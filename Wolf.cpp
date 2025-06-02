// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/contest/2106/problem/E
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
    ll n , q;
    cin >> n >> q;
    vector<ll>a(n);
    map<ll,ll>idx;
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
        idx[a[i]] = i;
    }
    while (q--) {
        ll l , r , k;
        cin >> l >> r >> k;
        l-- , r--;
        if(idx[k] > r || idx[k] < l)
        {
            cout << -1 << sp;
            continue;
        }
        ll needed_less = 0 , needed_more = 0 , less = 0 , more = 0;
        while (l <= r) {
            ll mid = (l + r) / 2;

            if(mid > idx[k])
            {
                r = mid - 1;
                more++;
                if(a[mid] < k)
                    needed_more++;
            }
            else if(mid < idx[k])
            {
                l = mid + 1;
                less++;
                if(a[mid] > k)
                    needed_less++;
            }
            else
                break;
        }
        if(n - k < more || k <= less)
        {
            cout << -1 << sp;
            continue;
        }
        cout << fabs(needed_more - needed_less) * 2 + min(needed_more , needed_less) * 2 << sp;
    }
    cout << nl;
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