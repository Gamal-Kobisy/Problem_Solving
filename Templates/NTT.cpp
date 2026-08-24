// ==============================================================================
// NTT (NUMBER THEORETIC TRANSFORM) + FORMAL POWER SERIES
// ==============================================================================
// NTT is the modular twin of FFT: it multiplies polynomials EXACTLY under a
// prime modulo (no floating-point precision limits), and unlocks formal power
// series: poly_inv, poly_ln, poly_exp, poly_sqrt, poly_pow, polynomial division.
// ==============================================================================

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#ifndef sz
#define sz(x) (int)(x.size())
#endif

// ==============================================================================
// CHANGEABLE PART #1 : MODULUS & PRIMITIVE ROOT
//   mod = 998244353   ->  G = 3
//   mod = 7340033     ->  G = 5
// ==============================================================================

const int mod = 998244353;
const int G = 3; // Primitive root of mod (3 for 998244353)

int add(int a, int b) { return (a + b >= mod ? a + b - mod : a + b); }
int mul(int a, int b) { return (1LL * a * b) % mod; }
int fast_pow(int base, int exp) {
    int res = 1;
    while (exp > 0) {
        if (exp % 2 == 1) res = mul(res, base);
        base = mul(base, base);
        exp /= 2;
    }
    return res;
}
int modInverse(int n) { return fast_pow(n, mod - 2); }

int generator(int p) {
    vector<int> fact;
    int phi = p - 1, n = phi;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            fact.push_back(i);
            while (n % i == 0) n /= i;
        }
    }
    if (n > 1) fact.push_back(n);
    for (int res = 2; res <= p; ++res) {
        bool ok = true;
        for (size_t i = 0; i < fact.size() && ok; ++i)
            ok &= fast_pow(res, phi / fact[i]) != 1;
        if (ok) return res;
    }
    return -1;
}

void ntt(vector<int>& a_arr, bool invert) {
    int sz_arr = a_arr.size();
    for (int i = 1, j = 0; i < sz_arr; i++) {
        int bit = sz_arr >> 1;
        for (; j & bit; bit >>= 1) j ^= bit;
        j ^= bit;
        if (i < j) swap(a_arr[i], a_arr[j]);
    }
    for (int len = 2; len <= sz_arr; len <<= 1) {
        int wlen = fast_pow(G, (mod - 1) / len);
        if (invert) wlen = modInverse(wlen);
        for (int i = 0; i < sz_arr; i += len) {
            int w = 1;
            for (int j = 0; j < len / 2; j++) {
                int u = a_arr[i + j];
                int v = mul(a_arr[i + j + len / 2], w);
                a_arr[i + j] = add(u, v);
                a_arr[i + j + len / 2] = add(u, mod - v);
                w = mul(w, wlen);
            }
        }
    }
    if (invert) {
        int inv_n = modInverse(sz_arr);
        for (int &x : a_arr) x = mul(x, inv_n);
    }
}

// ==============================================================================
// EXACT POLYNOMIAL MULTIPLICATION
// ==============================================================================
// WHAT IF I NEED TO ADD 'n' (Truncate to first n terms)?
// Do this:
// auto res = poly_mul(A, B);
// res.resize(n);
// (Optionally, if n is very small, do A.resize(n) and B.resize(n) BEFORE calling
// poly_mul to save execution time).
// ==============================================================================
vector<int> poly_mul(const vector<int>& p1, const vector<int>& p2) {
    if (p1.empty() || p2.empty()) return {};

    int exact_len = sz(p1) + sz(p2) - 1;
    vector<int> fa = p1, fb = p2;

    int sz_arr = 1;
    while (sz_arr < exact_len) sz_arr <<= 1;

    fa.resize(sz_arr, 0);
    fb.resize(sz_arr, 0);

    ntt(fa, false);
    ntt(fb, false);
    for (int i = 0; i < sz_arr; i++) fa[i] = mul(fa[i], fb[i]);
    ntt(fa, true);

    fa.resize(exact_len);
    while (fa.size() > 1 && fa.back() == 0) fa.pop_back();
    return fa;
}

