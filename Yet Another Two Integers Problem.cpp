// LINK: https://codeforces.com/problemset/problem/1409/A
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define nl '\n'

int main() {
    ll t;
    cin >> t;
    while (t--) {
        ll a, b;
        cin >> a >> b;
        ll diff = abs(a - b);
        cout << (diff + 9) / 10 << nl;
    }
    return 0;
}
