// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://cses.fi/problemset/task/1744
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
const int N = 2e5 + 5, M = 1e3, LOG = 20, inf = 0x3f3f3f3f;
ll infLL = 0x3f3f3f3f3f3f3f3f;

int a , b , dp[505][505];

void solve() {
    cin >> a >> b;
    memset(dp , inf , sizeof(dp));

    for (int i = 0; i < 501; ++i) {
        dp[i][i] = 0;
    }
    for (int x = 1; x <= a; ++x) {
        for (int y = 1; y <= b; ++y) {
            int mini = inf;
            for (int i = 1; i < y; i++) {
                mini = min(mini, dp[x][y - i] + dp[x][i]);
            }
            for (int i = 1; i < x; i++) {
                mini = min(mini , dp[i][y] + dp[x - i][y]);
            }
            dp[x][y] = min(mini + 1, dp[x][y]);
        }
    }
    cout << dp[a][b] << nl;
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
