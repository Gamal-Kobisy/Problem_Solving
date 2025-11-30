// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/problemset/problem/1551/A

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;

        long long c2 = n / 3;
        long long c1 = n - 2*c2;

        if (c1 - c2 > 1) {
            c2++;
            c1 = n - 2*c2;
        }

        cout << c1 << " " << c2 << "\n";
    }

    return 0;
}
