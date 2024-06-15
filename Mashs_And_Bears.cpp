//
// DATE : Created by Gamal on 6/7/2024.
// LINK : https://vjudge.net/contest/586365#problem/I

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
vector<int>v(4) , ans(3);
f0(4)
{
    cin >> v[i];
}
if(2 * v[2] < v[3] || 2 * v[3] < v[2] ||  v[3] >= v[1] )
{
    cout << -1 << nl;
}
else
{
ans[2] = max(v[2] , v[3]);
ans[1] = 2 * v[1];
ans[0] = 2 * v[0];
fe(ans)
{
    cout << it << nl;
}
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
