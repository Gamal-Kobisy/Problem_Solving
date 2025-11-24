// LINK: https://codeforces.com/problemset/problem/1850/A
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define nl '\n'

int main() {
    ll t;
    cin >> t;
    while (t--) {
        ll a, b, c;
        cin >> a >> b >> c;
        if (a + b >= 10 || a + c >= 10 || b + c >= 10) cout << "YES" << nl;
        else cout << "NO" << nl;
    }
    return 0;
}
