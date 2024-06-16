//
// DATE : Created by Gamal on 6/16/2024.
// LINK : https://vjudge.net/contest/588093#problem/V

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
    vector<long long> heights(n);
    for (long long i = 0; i < n; ++i) {
        cin >> heights[i];
    }

    vector<long long> minus_pre(n, 0), minus_suff(n, 0);

    for (int i = 1; i < n; ++i) {
        if (heights[i] < heights[i - 1]) {
            minus_pre[i] = minus_pre[i - 1] + (heights[i - 1] - heights[i]);
        } else {
            minus_pre[i] = minus_pre[i - 1];
        }
    }

    for (int i = n - 2; i >= 0; --i) {
        if (heights[i] < heights[i + 1]) {
            minus_suff[i] = minus_suff[i + 1] + (heights[i + 1] - heights[i]);
        } else {
            minus_suff[i] = minus_suff[i + 1];
        }
    }

    for (long long i = 0; i < k; ++i) {
        long long l, r;
        cin >> l >> r;
        l--;
        r--;
        if (l < r) {
            cout << minus_pre[r] - minus_pre[l] << '\n';
        } else {
            cout << minus_suff[r] - minus_suff[l] << '\n';
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
