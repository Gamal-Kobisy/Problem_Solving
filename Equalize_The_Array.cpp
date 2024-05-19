//
// Created by Gamal on 5/17/2024.
// https://vjudge.net/contest/585111#problem/AB
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif
long long t;
cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        map<long long , long long > freq;
        map <long long , long long>freq_of_freq;
        long long maxx = 0;
        for (long long i = 0; i < n; ++i)
        {
            long long num;
            cin >> num;
            freq[num]++;
            freq_of_freq[freq[num]]++;
        }

        for (const auto &item: freq_of_freq) {
            if(item.first * item.second >= maxx)
            {
                maxx = item.first * item.second;
            }
        }
        cout <<   n - maxx  << endl;
    }
    return 0;
}
