// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://vjudge.net/problem/UVA-10453
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
const int N = 1e3 + 5, M = 1e3, LOG = 20, inf = 0x3f3f3f3f;
ll infLL = 0x3f3f3f3f3f3f3f3f;

string s , ans;
int n , dp[N][N];

int calc(ll l , ll r) {
    if (r < l)
        return 0;
    int &ret = dp[l][r];
    if (~ret)
        return ret;
    ret = 0;
    if (s[l] != s[r])
        ret += min(calc(l + 1 , r) , calc(l , r - 1)) + 1;
    else
        ret += calc(l+ 1 , r - 1);
    return ret;
}

void track_and_generate(ll l , ll r) {
    if (r < l)
        return;
    if (s[l] == s[r]) {
        if (l == r) {
            ans += s[l];
        }
        else {
            track_and_generate(l + 1, r - 1);
            ans = s[l] + ans + s[r];
        }
    }
    else {
        if (calc(l + 1, r) < calc(l , r - 1)) {
            track_and_generate(l + 1, r);
            ans = s[l] + ans + s[l];
        }
        else {
            track_and_generate(l, r - 1);
            ans = s[r] + ans + s[r];
        }
    }

}

void solve() {
    ans = "";
    n = s.size();
    memset(dp, -1, sizeof(dp));
    cout << calc(0 , n - 1) << sp;
    track_and_generate(0 , n - 1);
    cout << ans << nl;;
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
    while (cin >> s) {
        solve();
    }

    return 0;
}
