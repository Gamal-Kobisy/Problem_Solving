// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://cses.fi/problemset/task/1746
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

int MOD = 1e9 + 7;

int n , m , a[N];


void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<int>prev(m + 1);
    for (int k = 1; k <= m; ++k) {
        if (a[0] == 0 || a[0] == k)
            prev[k] = 1;
    }

    for (int i = 2; i <= n; ++i) {
        vector<int>curr(m + 1);
        for (int j = 1; j <= m; ++j) {
            if (a[i - 1] != 0 && a[i - 1] != j)
                continue;
            for (int k = max(1 , j - 1); k <= min(m , j + 1); ++k) {
                curr[j] = (curr[j] + prev[k]) % MOD;
            }
        }
        prev = curr;
    }
    ll ans = 0;
    for (int i = 1; i <= m; ++i) {
        ans = (ans + prev[i]) % MOD;
    }
    cout << ans << nl;
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