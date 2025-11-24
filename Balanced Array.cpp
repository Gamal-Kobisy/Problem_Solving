// LINK: https://codeforces.com/problemset/problem/1343/B

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int k = n / 2;
        if (k % 2 != 0) {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        vector<int> ans;
        for (int i = 1; i <= k; i++) ans.push_back(2 * i);
        for (int i = 1; i < k; i++) ans.push_back(2 * i - 1);
        ans.push_back(3 * k - 1);
        for (int x : ans) cout << x << " ";
        cout << "\n";
    }
    return 0;
}
