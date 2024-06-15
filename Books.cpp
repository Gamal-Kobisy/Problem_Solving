//
// DATE : Created by Gamal on 6/14/2024.
// LINK : https://vjudge.net/contest/588093#problem/L

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

void solve() {
    long long n, time;
    cin >> n >> time;
    vector<long long> nums(n);

    for (long long i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    long long current_sum = 0;
    int start = 0;
    int max_books = 0;

    for (int end = 0; end < n; ++end) {
        current_sum += nums[end];

        while (current_sum > time) {
            current_sum -= nums[start];
            ++start;
        }

        max_books = max(max_books, end - start + 1);
    }

    cout << max_books << endl;
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