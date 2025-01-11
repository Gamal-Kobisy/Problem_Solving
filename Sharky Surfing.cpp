// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/problemset/problem/2037/D
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
    ll n , m , L;
    cin >> n >> m >> L;
    vector<tuple<int , int , int>>road;
    for (ll i = 0; i < n; ++i) {
        ll l , r;
        cin >> l >> r;
        road.push_back({l, r, -1});
    }
    for (ll i = 0; i < m; ++i) {
        ll x  , v;
        cin >> x >> v;
        road.push_back({x , x , v});
    }

    sort(all(road));
    priority_queue<ll , vector<ll> , less_equal<>>untaked_powerups;
    ll curr_power = 1 , ans = 0;

    for (ll i = 0; i < road.size(); ++i) {
        if(get<2>(road[i]) == -1)
        {
            while (!untaked_powerups.empty() && get<1>(road[i]) - get<0>(road[i]) + 1 >= curr_power)
            {
                ans++;
                curr_power += untaked_powerups.top();
                untaked_powerups.pop();
            }
            if(get<1>(road[i]) - get<0>(road[i]) + 1 >= curr_power)
                return void(cout << -1 << nl);
        }
        else
            untaked_powerups.push(get<2>(road[i]));
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