// ==============================================================================
// EXACT POLYNOMIAL POWER
// ==============================================================================
// WHAT IF I NEED TO ADD 'n' (Truncate to first n terms)?
// Since power grows the array exponentially, exact calculation will CRASH for big P.
// To fix this for n terms:
// Inside the while loop below, right after poly_mul, add:
// if (res.size() > n) res.resize(n);
// if (base.size() > n) base.resize(n);
// ==============================================================================
vector<int> poly_pow(vector<int> base, long long power) {
    vector<int> res = {1};
    while (power) {
        if (power & 1) res = poly_mul(res, base);
        if (power > 1) base = poly_mul(base, base);
        power >>= 1;
    }
    return res;
}

vector<int> fact_arr, inv_arr;
void precompute_fact(int n) {
    fact_arr.assign(n + 1, 1);
    inv_arr.assign(n + 1, 1);
    for (int i = 1; i <= n; i++) fact_arr[i] = mul(fact_arr[i - 1], i);
    inv_arr[n] = modInverse(fact_arr[n]);
    for (int i = n - 1; i >= 0; i--) inv_arr[i] = mul(inv_arr[i + 1], i + 1);
}

// WHAT IF I NEED TO ADD 'n'?
// No changes needed here. A shift polynomial operation naturally preserves
// the degree of the polynomial.
vector<int> shift_polynomial(const vector<int>& poly, int c) {
    int n = poly.size() - 1;
    int norm_c = (c % mod + mod) % mod;
    vector<int> A(n + 1), B(n + 1);
    for (int i = 0; i <= n; i++) A[n - i] = mul(poly[i], fact_arr[i]);
    int cur_c = 1;
    for (int i = 0; i <= n; i++) {
        B[i] = mul(cur_c, inv_arr[i]);
        cur_c = mul(cur_c, norm_c);
    }
    vector<int> conv = poly_mul(A, B);
    vector<int> res(n + 1);
    for (int i = 0; i <= n; i++) res[i] = mul(conv[n - i], inv_arr[i]);
    return res;
}

// BLACK BOX #1 : poly_inv
// ==============================================================================
// WHAT IF I NEED TO ADD 'n' (Calculate inverse up to n terms)?
// Before calling this function, manually resize your array A to n:
// A.resize(n, 0);
// auto invA = poly_inv(A);
// The function automatically computes up to A.size() terms.
// ==============================================================================
vector<int> poly_inv(const vector<int>& A) {
    int n = A.size();
    if (n == 0) return {};
    vector<int> B = {modInverse(A[0])};
    while ((int)B.size() < n) {
        int k = 2 * B.size();
        vector<int> fA(A.begin(), A.begin() + min(k, sz(A)));
        vector<int> T = poly_mul(fA, B);
        T.resize(k);
        for (int i = 0; i < k; i++) T[i] = (T[i] ? mod - T[i] : 0);
        T[0] = add(T[0], 2);
        B = poly_mul(B, T);
        B.resize(k);
    }
    B.resize(n);
    return B;
}

// BLACK BOX #2 : poly_divmod
// ==============================================================================
// WHAT IF I NEED TO ADD 'n'?
// This function strictly calculates Exact Division and Remainder.
// The concept of 'n' (truncation) does not mathematically apply to exact divmod.
// ==============================================================================
pair<vector<int>, vector<int>> poly_divmod(const vector<int>& A, const vector<int>& B) {
    int n = A.size(), m = B.size();
    if (n < m) return {{0}, A};
    vector<int> A_rev = A, B_rev = B;
    reverse(A_rev.begin(), A_rev.end());
    reverse(B_rev.begin(), B_rev.end());

    B_rev.resize(n - m + 1, 0); // Prepare B_rev size to instruct poly_inv how far to go
    vector<int> Q_rev = poly_mul(A_rev, poly_inv(B_rev));
    Q_rev.resize(n - m + 1);

    vector<int> Q = Q_rev;
    reverse(Q.begin(), Q.end());
    vector<int> QB = poly_mul(Q, B);
    vector<int> R(m - 1);
    for (int i = 0; i < m - 1; i++) R[i] = add(A[i], mod - (i < sz(QB) ? QB[i] : 0));
    while (R.size() > 1 && R.back() == 0) R.pop_back();
    return {Q, R};
}

