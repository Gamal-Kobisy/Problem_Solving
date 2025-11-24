// LINK: https://codeforces.com/problemset/problem/431/A

#include <bits/stdc++.h>
using namespace std;

int main() {
    int a[4];
    for (int i = 0; i < 4; i++) cin >> a[i];

    string s;
    cin >> s;

    int total = 0;
    for (char c : s) {
        total += a[c - '1'];  // convert '1'-'4' to index 0-3
    }

    cout << total << endl;
    return 0;
}
