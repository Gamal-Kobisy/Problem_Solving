//
// DATE : Created by Gamal on 6/13/2024.
// LINK : https://vjudge.net/contest/588093#problem/C

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
    ll n , q;
    cin >> n >> q;
    vector<ll>pre(n + 1);
    pre[0] = 0;
    vector<ll> nums;
    multiset<ll , greater_equal<>> sorted_nums;
    ll k;
    for (ll i = 0; i < n; ++i) {
        cin >> k;
        sorted_nums.insert(k);
    }
    for(auto i : sorted_nums)
    {
        nums.emplace_back(i);
    }
    for (ll i = 0; i < n; ++i) {
        pre[i + 1] = pre[i] + nums[i];
    }
    for (ll i = 0; i < q; ++i) {
        ll x , y;
        cin >> x >> y;
        cout << pre[x] - pre[x - (y)] << nl;
    }
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