// LINK: https://codeforces.com/problemset/problem/490/A
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define nl '\n'

int main() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    vector<ll> p1, p2, p3; // indices of 1, 2, 3
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] == 1) p1.push_back(i + 1);
        else if (a[i] == 2) p2.push_back(i + 1);
        else p3.push_back(i + 1);
    }
    ll w = min({p1.size(), p2.size(), p3.size()});
    cout << w << nl;
    for (ll i = 0; i < w; i++) {
        cout << p1[i] << " " << p2[i] << " " << p3[i] << nl;
    }
    return 0;
}
