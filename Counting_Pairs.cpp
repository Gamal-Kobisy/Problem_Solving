// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/contest/2051/problem/D
#include <bits/stdc++.h>
#define ll long long
#define nl '\n'
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
    ll total_sum = 0;
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
        total_sum += a[i];
    }

    sort(all(a)); // Sort for efficient range queries
    ll count = 0;

    for (ll i = 0; i < n; ++i) {
        // Calculate the valid range for a[j] based on a[i]
        ll L = total_sum - y - a[i];
        ll R = total_sum - x - a[i];

        // Find the number of elements in [L, R]
        auto left = lower_bound(a.begin() + i + 1, a.end(), L);
        auto right = upper_bound(a.begin() + i + 1, a.end(), R);
        count += (right - left); // Add the count of valid pairs
    }

    cout << count << nl;
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