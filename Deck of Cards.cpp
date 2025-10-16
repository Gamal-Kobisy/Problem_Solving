// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/problemset/problem/2145/B
#include <bits/stdc++.h>
#define ll long long
#define int ll
#define nl '\n'
#define sp ' '
#define all(a) a.begin(),a.end()
#define allr(a) a.rbegin(),a.rend()
#define no cout<<"NO\n"
#define yes cout<<"YES\n"
#define imp cout<<"IMPOSSIBLE\n"
#define ENG_GAMAL ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;
// ————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
const int N = 2e5 + 5, M = 1e3, LOG = 20, inf = 0x3f3f3f3f;
ll infLL = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int cnt0 = 0, cnt1 = 0, cnt2 = 0;
    for (char c : s) {
        if (c == '0') ++cnt0;
        else if (c == '1') ++cnt1;
        else if (c == '2') ++cnt2;
    }
    int Lmin = cnt0;
    int Lmax = cnt0 + cnt2;
    int rem = n - k;
    string ans(n, '-');
    if(rem > 0){
        int unionL = Lmin + 1;
        int unionR = Lmax + rem;
        int interL = Lmax + 1;
        int interR = Lmin + rem;
        for (int i = 1; i <= n; ++i) {
            if (i >= interL && i <= interR) ans[i-1] = '+';
            else if (i >= unionL && i <= unionR) ans[i-1] = '?';
            else ans[i-1] = '-';
        }
    }

    cout << ans << nl;
}
void file()
{
#ifndef ONLINE_JUDGE
    freopen("Input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
    freopen("Error.txt", "w", stderr);
#endif
}

signed main() {
    file();
    ENG_GAMAL
// test-independent code ——————————————————————
// ————————————————————————————————————————————
    ll t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}