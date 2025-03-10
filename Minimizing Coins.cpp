// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://cses.fi/problemset/task/1634
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

ll dp[N] , coins[N] , n , x;

ll calc(ll cur , int idx)
{
    if(cur == x)
        return 0;
    if(cur > x)
        return infLL;
    ll &ret = dp[cur];
    if(ret != infLL)
        return ret;
    for (ll i = idx; i < n; ++i) {
        ret = min(ret , calc(cur + coins[i] , i) + 1);
    }
    return ret;
}

void solve_rec() {
    memset(dp , infLL , sizeof dp);
    cin >> n >> x;
    for (ll i = 0; i < n; ++i) {
        cin >> coins[i];
    }
    sort(coins , coins + n , greater<ll>());
    calc(0 , 0);
    cout << (dp[0] == infLL ? -1 : dp[0]) << nl;
}

void solve_itr()
{
    memset(dp , infLL , sizeof dp);
    cin >> n >> x;
    for (ll i = 0; i < n; ++i) {
        cin >> coins[i];
    }
    dp[0] = 0;
    for (ll i = 0; i < n; ++i) {
        for (ll j = coins[i]; j <= x; ++j) {
            dp[j] = min(dp[j], dp[j - coins[i]] + 1);
        }
    }
    cout << (dp[x] == infLL ? -1 : dp[x]) << nl;
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
        solve_itr();
    }

    return 0;
}