// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/contest/2152/problem/C
#include <bits/stdc++.h>
#define ll long long
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
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    vector<int> pre0(n + 1, 0), pre1(n + 1, 0), pre_dif(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        pre0[i] = pre0[i - 1] + (a[i] == 0);
        pre1[i] = pre1[i - 1] + (a[i] == 1);
        if (i > 1) pre_dif[i] = pre_dif[i - 1] + (a[i] != a[i - 1]);
        else pre_dif[i] = 0;
    }

    while (q--) {
        int l, r;
        cin >> l >> r;
        int ones  = pre1[r] - pre1[l - 1];
        int zeros = pre0[r] - pre0[l - 1];

        if (ones % 3 != 0 or zeros % 3 != 0) {
            cout << -1 << nl;
            continue;
        }
        int ans = ones / 3 + zeros / 3;
        if (pre_dif[r] - pre_dif[l] == (r - l))
            ans++;
        cout << ans << nl;
    }
}
void file()
{
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
     cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}