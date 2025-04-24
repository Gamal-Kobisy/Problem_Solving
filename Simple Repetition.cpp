// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK :
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

bool Prime(ll n) {
	if (n == 1) return false;
	for (ll i = 2; i * i <= n; i++) {
        if (n % i == 0)
            return false;
	}
	return true;
}

void solve() {
    ll n, k;
    cin >> n >> k;
    ((Prime(n) && k == 1) || (n == 1 && k == 2)) ? yes : no;
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
