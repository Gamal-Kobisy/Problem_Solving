// LINK: https://codeforces.com/problemset/problem/703/A
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int mishkaWins = 0, chrisWins = 0;

    for (int i = 0; i < n; i++) {
        int m, c;
        cin >> m >> c;
        if (m > c) mishkaWins++;
        else if (c > m) chrisWins++;
    }

    if (mishkaWins > chrisWins) cout << "Mishka\n";
    else if (chrisWins > mishkaWins) cout << "Chris\n";
    else cout << "Friendship is magic!^^\n";

    return 0;
}
