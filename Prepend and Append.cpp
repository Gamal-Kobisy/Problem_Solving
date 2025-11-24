// LINK: https://codeforces.com/problemset/problem/1791/C
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define nl '\n'

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        string s;
        cin >> n >> s;
        int l = 0, r = n - 1;
        while (l < r && s[l] != s[r]) {
            l++;
            r--;
        }
        int ans = (l > r) ? 0 : (r - l + 1);
        cout << ans << nl;
    }
    return 0;
}
