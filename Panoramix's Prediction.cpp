// LINK: https://codeforces.com/problemset/problem/80/A
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    // list of primes up to 50
    vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};

    for (int i = 0; i < primes.size(); i++) {
        if (primes[i] == n) {
            if (i + 1 < primes.size() && primes[i + 1] == m) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
            break;
        }
    }

    return 0;
}
