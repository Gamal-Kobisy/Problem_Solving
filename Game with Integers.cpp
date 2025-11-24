// LINK: https://codeforces.com/problemset/problem/1899/A
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define nl '\n'

int main() {
    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        if (n % 3 == 0) cout << "Second" << nl;
        else cout << "First" << nl;
    }
    return 0;
}
