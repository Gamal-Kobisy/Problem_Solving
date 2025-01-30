// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/contest/2051/problem/E
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
    vector<pair<ll , bool>>All(2 * n);
    for (ll i = 0; i < n; ++i) {
        ll p;
        cin >> p;
        All[i] = {p , false};
    }
    for (ll i = 0; i < n; ++i) {
        ll p;
        cin >> p;
        All[n + i] = {p , true};
    }
    sort(all(All));
    ll ans = 0 , customers = n , neg = 0;
    for (ll i = 0; i < 2 * n ;) {
        ll p = All[i].first;
        if(neg <= k)
            ans = max(ans , All[i].first * customers);
        while (i < 2 * n && All[i].first == p)
        {
            if(All[i].second == false)
                neg++;
            if(All[i].second == true)
                customers-- , neg--;
            i++;
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