// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// TIME LIMIT EXCEEDED

// LINK : https://cses.fi/problemset/task/1636
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

const int N = 1e6 + 5, M = 1e3, LOG = 20, inf = 0x3f3f3f3f;
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

int dp[101][N] , coins[100] , n , x;

ll calc(ll i , ll sum)
{
    if(i == n || sum > x)
        return 0;
    if(sum == x)
        return 1;
    int &ret = dp[i][sum];
    if(~ret)
        return ret;
    ret = 0;
    for (ll j = i; j < n; ++j) {
        ret = add(ret , calc(j , sum + coins[j]));
    }
    return ret;
}

void solve() {
    cin >> n >> x;
    for (ll i = 0; i < n; ++i) {
        cin >> coins[i];
    }
    memset(dp , -1 , sizeof dp);
    cout << calc(0 , 0) << nl;

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