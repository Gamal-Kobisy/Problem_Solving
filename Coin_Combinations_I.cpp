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
const int N = 1e2 + 5, M = 1e6 + 5, LOG = 20, inf = 0x3f3f3f3f;
ll infLL = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9 + 7;
ll n , x , a[N] , dp[M];

ll calc(ll sum)
{
    if(sum > x)
        return 0;
    if(sum == x)
        return 1;

    ll &ret = dp[sum];
    if(~ret)
        return ret;
    ret = 0;
    for (ll j = 0; j < n; ++j) {
        ret = (ret + calc((sum + a[j]))) % MOD;
    }
    return ret;
}

void solve() {
    memset(dp , -1 , sizeof dp);
    cin >> n >> x;
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }
    cout << calc(0) << nl;
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