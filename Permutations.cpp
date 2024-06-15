//
// DATE : Created by Gamal on 6/9/2024.
// LINK : https://vjudge.net/contest/586365#problem/V

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
    int n, k;
    cin >> n >> k;
    vector <string> nums(n);
    string prem ;
    f0(n)
    {
        cin >> nums[i];
    }
    f0(k)
    {
        prem += i + '0';
    }
    int min_diff = INT_MAX;

    do {
        vector <int> new_nums(n);
        int minn = INT_MAX;
        int maxx = INT_MIN;
        for (int i = 0; i < n; ++i) {
            string new_num;
            for (int j = 0; j < k ; ++j) {
                new_num += nums[i][prem[j] - '0'];
            }
            new_nums[i] = stoi(new_num);
            minn = min(minn , new_nums[i]);
            maxx = max(maxx , new_nums[i]);
        }
        min_diff = min(min_diff , maxx - minn);
    }while(next_permutation(all(prem)));
        cout << min_diff << nl;
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
