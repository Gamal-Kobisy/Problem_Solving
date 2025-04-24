// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://vjudge.net/contest/711339#problem/Q
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
    ll n, x, y;
    cin >> n >> x >> y;
    vector<ll> a(n);
    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
		sum += a[i];
    }
	sort(all(a));
	ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        ll l = lower_bound(a.begin() + i + 1, a.end(), (sum - a[i] - y)) - a.begin();
		ll r = upper_bound(a.begin() + i + 1, a.end(), (sum - a[i] - x)) - a.begin();
		ans += (r - l);
    }
	cout << ans << nl;
}

int main() {
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
