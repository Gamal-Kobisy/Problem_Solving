//
// DATE : Created by Gamal on 6/14/2024.
// LINK : https://vjudge.net/contest/588093#problem/G

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
    ll n , k;
    cin >> n >> k;
    vector<ll>nums(n) , wake_up(n) , sleep(n) , pre(n+1);
    for (ll i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    ll max_sum = 0;
    for (ll i = 0; i < n; ++i) {
        short x;
        cin >> x;
        if(x)
        {
            max_sum += nums[i];
            wake_up[i] = nums[i];
        }
        else
        {
            sleep[i] = nums[i];
        }
    }
    ll sum = LLONG_MIN;
    for (ll i = 1; i < n + 1; ++i) {
        pre[i] = pre[i - 1] + sleep[i - 1];
        if(i >= k)
        {
            ll temp = pre[i] - pre[i - k];
            sum = max(sum , pre[i] - pre[i - k]);
        }
    }

    cout  << max_sum + sum << nl;
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
