// LINK : https://codeforces.com/contest/2005/problem/B2
#include <bits/stdc++.h>
#define ll long long
#define nl '\n'
#define all(a) a.begin(),a.end()
#define allr(a) a.rbegin(),a.rend()
#define no cout<<"NO\n"
#define yes cout<<"YES\n"
#define ENG_GAMAL ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

/*
 ███████╗███╗   ██╗ ██████╗       ██████╗  █████╗ ███╗   ███╗ █████╗ ██╗
 ██╔════╝████╗  ██║██╔════╝      ██╔════╝ ██╔══██╗████╗ ████║██╔══██╗██║
 █████╗  ██╔██╗ ██║██║  ███╗     ██║  ███╗███████║██╔████╔██║███████║██║
 ██╔══╝  ██║╚██╗██║██║   ██║     ██║   ██║██╔══██║██║╚██╔╝██║██╔══██║██║
 ███████╗██║ ╚████║╚██████╔╝     ╚██████╔╝██║  ██║██║ ╚═╝ ██║██║  ██║███████╗
 ╚══════╝╚═╝  ╚═══╝ ╚═════╝       ╚═════╝ ╚═╝  ╚═╝╚═╝     ╚═╝╚═╝  ╚═╝╚══════╝
*/
// ————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
void solve() {
    ll n, m, q;
    cin >> n >> m >> q;

    vector<ll> tech(m);
    for (ll i = 0; i < m; ++i) {
        cin >> tech[i];
    }

    // Sort the tech array for binary search
    sort(tech.begin(), tech.end());

    for (ll i = 0; i < q; ++i) {
        ll cur;
        cin >> cur;

        // Find lower and upper bounds
        auto it_l = lower_bound(tech.begin(), tech.end(), cur);
        auto it_r = upper_bound(tech.begin(), tech.end(), cur);

        ll l = (it_l == tech.begin()) ? 0 : *(it_l - 1);
        ll r = (it_r == tech.end()) ? n + 1 : *it_r;

        if (l == 0) {
            cout << r - 1 << '\n';
        } else if (r == n + 1) {
            cout << r - l - 1 << '\n';
        } else {
            cout << abs(r - l) / 2 << '\n';
        }
    }
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
    while(t--)
    {
        solve();
    }

    return 0;
}