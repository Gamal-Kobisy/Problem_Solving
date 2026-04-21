// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/gym/102644/problem/B
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
    ll n;
    cin >> n;
    mat s = {{0 , 1}};
    mat t = {{20 , 6} , {7 , 19}};
    t = t ^ n;
    s = s * t;
    cout << s[0][1] << nl;
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