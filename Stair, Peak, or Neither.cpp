// LINK: https://codeforces.com/problemset/problem/1950/A
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define nl '\n'

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a < b && b < c) cout << "STAIR" << nl;
        else if (a < b && b > c) cout << "PEAK" << nl;
        else cout << "NONE" << nl;
    }
    return 0;
}
