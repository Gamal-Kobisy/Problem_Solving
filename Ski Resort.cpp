// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/problemset/problem/1840/C
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

ll sum(ll a , ll b)
{
    if(a < b)
        return 0;
    ll res = (a * (a + 1)) / 2;
    res -= (b * (b - 1)) / 2;
    return res;
}

void solve() {
    ll n , k , q;
    cin >> n >> k >> q;
    vector<ll>a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }
    a.emplace_back(q + 1);
    ll l = 0 , r = 0 , ans = 0;
    while (l <= r && r < a.size())
    {
        if(a[r] <= q)
            r++;
        else
        {
            int chain = r - l;
            for (ll i = k; i <= chain; ++i) {
                ans += chain - i + 1;
            }
            r = l = r + 1;
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