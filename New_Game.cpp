// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK :
#include <bits/stdc++.h>
#define ll long long
#define nl '\n'
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
    map<ll , ll>a;
    ll maxi = LLONG_MIN;
    for (ll i = 0; i < n; ++i) {
        ll x;
        cin >> x;
        maxi = max(maxi , x);
        a[x]++;
    }
    vector<ll>pre(maxi + 1);
    for (ll i = 1; i <= maxi; ++i) {
        ll freq;
        if(a.find(i) == a.end())
            freq = 0;
        else
            freq = a[i];
        pre[i] = pre[i - 1] + freq;
    }

    ll l = 0 , r = 1 , ans = 0;
    while(l <= r && r <= maxi)
    {
        if(r - l <= k && a[r])
        {
            ans = max(ans , pre[r] - pre[l]);
            r++;
        }
        else if(r - l > k)
        {
            l++;
        }
        else
        {
            l = r;
            r++;
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