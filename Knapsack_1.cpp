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
const int N = 1e2 + 5, M = 1e5 + 5, LOG = 20, inf = 0x3f3f3f3f;
ll infLL = 0x3f3f3f3f3f3f3f3f;
int n;
ll w[N] , val[N] , dp[N][M];

ll calc(int i , ll remC)
{

}

void solve() {
    ll c;
    cin >> n >> c;
    for (ll i = 0; i < n; ++i) {
        cin >> w[i] >> val[i];
    }
    for (ll i = n;i >= 0; --i) {
        for (ll remC = 0; remC <= c; ++remC) {
            ll &ret = dp[i][remC];
            if(i == n)
            {
                ret = 0;
                continue;
            }
            ret = dp[i + 1][remC];
            if(remC >= w[i])
                ret = max(ret , dp[i + 1][remC - w[i]] + val[i]);
        }
    }
    cout << dp[0][c] << nl;
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