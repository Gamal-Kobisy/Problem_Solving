// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/problemset/problem/1517/D
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
#define rv(a) return(void(a))
#define nl '\n'
#define sp ' '
#define ENG_GAMAL ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;
// ————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
const int N = 2e5 + 5, M = 1e3, LOG = 20, inf = 0x3f3f3f3f;
ll infLL = 0x3f3f3f3f3f3f3f3f;
int n, m , k, adjH[501][501], adjV[501][501];
ll memo[501][501][21];

ll solve(int x , int y , int rem){
    if(rem == 0)
        return 0;
    ll &res = memo[x][y][rem];
    if(res != infLL) return res;
    if(y > 1)
        res = min(res , solve(x , y - 1 , rem - 1) + adjH[x - 1][y - 2]);
    if(y < m)
        res = min(res , solve(x , y + 1 , rem - 1) + adjH[x - 1][y - 1]);
    if(x > 1)
        res = min(res , solve(x - 1 , y , rem - 1) + adjV[x - 2][y - 1]);
    if(x < n)
        res = min(res , solve(x + 1 , y , rem - 1) + adjV[x - 1][y - 1]);
    return res;
}

void TC() {
    cin >> n >> m >> k;
    if(k&1){
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cout << -1 << sp;
            }
            cout << nl;
        }
        return;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m - 1; ++j) {
            cin >> adjH[i][j];
        }
    }
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> adjV[i][j];
        }
    }
    mem(memo , infLL);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            ll ans = solve(i + 1 , j + 1 , k / 2);
            cout << ans * 2 << sp;
        }
        cout << nl;
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