//
// DATE : Created by Gamal on 6/16/2024.
// LINK : https://vjudge.net/contest/588093#problem/P

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
struct compare
{
    bool operator()(pair<ll , ll>a, pair<ll , ll>b) const
    {
        return a.second <= b.second;
    }
};
template <class T>
using ordered_set = tree<T, null_type, less_equal<>, rb_tree_tag, tree_order_statistics_node_update>;

void solve()
{
    ll n , k;
    cin >> n >> k;
    vector<ll> v(n) , pre(n+2) , new_v(n) , new_pre(n+1) ;
    vector<pair<ll,ll>>q(k);
    priority_queue<ll , vector<ll> , less_equal<>> sorted_nums;
    for (ll i = 0; i < n; ++i) {
        cin >> v[i];
        sorted_nums.push(v[i]);
    }
    for (ll i = 0; i < k; ++i) {
        ll l , r;
        cin >> l >> r;
        q[i] = {l , r};
        pre[l]++;
        pre[r+1]--;
    }
    for (ll i = 0; i < n + 2; ++i) {
        pre[i + 1] += pre[i];
    }
    priority_queue<pair<ll,ll> , vector<pair<ll,ll>> , compare>pq;
    for (ll i = 1; i <= n; ++i) {
        pq.push(make_pair(i , pre[i]));
    }
    while(!pq.empty())
    {
        new_v[pq.top().first - 1] = sorted_nums.top();
        sorted_nums.pop();
        pq.pop();
    }
    for (ll i = 0; i < n; ++i) {
        new_pre[i+1] = new_pre[i] + new_v[i];
    }
    ll sum = 0;
    for (ll i = 0; i < k; ++i) {
        sum += new_pre[q[i].second] - new_pre[q[i].first - 1];
    }
    cout << sum << nl;
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