// BLACK BOX #3 : poly_ln
// ==============================================================================
// WHAT IF I NEED TO ADD 'n' (Calculate Ln up to n terms)?
// Before calling this function, manually resize your array A to n:
// A.resize(n, 0);
// auto lnA = poly_ln(A);
// The function uses A.size() to determine how far to compute.
// ==============================================================================
vector<int> poly_ln(const vector<int>& A) {
    int n = A.size();
    if (n == 0) return {};
    vector<int> invA = poly_inv(A);
    vector<int> dA(n - 1);
    for (int i = 1; i < sz(A) && i < n; i++) dA[i - 1] = mul(A[i], i);
    vector<int> prod = poly_mul(dA, invA);
    vector<int> res(n, 0);
    for (int i = 1; i < n; i++) res[i] = mul(prod[i - 1], modInverse(i));
    return res;
}

// BLACK BOX #4 : poly_exp
// ==============================================================================
// WHAT IF I NEED TO ADD 'n' (Calculate Exp up to n terms)?
// Before calling this function, manually resize your array A to n:
// A.resize(n, 0);
// auto expA = poly_exp(A);
// The function automatically computes up to A.size() terms.
// ==============================================================================
vector<int> poly_exp(const vector<int>& A) {
    int n = A.size();
    if (n == 0) return {1};
    vector<int> B = {1};
    while ((int)B.size() < n) {
        int k = 2 * B.size();
        vector<int> fB = B;
        fB.resize(k, 0);
        vector<int> lnB = poly_ln(fB);
        vector<int> T(k);
        T[0] = 1;
        for (int i = 0; i < k; i++) {
            int a = (i < sz(A) ? A[i] : 0);
            T[i] = add(T[i], add(a, mod - lnB[i]));
        }
        B = poly_mul(B, T);
        B.resize(k);
    }
    B.resize(n);
    return B;
}

int sqrt_mod(int a) {
    if (a == 0) return 0;
    if (mod == 2) return a;
    if (fast_pow(a, (mod - 1) / 2) != 1) return -1;
    if (mod % 4 == 3) return fast_pow(a, (mod + 1) / 4);
    int q = mod - 1, s = 0;
    while (q % 2 == 0) { q /= 2; s++; }
    int z = 2;
    while (fast_pow(z, (mod - 1) / 2) != mod - 1) z++;
    int c = fast_pow(z, q), x = fast_pow(a, (q + 1) / 2), t = fast_pow(a, q), m = s;
    while (t != 1) {
        int i = 0, tt = t;
        while (tt != 1) { tt = mul(tt, tt); i++; if (i == m) return -1; }
        int b = fast_pow(c, 1 << (m - i - 1));
        x = mul(x, b);
        c = mul(b, b);
        t = mul(t, c);
        m = i;
    }
    return x;
}

// BLACK BOX #5 : poly_sqrt
// ==============================================================================
// WHAT IF I NEED TO ADD 'n' (Calculate Sqrt up to n terms)?
// Before calling this function, manually resize your array A to n:
// A.resize(n, 0);
// auto sqrtA = poly_sqrt(A);
// The function automatically computes up to A.size() terms.
// ==============================================================================
vector<int> poly_sqrt(const vector<int>& A) {
    int n = A.size();
    if (n == 0) return {};
    int s0 = sqrt_mod(A[0]);
    if (s0 == -1) return {};
    vector<int> B = {s0};
    while ((int)B.size() < n) {
        int k = 2 * B.size();
        vector<int> fB = B;
        fB.resize(k, 0);
        vector<int> invB = poly_inv(fB);
        vector<int> fA(A.begin(), A.begin() + min(k, sz(A)));
        vector<int> T = poly_mul(fA, invB);
        T.resize(k);
        for (int i = 0; i < k; i++) {
            int b = (i < sz(B) ? B[i] : 0);
            T[i] = mul(add(b, T[i]), modInverse(2));
        }
        B = T;
        B.resize(k);
    }
    B.resize(n);
    return B;
}

