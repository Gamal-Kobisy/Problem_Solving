// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/problemset/problem/1472/B

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int ones = 0, twos = 0;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            if (x == 1) ones++;
            else twos++;
        }

        int total = ones + 2 * twos;
        if (total % 2 != 0) {
            cout << "NO\n";
        } else {
            int half = total / 2;
            // We can use as many 2s as possible
            int twos_needed = min(twos, half / 2);
            half -= twos_needed * 2;
            // Remaining half must be covered by 1s
            if (half <= ones) cout << "YES\n";
            else cout << "NO\n";
        }
    }

    return 0;
}
