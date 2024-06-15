//
// DATE : Created by Gamal on 6/7/2024.
// LINK : https://vjudge.net/contest/586365#problem/O

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
    // o(n^3)
int n;
ll count = 0;
cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = i; j <= n; ++j) {
            for (int k = j; k <= n; ++k) {
                if ((i ^ j ^ k) == 0) {
                    if (i + j > k && i + k > j && j + k > i) {
                        ++count;
                    }
                }
            }
        }
    }
    cout << count << nl;
}
void good_solve()
{
    // o(n^2)
    int n;
    ll count = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = i; j <= n; ++j) {
            int k = i ^ j;
            if (k >= j && k <= n) {
                if (i + j > k && i + k > j && j + k > i) {
                    ++count;
                    }
                }
            }
        }
    cout << count << nl;
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
        good_solve();
    }

    return 0;
}
