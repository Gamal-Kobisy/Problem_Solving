// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/problemset/problem/1858/A

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        long long a, b, c;
        cin >> a >> b >> c;

        if (a > b) {
            cout << "First\n";
        } else if (b > a) {
            cout << "Second\n";
        } else {
            // a == b
            if (c % 2 == 1)
                cout << "First\n";
            else
                cout << "Second\n";
        }
    }

    return 0;
}
