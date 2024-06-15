//
// DATE : Created by Gamal on 6/14/2024.
// LINK : https://vjudge.net/contest/588093#problem/F

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define nl '\n'
#define all(a) a.begin(),a.end()
#define allr(a) a.rbegin(),a.rend()
#define f1(n) for(int i=1;i<n;i++)
#define f0(n) for(int i=0;i<n;++i)
#define fe(v) for(auto & it:v)
#define pi 3.141592653589793238462643383279502884197
#define e 2.718281828459045
using namespace std;
using namespace __gnu_pbds;
struct un_ordered
{
    bool operator()(const long long &a, const long long &b) const
    {
        return true;
    }
};
template <class T>
using ordered_set = tree<T, null_type, un_ordered, rb_tree_tag, tree_order_statistics_node_update>;

void solve()
{
    ll n , m ,k;
    cin >> n >> m >> k;
    vector<ll> v(n) , pre_of_nums(n + 2) ,pre_of_oper(m+2) ;
    vector<pair<pair<ll , ll> ,ll>> oper(m + 2);
    for (ll i = 0; i < n; ++i) {
        cin >> v[i];
    }
    for (ll i = 0; i < m; ++i) {
        ll l , r , d;
        cin >> l >> r >> d;
        oper[i + 1] = {{l , r} ,d};
    }
    for (int i = 0; i < k; ++i) {
        ll x , y;
        cin >> x >> y;
        pre_of_oper[x]++;
        pre_of_oper[y + 1]--;
    }
    for (ll i = 1; i < m + 2; ++i) {
        pre_of_oper[i] += pre_of_oper[i - 1];
    }
    for (ll i = 1; i < m + 2; ++i) {
        pre_of_nums[oper[i].first.first] += oper[i].second * pre_of_oper[i];
        pre_of_nums[oper[i].first.second + 1] -= oper[i].second * pre_of_oper[i];
    }
    for (ll i = 0; i < n + 2; ++i) {
        pre_of_nums[i + 1] += pre_of_nums[i];
    }
    for (ll i = 0; i < n; ++i) {
        cout << v[i] + pre_of_nums[i + 1] << ' ' ;
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
