// LINK: https://codeforces.com/problemset/problem/472/A
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define nl '\n'

int main() {
    ll n;
    cin >> n;
    if (n % 2 == 0) {
        cout << 4 << " " << n - 4 << nl; // even n: 4 + (n-4)
    } else {
        cout << 9 << " " << n - 9 << nl; // odd n: 9 + (n-9)
    }
    return 0;
}
