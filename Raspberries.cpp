// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/contest/1883/problem/C
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
    ll n , k;
    cin >> n >> k;
    vector<ll>a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }
    ll ans = infLL;
    if(k == 4)
    {
        int even = 0;
        for (ll i = 0; i < n; ++i) {
            if(a[i] % 2 == 0)
                even++;
        }
        if(even >= 2)
            ans = 0;
        else if(even == 1)
            ans = 1;
        else
            ans = 2;
        for (ll i = 0; i < n; ++i) {
            if(a[i] % k == 0)
            {
                ans = 0;
                break;
            }
            ans = min(ans , k - a[i] % k);
        }
    }
    else
    {
        for (ll i = 0; i < n; ++i) {
            if(a[i] % k == 0)
            {
                ans = 0;
                break;
            }
            ans = min(ans , k - a[i] % k);
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