// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/problemset/problem/749/A

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    if (n % 2 == 0) {
        cout << n/2 << "\n";
        for (int i = 0; i < n/2; ++i) cout << "2 ";
        cout << "\n";
    } else {
        cout << n/2 << "\n";
        for (int i = 0; i < n/2 - 1; ++i) cout << "2 ";
        cout << "3\n";
    }

    return 0;
}
