//
// DATE : Created by Gamal on 6/11/2024.
// LINK : https://vjudge.net/contest/588093#problem/B

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
    ll n , k;
    cin >> n >> k;
    vector<ll> v(n);
    set<ll>s;
    ordered_set<pair<ll,ll>>os;
    vector<map<ll,ll>> pre(n + 1);
    for (ll i = 0; i < n; ++i) {
        cin >> v[i];
        s.insert(v[i]);
        pre[i + 1][v[i]] = 1;
    }
    for(auto it : pre)
    {
        for(auto it2 : s)
        {
            it[it2];
        }
    }
    for (ll i = 1;  i < n +1 ; i++) {
        for(auto it2 : s)
        {
            pre[i][it2] += pre[i - 1][it2];
        }
    }
    cout << "DONE\n";
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
    cin >> t;
    while(t--)
    {
        solve();
    }

    return 0;
}
