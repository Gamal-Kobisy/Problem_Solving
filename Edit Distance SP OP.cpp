// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://cses.fi/problemset/task/1639
#include <bits/stdc++.h>
#define ll long long
#define nl '\n'
#define sp ' '
#define all(a) a.begin(),a.end()
#define allr(a) a.rbegin(),a.rend()
#define no cout<<"NO\n"
#define yes cout<<"YES\n"
#define ENG_GAMAL ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;
// ————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
const int N = 2e5 + 5, M = 1e3, LOG = 20, inf = 0x3f3f3f3f;
ll infLL = 0x3f3f3f3f3f3f3f3f;

string s, t;

int dp[5005][5005];


void solve() {
    cin >> s >> t;

    vector<int>prev(t.size() + 1);
    iota(all(prev), 0);

    for (int i = 1; i <= s.size(); ++i) {
        vector<int>curr(t.size() + 1);
        curr[0] = i;
        for (int j = 1; j <= t.size(); ++j) {
            if (s[i - 1] == t[j - 1])
                curr[j] = prev[j - 1];
            else
                curr[j] = min({prev[j - 1], prev[j], curr[j - 1]}) + 1;
        }
        prev = curr;
    }
    cout << prev[t.size()] << endl;
}

void file() {
#ifndef ONLINE_JUDGE
    freopen("Input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
    freopen("Error.txt", "w", stderr);
#endif
}

int main() {
    file();
    ENG_GAMAL
    // test-independent code ——————————————————————
    // ————————————————————————————————————————————
    ll t = 1;
    //     cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
