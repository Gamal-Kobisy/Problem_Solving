// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/problemset/problem/1703/B

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;

        string s;
        cin >> s;

        vector<bool> seen(26, false);
        ll distinct = 0;

        for (char c : s) {
            int id = c - 'A';
            if (!seen[id]) {
                seen[id] = true;
                distinct++;
            }
        }

        cout << n + distinct << '\n';
    }

    return 0;
}
