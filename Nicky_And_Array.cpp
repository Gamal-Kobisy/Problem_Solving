//
// DATED : Created by Gamal on 6/7/2024.
// LINK : https://vjudge.net/contest/586365#problem/L

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
    long long sz;
    vector<long long> nums, neg_nums;
    cin >> sz;
    long long neg_counter = 0, maxx = LLONG_MIN, minn = LLONG_MAX;
    for (long long i = 0; i < sz; i++)
    {
        long long x;
        cin >> x;
        if (x < 0)
        {
            x = -x - 1;
        }
        nums.emplace_back(x);
        maxx = max(maxx, x);
        minn = min(minn, x);
    }
    if (sz % 2 == 0)
    {
        for (long long i : nums)
        {
            cout << -i - 1 << ' ';
        }
    }
    else
    {
        bool max_not_found = true;
        for (long long i : nums)
        {
            if (i == maxx && max_not_found)
            {
                cout << i << ' ';
                max_not_found = false;
            }
            else
            {
                cout << -i - 1 << ' ';
            }
        }
    }
    cout << endl;
}

void file()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
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