// BLACK BOX #7 : count_pairs_sum
// ==============================================================================
// WHAT IF I NEED TO ADD 'n' (I only care about pair sums up to n)?
// Since the combinations array naturally caps at 2 * maxV, simply do:
// auto res = count_pairs_sum(A);
// res.resize(n + 1);
// at the end to drop sums larger than n.
// ==============================================================================
vector<int> count_pairs_sum(const vector<int>& A) {
    if (A.empty()) return {};
    int maxV = *max_element(A.begin(), A.end());
    vector<int> freq(2 * maxV + 1);
    for (int x : A) freq[x]++;
    vector<int> conv = poly_mul(freq, freq);
    vector<int> res(2 * maxV + 1);
    int inv2 = modInverse(2);
    for (int X = 0; X <= 2 * maxV; X++) {
        long long c = (X < sz(conv) ? conv[X] : 0);
        if (X % 2 == 0) c = (c - freq[X / 2] + mod) % mod;
        res[X] = c * inv2 % mod;
    }
    return res;
}

// BLACK BOX #8 : count_subset_sum
// ==============================================================================
// WHAT IF I NEED TO ADD 'n' (I only care about subset sums up to K)?
// 1. Change `int n = (int)total + 1;` to `int n = min((int)total + 1, K + 1);`
// 2. In the loop, after `res = poly_mul(res, ...);`, forcefully add: `res.resize(n);`
// This bounds the memory growth inside the loop.
// ==============================================================================
vector<int> count_subset_sum(const vector<int>& A) {
    if (A.empty()) return {1};
    long long total = 0;
    map<int, int> cnt;
    for (int x : A) { cnt[x]++; total += x; }

    int n = (int)total + 1; // max possible exact subset sum
    vector<int> res = {1};
    for (auto &p : cnt) {
        if (p.first == 0) continue;
        vector<int> base(p.first + 1, 0);
        base[0] = 1; base[p.first] = 1;
        res = poly_mul(res, poly_pow(base, p.second));
        // IF YOU WANT TO LIMIT BY n: res.resize(n);
    }
    res.resize(n);
    if (cnt.count(0)) {
        int mult = fast_pow(2, cnt[0]);
        for (int &x : res) x = mul(x, mult);
    }
    return res;
}

// BLACK BOX #9 : count_arithmetic_progressions
// ==============================================================================
// WHAT IF I NEED TO ADD 'n' (Limit maximum element considered)?
// Truncation doesn't apply directly here. If you want to limit it, you
// should filter the input array `A` to remove elements > n before calling.
// ==============================================================================
vector<int> count_arithmetic_progressions(const vector<int>& A) {
    if (A.size() < 3) return {};
    int maxV = *max_element(A.begin(), A.end());
    vector<int> cnt(maxV + 1);
    for (int x : A) cnt[x]++;
    vector<int> conv = poly_mul(cnt, cnt);
    int inv2 = modInverse(2), inv6 = modInverse(6);
    vector<int> res(maxV + 1);
    for (int b = 0; b <= maxV; b++) {
        if (!cnt[b]) continue;
        int v = 2 * b;
        long long c = (v < sz(conv) ? conv[v] : 0);
        c = (c - 1LL * cnt[b] * cnt[b] % mod + mod) % mod;
        res[b] = c * inv2 % mod * cnt[b] % mod;
        long long choose3 = 1LL * cnt[b] * (cnt[b] - 1) % mod * (cnt[b] - 2) % mod;
        res[b] = (res[b] + choose3 * inv6) % mod;
    }
    return res;
}