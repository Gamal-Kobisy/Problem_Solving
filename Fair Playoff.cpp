// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/problemset/problem/1535/A

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        vector<int> s(4);
        for (int i = 0; i < 4; ++i) cin >> s[i];

        int w1 = max(s[0], s[1]);
        int w2 = max(s[2], s[3]);

        vector<int> best = s;
        sort(best.begin(), best.end(), greater<int>()); // descending
        vector<int> winners = {w1, w2};
        sort(winners.begin(), winners.end(), greater<int>());

        if (winners == vector<int>{best[0], best[1]})
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}
