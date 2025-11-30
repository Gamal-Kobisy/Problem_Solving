// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/problemset/problem/1926/A

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        int countA = 0, countB = 0;
        for (char c : s) {
            if (c == 'A') countA++;
            else countB++;
        }

        if (countA >= countB) cout << "A\n";
        else cout << "B\n";
    }
    return 0;
}
