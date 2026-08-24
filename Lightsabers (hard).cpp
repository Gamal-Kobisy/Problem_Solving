// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/contest/958/problem/F3
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
// 2. STANDARD FFT & APPLICATIONS (Complex Double - Updated to Long Long)
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
vector<ll> multiply(vector<ll> const& a, vector<ll> const& b)
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

    vector<ll> result(n);
    for (int i = 0; i < n; i++) result[i] = round(fa[i].real());
    return result;
}

/*
 * HOW TO USE: poly_pow(poly, p)
 * WHEN TO USE: Raising a polynomial to the power of 'p'.
 * COMPLEXITY: O(N log N * log P)
 */
vector<ll> poly_pow(vector<ll> poly, int p)
{
    vector<ll> result = {1};
    while (p > 0)
    {
        if (p & 1) result = multiply(result, poly);
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
    vector<ll> a(s1.size()), b(s2.size());
    for (int i = 0; i < s1.size(); i++) a[i] = s1[s1.size() - 1 - i] - '0';
    for (int i = 0; i < s2.size(); i++) b[i] = s2[s2.size() - 1 - i] - '0';

    vector<ll> res = multiply(a, b);
    ll carry = 0;
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
vector<ll> count_distinct_triplets_sum(const vector<ll>& A)
{
    if (A.empty()) return {};
    ll max_val = 0;
    for (ll x : A) max_val = max(max_val, x);
    int size = 1;
    while (size <= 3 * max_val) size <<= 1;

    vector<ll> p1(size, 0), p2(size, 0), p3(size, 0);
    for (ll x : A)
    {
        p1[x]++;
        if (2 * x < size) p2[2 * x]++;
        if (3 * x < size) p3[3 * x]++;
    }

    vector<ll> p1_sq = multiply(p1, p1);
    vector<ll> p_cube = multiply(p1_sq, p1);
    vector<ll> p1_p2 = multiply(p1, p2);

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

/*
 * HOW TO USE: get_hamming_distances(Text_array, Pattern_array)
 * WHEN TO USE: String matching allowing mismatches. Returns an array where ans[i] is the number of mismatches if Pattern is placed at index i of Text.
 * COMPLEXITY: O(|Sigma| * N log N) where Sigma is the unique characters in Pattern.
 */
vector<int> get_hamming_distances(const vector<int>& T, const vector<int>& P)
{
    int n = T.size(), m = P.size();
    if (n < m) return {};
    vector<int> unique_chars = P;
    sort(unique_chars.begin(), unique_chars.end());
    unique_chars.erase(unique(unique_chars.begin(), unique_chars.end()), unique_chars.end());

    vector<int> total_matches(n - m + 1, 0);
    for (int c : unique_chars)
    {
        vector<ll> t_bin(n), p_bin(m);
        for (int i = 0; i < n; i++) t_bin[i] = (T[i] == c ? 1 : 0);
        for (int i = 0; i < m; i++) p_bin[i] = (P[i] == c ? 1 : 0);

        reverse(p_bin.begin(), p_bin.end());
        vector<ll> matches_c = multiply(t_bin, p_bin);

        for (int i = 0; i <= n - m; i++) total_matches[i] += matches_c[i + m - 1];
    }

    vector<int> ham(n - m + 1);
    for (int i = 0; i <= n - m; i++) ham[i] = m - total_matches[i];
    return ham;
}

/*
 * HOW TO USE: wildcard_string_matching(Text, Pattern)
 * WHEN TO USE: Finding all starting indices where Pattern matches Text, allowing '?'
 *              as a wildcard character that can match any letter ('a'-'z').
 * COMPLEXITY: O(N log N) where N is the length of the Text.
 */
vector<int> wildcard_string_matching(string T, string P)
{
    int n = T.size(), m = P.size();
    if (n < m) return {};

    vector<ll> t1(n), t2(n), t3(n);
    for (int i = 0; i < n; i++)
    {
        ll val = (T[i] == '?' ? 0 : T[i] - 'a' + 1);
        t1[i] = val;
        t2[i] = val * val;
        t3[i] = val * val * val;
    }

    vector<ll> p1(m), p2(m), p3(m);
    for (int i = 0; i < m; i++)
    {
        ll val = (P[i] == '?' ? 0 : P[i] - 'a' + 1);
        p1[m - 1 - i] = val;
        p2[m - 1 - i] = val * val;
        p3[m - 1 - i] = val * val * val;
    }

    vector<ll> res1 = multiply(t3, p1);
    vector<ll> res2 = multiply(t2, p2);
    vector<ll> res3 = multiply(t1, p3);

    vector<int> match_indices;
    for (int i = m - 1; i < n; i++)
    {
        ll sum = res1[i] - 2LL * res2[i] + res3[i];
        if (sum == 0)
        {
            match_indices.push_back(i - m + 1);
        }
    }

    return match_indices;
}

vector<ll> get_pairwise_differences(const vector<ll>& A, const vector<ll>& B) {
    if (A.empty() || B.empty()) return {};

    // Find maximum values to determine the size of the frequency arrays
    int max_A = 0, max_B = 0;
    for (int x : A) max_A = max(max_A, x);
    for (int x : B) max_B = max(max_B, x);

    // Create frequency arrays
    vector<ll> freq_A(max_A + 1, 0);
    for (int x : A) freq_A[x]++;

    vector<ll> freq_B(max_B + 1, 0);
    for (int x : B) freq_B[x]++;

    // Reverse the second frequency array to calculate differences
    vector<ll> rev_freq_B(max_B + 1, 0);
    for (int i = 0; i <= max_B; i++) {
        rev_freq_B[max_B - i] = freq_B[i];
    }

    // Multiply A and the reversed B
    vector<ll> res = multiply(freq_A, rev_freq_B);

    // The result for difference X (where X = A[i] - B[j]) is stored at index (X + max_B)
    return res;
}
/*
 * HOW TO USE: count_subset_sums(A)
 * WHEN TO USE: Finding the exact number of subsets that sum to X, for all possible sums.
 * COMPLEXITY: O(S log S log N), where S is the total sum of all elements in A.
 */
vector<ll> count_subset_sums_helper(int l, int r, const vector<vector<ll>>& polys)
{
    if (l == r) return polys[l];
    int mid = l + (r - l) / 2;
    vector<ll> left_poly = count_subset_sums_helper(l, mid, polys);
    vector<ll> right_poly = count_subset_sums_helper(mid + 1, r, polys);
    return multiply(left_poly, right_poly);
}

vector<ll> count_subset_sums(const vector<int>& A)
{
    if (A.empty()) return {1};

    // Convert each element x into a polynomial (1 + z^x)
    vector<vector<ll>> polys(A.size());
    for (int i = 0; i < A.size(); i++)
    {
        polys[i].assign(A[i] + 1, 0);
        polys[i][0] = 1;      // exclude A[i] (sum contributes 0)
        polys[i][A[i]] = 1;   // include A[i] (sum contributes A[i])
    }

    // Multiply them all using divide and conquer
    return count_subset_sums_helper(0, polys.size() - 1, polys);
}
/*
 * EXAMPLE:
 *   A = {1, 2, 2}
 *   count_subset_sums(A)
 *     -> Polynomials: (1 + x^1) * (1 + x^2) * (1 + x^2)
 *     -> Result: {1, 1, 2, 2, 1, 1}
 *   Result[2] == 2, meaning 2 distinct subsets sum to 2: {2} and {2}.
 *   Result[5] == 1, meaning 1 subset sums to 5: {1, 2, 2}.
 *
 * EXPLANATION: Multiplying all (1 + z^x) binomials gives a polynomial where
 *   the coefficient of z^S is the number of subsets summing to S. A divide-and-conquer
 *   approach keeps polynomial sizes balanced, keeping it much faster than sequential multiplication.
 *
 * CAUTION: Because your FFT uses complex<double>, coefficients > 10^15
 *   will suffer from floating-point precision loss. If you expect a massive
 *   number of ways, you need a Number Theoretic Transform (NTT) instead of standard FFT.
 */
void TC() {
    int n , m , k;
    cin >> n >> m >> k;
    vector<int>freq(m + 1);
    vector<int>a(n);
    for (int i = 0; i < n; i++) cin >> a[i] , freq[a[i]]++;
    priority_queue<pair<int,int> , vector<pii> , greater<>>pq;
    vector<vector<ll>>polys;
    for (int i = 1; i <= m; i++)
    {
        if (freq[i] == 0) continue;
        polys.pb(vector<ll>(freq[i] + 1, 1));
        pq.push({freq[i], polys.size() - 1});
    }

    while (pq.size() > 1) {
        auto [c1, idx1] = pq.top();
        pq.pop();
        auto [c2, idx2] = pq.top();
        pq.pop();

        auto res = multiply(polys[idx1], polys[idx2]);
        if (res.size() > k + 1) res.resize(k + 1);
        for (ll &x : res) x %= 1009;
        polys[idx1] = res;
        pq.push({res.size(), idx1});
    }

    int final_id = pq.top().second;
    if (k < polys[final_id].size()) {
        cout << polys[final_id][k] << nl;
    } else {
        cout << 0 << nl;
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
