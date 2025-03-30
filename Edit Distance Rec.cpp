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

int calc(int idx1 , int idx2) {
    if (idx1 == s.size())
        return t.size() - idx2;
    if (idx2 == t.size())
        return s.size() - idx1;
    int &ret = dp[idx1][idx2];
    if (ret != inf)
        return ret;
    if (idx1 < s.size() && idx2 < t.size() && s[idx1] == t[idx2])
        ret = calc(idx1 + 1, idx2 + 1);
    else {
        if (idx1 + 1 <= s.size() && idx2 + 1 <= t.size())
            ret = calc(idx1 + 1, idx2 + 1) + 1;
        if (idx1 + 1 <= s.size())
            ret = min(ret , calc(idx1 + 1, idx2) + 1);
        if (idx2 + 1 <= t.size())
            ret = min(ret , calc(idx1, idx2 + 1) + 1);
    }
    return ret;
}

void solve() {
    cin >> s >> t;
    memset(dp, inf, sizeof(dp));
    // if (s.size() > t.size())
    //     swap(s, t);
    // while (s.size() != t.size())
    //     s += "*";
    cout << calc(0, 0) << nl;
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
