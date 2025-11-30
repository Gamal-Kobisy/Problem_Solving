// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/problemset/problem/1433/A

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int x;
        cin >> x;

        string s = to_string(x);
        int d = s[0] - '0';
        int len = s.size();

        int ans = (d - 1) * (1 + 2 + 3 + 4) + (len * (len + 1) / 2);

        cout << ans << "\n";
    }
    return 0;
}
