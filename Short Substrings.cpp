// LINK: https://codeforces.com/problemset/problem/1367/A
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        string b;
        cin >> b;
        string a;
        a += b[0];
        for (int i = 1; i < b.size(); i += 2) {
            a += b[i];
        }
        cout << a << "\n";
    }
    return 0;
}
