// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/contest/2065/problem/D
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

void solve() {
    ll n , m;
    cin >> n >> m;
    vector<vector<ll>>a(n , vector<ll>(m + 1));
    vector<pair<ll , ll>>sum(n);
    for (ll i = 0; i < n; ++i) {
        ll pre_sum = 0 , t_sum = 0;
        for (ll j = 1; j <= m; ++j) {
            cin >> a[i][j];
            t_sum += a[i][j];
            a[i][j] += a[i][j - 1];
            pre_sum += a[i][j];
        }
        sum[i] = {t_sum , pre_sum};
    }
    sort(allr(sum));
    ll ans = 0;
    for (ll i = 0; i < n; ++i) {
        ans += sum[i].second;
        ans += sum[i].first * ((n-1-i) * m);
    }
    cout << ans  << nl;
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
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}