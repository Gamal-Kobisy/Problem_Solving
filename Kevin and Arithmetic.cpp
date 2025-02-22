// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/contest/2061/problem/A
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
    int n;
    cin >> n;
    vector<ll>ev , od;
    for (ll i = 0; i < n; ++i) {
        ll x;
        cin >> x;
        (x & 1 ? od.emplace_back(x) : ev.emplace_back(x));
    }
    ll ans = 0 , sum = 0;
    while (ev.size() || od.size())
    {
        if(ev.size())
            sum += ev.back() , ev.pop_back();
        if(sum % 2 == 0 && sum)
        {
            ans++;
            while (sum % 2 == 0)
                sum /= 2;
        }
        if(od.size())
            sum += od.back() , od.pop_back();
        if(sum % 2 == 0 && sum)
        {
            ans++;
            while (sum % 2 == 0)
                sum /= 2;
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