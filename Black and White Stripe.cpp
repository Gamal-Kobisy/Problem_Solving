// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/problemset/problem/1690/D
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
    ll n, k;
    string s;
    cin >> n >> k >> s;
    ll ans = infLL;
	vector<ll>pre(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		pre[i] = pre[i - 1] + (s[i - 1] == 'W');
	}
	for (int i = 0; i <= n - k; i++) {
		ans = min(ans, pre[i + k] - pre[i]);
	}
	if (ans == infLL) {
		cout << 0 << nl;
	}
	else {
		cout << ans << nl;
	}
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
