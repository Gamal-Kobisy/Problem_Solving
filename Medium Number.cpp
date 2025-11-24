// LINK: https://codeforces.com/problemset/problem/1760/A
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
        if ((a > b && a < c) || (a > c && a < b)) cout << a << nl;
        else if ((b > a && b < c) || (b > c && b < a)) cout << b << nl;
        else cout << c << nl;
    }
    return 0;
}
