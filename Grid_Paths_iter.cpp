// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://cses.fi/problemset/task/1638
#include <bits/stdc++.h>
#define ll long long
#define nl '\n'
#define sp ' '
#define all(a) a.begin(),a.end()
#define allr(a) a.rbegin(),a.rend()
#define no cout<<"NO\n"
#define yes cout<<"YES\n"
#define ENG_GAMAL ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;
// ————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
const int N = 1e3 + 5, M = 1e3, LOG = 20, inf = 0x3f3f3f3f;
ll infLL = 0x3f3f3f3f3f3f3f3f;

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

ll power(ll b, ll p) {
    ll ans = 1;
    while (p) {
        if (p & 1)
            ans = mul(ans, b);
        b = mul(b, b);
        p /= 2;
    }
    return ans;
}

string grid[N];
ll n;

ll dp[N][N];

void solve()
{
    memset(dp , 0 , sizeof(dp));
    cin >> n;
    for (ll i = 0; i < n; ++i) {
        cin >> grid[i];
    }
    if(grid[0][0] == '*' || grid[n - 1][n - 1] == '*')
        return void(cout << 0 << nl);
    dp[0][0] = 1;
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < n; ++j) {
            if(i + 1 < n && grid[i + 1][j] == '.')
                dp[i + 1][j] = add(dp[i][j] ,dp[i + 1][j]);
            if(j + 1 < n && grid[i][j + 1] == '.')
                dp[i][j + 1] = add(dp[i][j] ,dp[i][j + 1]);
        }
    }
    cout << dp[n - 1][n - 1] << nl;
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