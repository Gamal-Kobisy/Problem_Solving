// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/contest/1096/problem/G
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
const int G = 3;
const int mod = 998244353;
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

int generator(int p) {
    vector<int> fact;
    int phi = p-1, n = phi;
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
vector<int> poly_mul(const vector<int>& p1, const vector<int>& p2) {
    vector<int> fa = p1, fb = p2;
    int sz_arr = 1;
    while (sz_arr < fa.size() + fb.size()) sz_arr <<= 1;
    fa.resize(sz_arr, 0);
    fb.resize(sz_arr, 0);

    ntt(fa, false);
    ntt(fb, false);

    for (int i = 0; i < sz_arr; i++) fa[i] = mul(fa[i], fb[i]);
    ntt(fa, true);

    while (fa.size() > 1 && fa.back() == 0) fa.pop_back();
    return fa;
}
vector<int> poly_pow(vector<int> base, ll power) {
    vector<int> res = {1};
    while (power) {
        if (power & 1) res = poly_mul(res, base);
        if (power > 1) base = poly_mul(base, base);
        power >>= 1;
    }
    return res;
}


void TC()
{
    ll n , k;
    cin >> n >> k;
    vector<int> A(10);
    for (int i = 0; i < k; i++)
    {
        int d;cin >> d;
        A[d] = 1;
    }
    auto res = poly_pow(A, n / 2);
    ll ans = 0;
    for (int i = 0; i < res.size(); i++)
    {
        // if (res[i]) cout << i << sp << res[i] << nl;
        ans = add(ans , mul(res[i] , res[i]));
    }
    cout << ans << endl;
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
