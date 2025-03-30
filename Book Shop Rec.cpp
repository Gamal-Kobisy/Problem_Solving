// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://cses.fi/problemset/task/1158
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
const int N = 1e3 + 5, M = 1e5 + 5, LOG = 20, inf = 0x3f3f3f3f;
ll infLL = 0x3f3f3f3f3f3f3f3f;

int W[N], V[N], dp[N][M], n, x;

int calc(ll idx, ll w) {
    if (idx == n || w > x)
        return 0;

    int &ret = dp[idx][w];
    if (~ret)
        return ret;
    ret = calc(idx + 1, w);
    if (w + W[idx] <= x)
        ret = max(ret, calc(idx + 1, w + W[idx]) + V[idx]);

    return ret;
}

void solve() {
    cin >> n >> x;
    for (ll i = 0; i < n; ++i)
        cin >> W[i];
    for (ll i = 0; i < n; ++i)
        cin >> V[i];
    memset(dp, -1, sizeof dp);
    cout << calc(0, 0) << nl;
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