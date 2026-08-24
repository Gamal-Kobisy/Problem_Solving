// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://vjudge.net/problem/SPOJ-TSUM
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define PI acos(-1)
#define Ones(n) __builtin_popcountll(n)
#define MSB(n) (63 - __builtin_clzll(n))
#define LSB(n) (__builtin_ctzll(n))
#define mem(arrr, xx) memset(arrr,xx,sizeof arrr)
#define fr first
#define sc second
#define pb push_back
#define all(a) a.begin(),a.end()
#define allr(a) a.rbegin(),a.rend()
#define no cout<<"NO\n"
#define yes cout<<"YES\n"
#define imp cout<<"IMPOSSIBLE\n"
#define nl '\n'
#define sp ' '
#define ENG_GAMAL ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;
// ————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
const int N = 2e5 + 5, M = 1e3, LOG = 20, inf = 0x3f3f3f3f;
ll infLL = 0x3f3f3f3f3f3f3f3f;

// ==============================================================================
// 1. MODULAR ARITHMETIC HELPERS
// ==============================================================================
const int mod = 1e9 + 7;
/*
 * HOW TO USE: fast_pow(base, exponent)
 * WHEN TO USE: Calculating (base^exponent) % mod.
 * COMPLEXITY: O(log b)
 */
ll fast_pow(ll a, ll b)
{
    ll ans = 1;
    while (b)
    {
        if (b & 1) ans = (ans * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return ans;
}

/*
 * HOW TO USE: modInverse(n)
 * WHEN TO USE: When you need to divide by 'n' under a prime modulo (Fermat's Little Theorem).
 * COMPLEXITY: O(log mod)
 */
int modInverse(int n)
{
    return fast_pow(n, mod - 2);
}

int add(int a, int b)
{
    int ret = a + b;
    if (ret >= mod) ret -= mod;
    if (ret < 0) ret += mod;
    return ret;
}

int mul(int a, int b)
{
    return 1ll * a * b % mod;
}

// ==============================================================================
// 2. STANDARD FFT & APPLICATIONS (Complex Double)
// ==============================================================================

using cd = complex<double>;
/*
 * HOW TO USE: fft(array, invert_flag)
 * WHEN TO USE: Base function for standard convolution over complex numbers (No modulo).
 * COMPLEXITY: O(N log N)
 */
void fft(vector<cd>& a, bool invert)
{
    int n = a.size();
    for (int i = 1, j = 0; i < n; i++)
    {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1) j ^= bit;
        j ^= bit;
        if (i < j) swap(a[i], a[j]);
    }
    for (int len = 2; len <= n; len <<= 1)
    {
        double ang = 2 * PI / len * (invert ? -1 : 1);
        cd wlen(cos(ang), sin(ang));
        for (int i = 0; i < n; i += len)
        {
            cd w(1);
            for (int j = 0; j < len / 2; j++)
            {
                cd u = a[i + j], v = a[i + j + len / 2] * w;
                a[i + j] = u + v;
                a[i + j + len / 2] = u - v;
                w *= wlen;
            }
        }
    }
    if (invert)
    {
        for (cd& x : a) x /= n;
    }
}

/*
 * HOW TO USE: multiply(polyA, polyB)
 * WHEN TO USE: Multiplying two polynomials where exact values don't exceed floating-point precision (~10^15). No modulo applied.
 * COMPLEXITY: O(N log N)
 */
vector<int> multiply(vector<int> const& a, vector<int> const& b)
{
    vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int n = 1;
    while (n < a.size() + b.size()) n <<= 1;
    fa.resize(n);
    fb.resize(n);
    fft(fa, false);
    fft(fb, false);
    for (int i = 0; i < n; i++) fa[i] *= fb[i];
    fft(fa, true);
    vector<int> result(n);
    for (int i = 0; i < n; i++) result[i] = round(fa[i].real());
    return result;
}

/*
 * HOW TO USE: poly_pow(poly, p)
 * WHEN TO USE: Raising a polynomial to the power of 'p' (e.g., multiplying it by itself p times).
 * COMPLEXITY: O(N log N * log P)
 */
vector<int> poly_pow(vector<int> poly, int p)
{
    // Base polynomial representing '1' (x^0 = 1)
    vector<int> result = {1};

    while (p > 0)
    {
        if (p & 1)
        {
            result = multiply(result, poly);
        }
        poly = multiply(poly, poly);
        p >>= 1;
    }
    return result;
}

/*
 * HOW TO USE: big_multiply("123456...", "987654...")
 * WHEN TO USE: Multiplying two extremely large numbers represented as strings.
 * COMPLEXITY: O(N log N)
 */
string big_multiply(string s1, string s2)
{
    if (s1 == "0" || s2 == "0") return "0";
    vector<int> a(s1.size()), b(s2.size());
    for (int i = 0; i < s1.size(); i++) a[i] = s1[s1.size() - 1 - i] - '0';
    for (int i = 0; i < s2.size(); i++) b[i] = s2[s2.size() - 1 - i] - '0';
    vector<int> res_int = multiply(a, b);
    vector<ll> res(res_int.begin(), res_int.end());
    int carry = 0;
    for (int i = 0; i < res.size(); i++)
    {
        res[i] += carry;
        carry = res[i] / 10;
        res[i] %= 10;
    }
    while (carry)
    {
        res.push_back(carry % 10);
        carry /= 10;
    }
    while (res.size() > 1 && res.back() == 0) res.pop_back();
    string ans = "";
    for (int i = res.size() - 1; i >= 0; i--) ans += to_string(res[i]);
    return ans;
}

/*
 * HOW TO USE: count_distinct_triplets_sum(array_of_integers)
 * WHEN TO USE: Finding the number of ways to pick 3 distinct elements from an array that sum to exactly X.
 * COMPLEXITY: O(MAX_VAL * log(MAX_VAL))
 */
vector<ll> count_distinct_triplets_sum(const vector<int>& A)
{
    if (A.empty()) return {};
    int max_val = 0;
    for (int x : A) max_val = max(max_val, x);
    int size = 1;
    while (size <= 3 * max_val) size <<= 1;

    vector<int> p1(size, 0), p2(size, 0), p3(size, 0);
    for (int x : A)
    {
        p1[x]++;
        if (2 * x < size) p2[2 * x]++;
        if (3 * x < size) p3[3 * x]++;
    }

    vector<int> p1_sq_int = multiply(p1, p1);
    vector<int> p_cube = multiply(p1_sq_int, p1);
    vector<int> p1_p2 = multiply(p1, p2);

    vector<ll> res(size);
    for (int i = 0; i < size; i++)
    {
        ll term1 = p_cube[i];
        ll term2 = 3 * (i < p1_p2.size() ? p1_p2[i] : 0);
        ll term3 = 2 * p3[i];
        res[i] = (term1 - term2 + term3) / 6;
    }
    return res;
}
void TC() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int mn = *min_element(all(a));
    int add = mn < 0 ? abs(mn) : 0;

    vector<int> shifted(n);
    for (int i = 0; i < n; i++) shifted[i] = a[i] + add;

    auto res = count_distinct_triplets_sum(shifted);
    for (int i = 0; i < (int)res.size(); i++)
    {
        if (res[i] == 0) continue;
        cout << i - 3 * add << " : " << res[i] << nl;
    }
}
void file()
{
#ifndef ONLINE_JUDGE
    freopen("Input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
    freopen("Error.txt", "w", stderr);
#endif
}

int main() {
    file();
    ENG_GAMAL
    // test-independent code ——————————————————————
    // ————————————————————————————————————————————
    ll tc = 1;
    //     cin >> tc;
    while (tc--)
    {
        TC();
    }

    return 0;
}
