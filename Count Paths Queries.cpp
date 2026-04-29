// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/gym/102644/problem/I
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
const int N = 2e5 + 5, LOG = 30, inf = 0x3f3f3f3f;
ll infLL = 0x3f3f3f3f3f3f3f3f;
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
const int mod = 1e9 + 7;
const int sz = 200;
typedef array<ll, sz> row;
typedef array<row, sz> mat;
const int S = 32;

mat operator*(const mat &a, const mat &b) {
    mat ret{};

    // The outer loops iterate over the "blocks" or "tiles"
    for (int ih = 0; ih < sz; ih += S) {
        for (int kh = 0; kh < sz; kh += S) {
            for (int jh = 0; jh < sz; jh += S) {

                // The inner loops multiply the elements within the current block
                for (int il = ih; il < min(ih + S, sz); ++il) {
                    for (int kl = kh; kl < min(kh + S, sz); ++kl) {

                        if (a[il][kl] == 0) continue; // Zero-skip optimization

                        // Because of the pragmas at the top, the compiler will
                        // automatically vectorize this innermost loop using AVX!
                        for (int jl = jh; jl < min(jh + S, sz); ++jl) {
                            ret[il][jl] = (ret[il][jl] + a[il][kl] * b[kl][jl]) % mod;
                        }
                    }
                }

            }
        }
    }
    return ret;
}

row operator*(const row &a, const mat &b) {
    row ret{};
    // Tiling isn't needed here since a 1D array easily fits in L1 cache
    for (int k = 0; k < sz; k++) {
        if (a[k] == 0) continue;
        for (int j = 0; j < sz; j++) {
            ret[j] = (ret[j] + a[k] * b[k][j]) % mod;
        }
    }
    return ret;
}

mat operator^(mat a, ll k) {
    mat ret{};
    for (int i = 0; i < sz; i++) ret[i][i] = 1;
    while (k) {
        if (k & 1) ret = ret * a;
        a = a * a;
        k >>= 1;
    }
    return ret;
}
void TC() {
    int n , m , q;
    cin >> n >> m >> q;
    mat t{};
    for (int i = 0; i < m; ++i) {
        int a , b;
        cin >> a >> b;
        t[--a][--b] = 1;
    }
    vector<mat>pre(LOG);
    pre[0] = t;
    for (int i = 1; i < LOG; ++i) {
        pre[i] = pre[i - 1] ^ 2;
    }
    while(q--){
        int a , b , k;
        cin >> a >> b >> k;
        row s{};
        s[--a] = 1;
        for (int i = 0; i < LOG; ++i) {
            if((1 << i) & k){
                s = s * pre[i];
            }
        }
        cout << s[--b] << nl;
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