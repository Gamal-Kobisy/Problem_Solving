// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/contest/2075/problem/C
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

ll fact(int n) {
    ll f = 1;
    for (int i = 2; i <= n; i++) {
        f *= i;
    }
    return f;
}

ll p(int n, int r) {
    if (r > n) return 0;
    return fact(n) / fact(n - r);
}

ll c(int n, int r) {
    if (r > n) return 0;
    return fact(n) / (fact(r) * fact(n - r));
}

void solve() {
    ll n , m;
    cin >> n >> m;
    vector<ll>a(m);
    for (ll i = 0; i < m; ++i) {
        cin >> a[i];
        a[i] *= -1;
    }
    sort(all(a));
    ll ans = 0;
    for (ll i = 1; i < n; ++i) {
        ll cnt1 = upper_bound(all(a) , -i) - a.begin();
        ll cnt2 = upper_bound(all(a) , -n + i) - a.begin();
        ans += cnt1 * cnt2 - min(cnt1 , cnt2);
    }
    cout << ans << nl;
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