// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/problemset/problem/2049/D
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
int n , m , k , vid = -1;
ll memo[201][201][201], vis[201][201][201], grid[201][201];

ll solve(int x , int y , int shift){
    if (x >= n or y >= m) return infLL;
    ll &res = memo[x][y][shift];
    if (vis[x][y][shift] == vid) return res;
    vis[x][y][shift] = vid;
    if (shift == m){
        res = infLL;
        for (int s = 0; s < m; ++s){
            res = min(res, 1ll * k * s + solve(x, y, s));
        }
        return res;
    }
    if (x == n - 1 && y == m - 1) return res = grid[x][(y + shift) % m];
    res = infLL;
    if (y + 1 < m){
        res = min(res, solve(x, y + 1, shift) + grid[x][(y + shift) % m]);
    }
    if (x + 1 < n){
        res = min(res, solve(x + 1, y, m) + grid[x][(y + shift) % m]);
    }
    return res;
}

void TC() {
    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
        }
    }
    cout << solve(0 , 0 , m) << nl;
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
    mem(vis , 1);
// ————————————————————————————————————————————
    ll tc = 1;
     cin >> tc;
    while (tc--)
    {
        TC();
        vid++;
    }

    return 0;
}