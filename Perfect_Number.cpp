//
// DATE : Created by Gamal on 6/7/2024.
// LINK : https://vjudge.net/contest/586365#problem/R

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

bool divide(ll x)
{
    int cnt = 0;
    while (x)
    {
        cnt += x % 10;
        x /= 10;
    }
    return (cnt == 10);
}
void solve()
{
    ll ans , n;
    cin >> n;
    int x = 10, y = 1;
    for (int i = 1; i <= n;)
    {
        ans = x + 9 * y;
        if (divide(ans))
        {
            i++;
        }
        y++;
    }
    cout << ans;
}

void file()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
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
