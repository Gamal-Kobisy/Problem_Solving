// LINK: https://codeforces.com/problemset/problem/1915/A
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
        if (a == b) cout << c << nl;
        else if (a == c) cout << b << nl;
        else cout << a << nl;
    }
    return 0;
}
