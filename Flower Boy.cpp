// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/contest/2106/problem/D
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

void solve() {
    ll n , m;
    cin >> n >> m;
    vector<ll>a(n) , b(m);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (ll i = 0; i < m; ++i) {
        cin >> b[i];
    }
    vector<ll>pre(n + 1) , suf(n + 1);
    int idx = 0;
    for (ll i = 1; i <= n; ++i) {
        if(idx < m && a[i - 1] >= b[idx])
            pre[i] = pre[i - 1] + 1 , idx++;
        else
            pre[i] = pre[i - 1];
    }
    idx = m - 1;
    for (ll i = n - 1; i >= 0; --i) {
        if(idx >= 0 && a[i] >= b[idx])
            suf[i] = suf[i + 1] + 1 , idx--;
        else
            suf[i] = suf[i + 1];
    }
    if(pre[n] == m)
        return void(cout << 0 << nl);
    ll ans = inf;
    for (ll i = 0; i <= n; ++i) {
        if(suf[i] + pre[i] + 1 == m)
            ans = min(ans , b[pre[i]]);
    }
    cout << (ans == inf ? -1 : ans) << nl;
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