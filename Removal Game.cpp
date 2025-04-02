// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"
 
// LINK : https://cses.fi/problemset/task/1097
 
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
const int N = 5000 + 5, M = 1e3, LOG = 20, inf = 0x3f3f3f3f;
ll infLL = 0x3f3f3f3f3f3f3f3f;
 
ll a[N];
pair<ll, ll> dp[N][N];
bool computed[N][N];

pair<ll, ll> calc(int l, int r) {
    if (l > r)
        return {0, 0};
    if (l == r)
        return {a[l], 0};

    auto &ret = dp[l][r];

    if (computed[l][r])
        return ret;
    computed[l][r] = true;

    auto op1 = calc(l + 1, r);
    auto op2 = calc(l, r - 1);
    if (a[l] + op1.second > a[r] + op2.second) {
        ret = {a[l] + op1.second, op1.first};
    } else {
        ret = {a[r] + op2.second, op2.first};
    }
    return ret;
}

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    memset(dp,-1,sizeof(dp));
    cout << calc(0,n-1).first << nl;
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