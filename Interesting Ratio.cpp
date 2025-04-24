// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/problemset/problem/2091/E
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
const int N = 1e7 + 5, M = 1e3, LOG = 20, inf = 0x3f3f3f3f;
ll infLL = 0x3f3f3f3f3f3f3f3f;


vector<int> primes;
vector<bool> is_prime;

void Sieve(int n) {
    is_prime.assign(n + 1, true);
    is_prime[0] = is_prime[1] = false;

    for (int i = 2; i <= n; i++) {
        if (is_prime[i]) {
            primes.emplace_back(i);
            for (ll j = 1LL * i * i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }
}


void solve() {
    ll n;
    cin >> n;
	ll ans = 0;

    for (int i = 2; i <= n; i++)
    {
		if (is_prime[i])
            ans += n / i;
    }
	cout << ans << nl;
}

int main() {
    ENG_GAMAL
        // test-independent code ——————————————————————
         Sieve(N);
        // ———————————————————————————————————————————— 
        ll t = 1;
         cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}
