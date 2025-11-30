// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/problemset/problem/1520/A

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
        string s;
        cin >> s;

        set<char> seen;
        char last = 0;
        bool suspicious = false;

        for (char c : s) {
            if (c != last) {
                if (seen.count(c)) {
                    suspicious = true;
                    break;
                }
                seen.insert(last);
                last = c;
            }
        }
        cout << (suspicious ? "NO" : "YES") << '\n';
    }

    return 0;
}
