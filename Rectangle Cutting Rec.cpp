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

int calc(int x , int y) {
    if (x == y)
        return 0;
    if (min(x , y) == 1)
        return max(x , y) - 1;
    int &ret = dp[x][y];
    if (~ret)
        return ret;
    ret = 1;
    int mini = inf;
    for (int i = 1; i < y; i++) {
        mini = min(mini, calc(x, y - i) + calc(x , i));
    }
    for (int i = 1; i < x; i++) {
        mini = min(mini , calc(i , y) + calc(x - i , y));
    }
    ret += mini;
    return ret;
}

void solve() {
    cin >> a >> b;
    memset(dp , -1 , sizeof(dp));
    cout << calc(a , b) << nl;
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
