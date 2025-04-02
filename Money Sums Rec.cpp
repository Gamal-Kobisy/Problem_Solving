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

int dp[101][N] , n , a[101];
bool vis[N];

int calc(int idx , int sum) {
    if(idx == n) {
        if (vis[sum] || sum == 0)
            return 0;
        vis[sum] = true;
        return 1;
    }

    int &ret = dp[idx][sum];
    if (~ret)
        return 0;
    ret = 0;
    ret += calc(idx+1, sum);
    ret += calc(idx+1, sum + a[idx]);

    return ret;
}

void solve() {
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    memset(dp, -1, sizeof(dp));
    memset(vis, false, sizeof(vis));
    cout << calc(0, 0) << nl;
    for (int i = 1; i < N; ++i) {
        if (vis[i])
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
