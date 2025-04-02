// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://cses.fi/problemset/task/1745
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

int dp[N] , n , a[101];
bool vis[N];

void solve() {
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    memset(dp, 0, sizeof(dp));
    memset(vis, false, sizeof(vis));

    dp[0] = true;

    ll ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = N; j >= a[i - 1]; --j) {
            if (dp[j - a[i - 1]]) {
                ans += (dp[j] ? 0 : 1);
                dp[j] = true;
            }
        }
    }
    cout << ans << nl;
    for (int i = 1; i < N; ++i) {
        if (dp[i])
            cout << i << sp;
    }
}

void file() {
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
    //     cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
