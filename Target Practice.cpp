// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/problemset/problem/1873/C

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        vector<string> g(10);
        for (int i = 0; i < 10; ++i) cin >> g[i];

        int ans = 0;
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < 10; ++j) {
                if (g[i][j] == 'X') {
                    int dist = min(min(i, j), min(9 - i, 9 - j));
                    int val = dist + 1; // outermost (dist=0) -> 1, center (dist=4) -> 5
                    ans += val;
                }
            }
        }
        cout << ans << '\n';
    }

    return 0;
}
