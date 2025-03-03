// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/contest/2070/problem/C
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
    string s;
    cin >> s;
    vector<ll>a(n);
    ll ans = LLONG_MAX;
    ll l = 0 , r = 0;
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
        r = max(r , a[i]);
    }
    while (l <= r)
    {
        ll mid = (r + l) / 2;
        ll k_copy = k;
        bool used = false;
        for (ll i = 0; i < n ; ++i) {
            while (i < n && !(a[i] > mid && s[i] == 'R'))
            {
                used |= a[i] > mid;
                i++;
            }
            if(used)
                k_copy-- , used = false;
        }
        if(k_copy >= 0)
        {
            ans = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
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