// LINK: https://codeforces.com/problemset/problem/1873/A
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define nl '\n'

string alph = "abc";

void TC() {
    string s;
    cin >> s;
    int cnt = 0;
    for (int i = 0; i < 3; i++) {
        cnt += (s[i] != alph[i]);
    }
    cout << (cnt <= 2 ? "YES\n" : "NO\n");
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc;
    cin >> tc;
    while(tc--)
        TC();
}






