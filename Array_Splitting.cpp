//
// DATE : Created by Gamal on 6/9/2024.
// LINK : https://vjudge.net/contest/586365#problem/E

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
    vector <ll> nums(n);
    f0(n)
    {
        cin >> nums[i];
    }
    ll max_array = LLONG_MAX , max_array_index = 0;
    if(n % k)
    {
        ll mod = (n % k) , size_of_normalArray = (((n - (n % k)) / k));
        ll size_of_maxArray = mod + size_of_normalArray;
        for (int i = 0; i < n - size_of_normalArray; i += size_of_normalArray) {
            ll temp_sum = 0;
            for (int j = 0; j < size_of_maxArray; ++j) {
                temp_sum += nums[i + j];
            }
            if(temp_sum <= max_array)
            {
                max_array = temp_sum;
                max_array_index = i;
            }
        }
        nums.erase(nums.begin() + max_array_index , nums.begin() + max_array_index + size_of_normalArray + 1);
        ll Max_Cost = 0;
        vector <ll> all_arrays;
        all_arrays.push_back(max_array);
        for (ll i = 0; i < (n - size_of_maxArray) / k; i += size_of_normalArray) {
            ll temp_sum = 0;
            for (int j = 0; j < size_of_normalArray; ++j) {
                temp_sum += nums[i + j];
            }
            all_arrays.push_back(temp_sum);
        }
        sort(allr(all_arrays));
        cout << "DONE\n";
    }
    else
    {

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
