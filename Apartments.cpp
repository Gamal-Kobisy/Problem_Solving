//
// DATE : Created by Gamal on 8/4/2024.
// LINK : https://cses.fi/problemset/task/1084

#include <iostream>
#include <set>
#include <queue>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define nl '\n'
using namespace std;

void solve()
{
    ll n , m , k;
    cin >> n >> m >> k;
    priority_queue<ll>a;
    multiset<ll>b;
    for (ll i = 0; i < n; ++i) {
        ll x;
        cin >> x;
        a.push(-x);
    }
    for (ll i = 0; i < m; ++i) {
        ll x;
        cin >> x;
        b.insert(x);
    }
    ll ans = 0;
    while (!a.empty())
    {
        ll top = -a.top();
        a.pop();
        auto it = b.lower_bound(top - k);
        if(*it <= top + k && it != b.end())
        {
            ans++;
            b.erase(it);
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
void fast()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

}
int main() {
    file();
    fast();
    ll t = 1;
    // cin >> t;
    while(t--)
    {
        solve();
    }

    return 0;
}
