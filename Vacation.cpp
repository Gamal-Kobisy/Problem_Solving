// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://atcoder.jp/contests/dp/tasks/dp_c?lang=en
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
const int N = 1e5 + 5, M = 1e3, LOG = 20, inf = 0x3f3f3f3f;
ll infLL = 0x3f3f3f3f3f3f3f3f;

ll n , act[3][N] , dp[3][N];

ll calc(int c , int idx)
{
    if(idx > n)
        return 0;
    ll &ret = dp[c][idx];
    if(ret)
        return ret;
    for (ll i = 0; i < 3; ++i) {
        if(i != c)
            ret = max(ret , calc(i , idx + 1) + act[i][idx]);
    }
    return ret;
}


void solve() {
    memset(dp , 0 , sizeof dp);
    cin >> n;
    for (ll i = 1; i <= n; ++i) {
        for (ll j = 0; j < 3; ++j) {
            cin >> act[j][i];
        }
    }
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