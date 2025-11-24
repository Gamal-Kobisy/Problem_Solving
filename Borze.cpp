// LINK: https://codeforces.com/problemset/problem/32/B
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define nl '\n'

int main() {
    string s;
    cin >> s;
    string res = "";
    for (size_t i = 0; i < s.size(); i++) {
        if (s[i] == '.') res += '0';
        else if (s[i] == '-' && i + 1 < s.size() && s[i+1] == '.') {
            res += '1';
            i++;
        } else if (s[i] == '-' && i + 1 < s.size() && s[i+1] == '-') {
            res += '2';
            i++;
        }
    }
    cout << res << nl;
    return 0;
}
