// LINK: https://codeforces.com/problemset/problem/1560/A
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define nl '\n'

int main() {
    ll t;
    cin >> t;
    while (t--) {
        ll k;
        cin >> k;
        ll count = 0, num = 0;
        while (count < k) {
            num++;
            if (num % 3 != 0 && num % 10 != 3) count++;
        }
        cout << num << nl;
    }
    return 0;
}
