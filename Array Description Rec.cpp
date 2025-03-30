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

int n , m , a[N] , dp[101][N];

int calc(int prev , int idx) {
    if (idx == n)
        return 1;
    int &ret = dp[prev][idx];
    if (~ret)
        return ret;
    if (a[idx] != 0) {
        if (abs(a[idx] - prev) > 1)
            ret = 0;
        else
            ret = calc(a[idx] , idx + 1);
    }
    else {
        ret = 0;
        for (int i = max(prev - 1 , 1); i <= min(prev + 1, m); ++i) {
            ret = (ret + calc(i , idx + 1)) % MOD;

        }
    }
    return ret;
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    memset(dp , -1 , sizeof(dp));

    int ans = 0;
    if (a[0] != 0) {
        ans = calc(a[0], 1);
    } else {
        for (int j = 1; j <= m; ++j) {
            ans = (ans + calc(j, 1)) % MOD;
        }
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