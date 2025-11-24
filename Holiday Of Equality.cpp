// LINK: https://codeforces.com/problemset/problem/758/A
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define nl '\n'

int main() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++) cin >> a[i];
    ll mx = *max_element(a.begin(), a.end());
    ll sum = 0;
    for (ll i = 0; i < n; i++) sum += (mx - a[i]);
    cout << sum << nl;
    return 0;
}
