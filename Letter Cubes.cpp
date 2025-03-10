// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/group/Rilx5irOux/contest/526482/problem/I
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
ifstream infile("cube.in");

ll calc_c(ll x)
{
    return x * (x + 1);
}

void solve() {
    ll c = 0 , odds = 0;
    for (ll i = 0; i < 26; ++i) {
        ll freq;
        infile >> freq;
        if(freq & 1)
            odds++;
        c += freq / 2;
    }
    ll l = 0 , r = 1e9 , ans = 0;
    while (l <= r)
    {
        ll odds_c = odds;
        ll mid = (r + l) >> 1ll;
        ll needed_c = calc_c(mid / 2);
        if(!(mid & 1))
        {
            needed_c -= mid / 2;
        }
        ll needed_o = (mid + 1) / 2;
        if(needed_c < c)
            odds_c += (c - needed_c) * 2;
        bool ok = needed_c <=c;
        ok &= needed_o <= odds_c;
        if(ok)
        {
            ans = mid;
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    cout << ans << nl;
}
void file()
{
//#ifndef ONLINE_JUDGE
//    freopen("Input.txt", "r", stdin);
//    freopen("Output.txt", "w", stdout);
//    freopen("Error.txt", "w", stderr);
//#endif
}

int main() {
    file();
    ENG_GAMAL
// test-independent code ——————————————————————
// ————————————————————————————————————————————
    ll t = 1;
    infile >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}