// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK :
#include <bits/stdc++.h>
#define ll long long
#define nl '\n'
#define all(a) a.begin(),a.end()
#define allr(a) a.rbegin(),a.rend()
#define no cout<<"NO\n"
#define yes cout<<"YES\n"
#define ENG_GAMAL ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;
// ————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
const int N = 1e3 + 5, M = 1e3, LOG = 20, inf = 0x3f3f3f3f;
const ll MOD = 1e9 + 7;

ll add(ll a  , ll b)
{
    return ((a % MOD) + (b % MOD)) % MOD;
}

ll sub(ll a , ll b)
{
    return ((a % MOD) - (b % MOD) + MOD) % MOD;
}

ll mul(ll a , ll b)
{
    return ((a % MOD) * (b % MOD)) % MOD;
}
ll infLL = 0x3f3f3f3f3f3f3f3f;
int n;
string grid[N];
int dp[N][N];

void solve() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
    }
    for (ll i = n - 1; i >= 0 ; --i) {
        for (ll j = n - 1; j >= 0; --j) {
            int &ret = dp[i][j];
            if(grid[i][j] != '.')
            {
                ret = 0;
                continue;
            }
            if(i == n - 1 && j == n - 1){
                ret = 1;
                continue;
            }
            ret = 0;
            if(i + 1 < n && grid[i][j] == '.')
                ret = add(ret , dp[i + 1][j]);
            if(j + 1 < n && grid[i][j] == '.')
                ret = add(ret , dp[i][j + 1]);
        }
    }
    cout << dp[0][0] << nl;
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
    ll t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}