// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/problemset/problem/1619/A

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int n = s.size();

        if (n % 2 == 1) {
            cout << "NO\n";
            continue;
        }

        string a = s.substr(0, n/2);
        string b = s.substr(n/2);

        if (a == b) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
