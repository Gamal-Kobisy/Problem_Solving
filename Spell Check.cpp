// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/problemset/problem/1722/A

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

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

        string target = "Timur";
        if (n != 5) {
            cout << "NO\n";
            continue;
        }

        sort(s.begin(), s.end());
        string sortedTarget = target;
        sort(sortedTarget.begin(), sortedTarget.end());

        if (s == sortedTarget)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}
