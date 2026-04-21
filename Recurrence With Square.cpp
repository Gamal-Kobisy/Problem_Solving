// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/gym/102644/problem/G
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

const int mod = 1e9 + 7;
typedef vector<ll> row;
typedef vector<row> mat;

mat operator*(const mat &a, const mat &b) {
    int r1 = a.size(), r2 = b.size(), c2 = b[0].size();
    mat ret(r1, row(c2));
    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c2; j++)
            for (int k = 0; k < r2; k++)
                ret[i][j] += a[i][k] * b[k][j], ret[i][j] %= mod;
    return ret;
}

mat operator^(const mat &a, ll k) {
    mat ret(a.size(), row(a.size()));
    for (int i = 0; i < a.size(); i++)ret[i][i] = 1;
    for (mat tmp = a; k; tmp = tmp * tmp, k /= 2)if (k & 1)ret = ret * tmp;
    return ret;
}

void TC() {
    ll n, k, p, q, r;
    cin >> n >> k;

    vector<ll> a(n), c(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> c[i];
    cin >> p >> q >> r;
    if (k < n) {
        cout << a[k] % mod << nl;
        return;
    }

    mat s(1, row(n + 3, 0));
    for (int i = 0; i < n; ++i) {
        s[0][i] = a[n - 1 - i];
    }
    s[0][n] = (n - 1);
    s[0][n + 1] = ((n - 1) * (n - 1)) % mod;
    s[0][n + 2] = 1;

    mat t(n + 3, row(n + 3, 0));

    for (int j = 0; j < n; ++j) {
        t[j][0] = c[j];
    }
    for (int i = 1; i < n; ++i) {
        t[i - 1][i] = 1;
    }

    t[n][n + 1] = 2;
    t[n][n] = 1;
    t[n + 2][n] = 1;

    t[n + 1][n + 1] = 1;
    t[n + 2][n + 1] = 1;

    t[n + 2][n + 2] = 1;

    t[n][0] = (q + 2 * r) % mod;
    t[n + 1][0] = r % mod;
    t[n + 2][0] = (p + q + r) % mod;

    t = t ^ (k - (n - 1));
    s = s * t;

    cout << s[0][0] % mod << nl;
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