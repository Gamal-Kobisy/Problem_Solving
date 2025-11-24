// LINK: https://codeforces.com/problemset/problem/1829/A
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define nl '\n'

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    string target = "codeforces";
    while (t--) {
        string s;
        cin >> s;
        int diff = 0;
        for (int i = 0; i < 10; i++) {
            if (s[i] != target[i]) diff++;
        }
        cout << diff << nl;
    }
    return 0;
}
