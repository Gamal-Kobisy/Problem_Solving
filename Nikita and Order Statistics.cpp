// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/contest/993/problem/E
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
vector<ll> multiply(vector<int> const& a, vector<int> const& b)
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
    for (int i = 0; i < n; i++) result[i] = llround(fa[i].real());
    return result;
}

vector<ll> get_pairwise_differences(const vector<int>& A, const vector<int>& B) {
    if (A.empty() || B.empty()) return {};

    // Find maximum values to determine the size of the frequency arrays
    int max_A = 0, max_B = 0;
    for (int x : A) max_A = max(max_A, x);
    for (int x : B) max_B = max(max_B, x);

    // Create frequency arrays
    vector<int> freq_A(max_A + 1, 0);
    for (int x : A) freq_A[x]++;

    vector<int> freq_B(max_B + 1, 0);
    for (int x : B) freq_B[x]++;

    // Reverse the second frequency array to calculate differences
    vector<int> rev_freq_B(max_B + 1, 0);
    for (int i = 0; i <= max_B; i++) {
        rev_freq_B[max_B - i] = freq_B[i];
    }

    // Multiply A and the reversed B
    vector<ll> res = multiply(freq_A, rev_freq_B);

    // The result for difference X (where X = A[i] - B[j]) is stored at index (X + max_B)
    return res;
}


void TC() {
    int n , x;
    cin >> n >> x;
    vector<int>a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<int>pre(n + 1);
    for (int i = 1; i <= n; i++) pre[i] = a[i - 1] < x ? 1 : 0;
    for (int i = 1; i <= n; i++) pre[i] += pre[i - 1];
    auto res = get_pairwise_differences(pre, pre);
    int M = *max_element(all(pre));
    vector<ll> ans(n + 1, 0);
    ans[0] = (res[M] - (n + 1)) / 2;
    for (int k = 1; k <= n; k++)
        if (k <= M) ans[k] = res[M - k];
    for (int k = 0; k <= n; k++)
        cout << ans[k] << sp;
    cout << endl;
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
