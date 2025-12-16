// https://codeforces.com/problemset/problem/1829/A

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    string ref = "codeforces";
    while (t--) {
        string s;
        cin >> s;
        int cnt = 0;
        for (int i = 0; i < 10; i++) {
            if (s[i] != ref[i]) cnt++;
        }
        cout << cnt << nl;
    }
    return 0;
}
