//
// Created by Gamal on 5/15/2024.
// https://vjudge.net/contest/585111#problem/X
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
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
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
        long long n , r;
        cin >> n >> r;
        set<long long> monsters;
        for (long long i = 0; i < n; ++i) {
            long long x;
            cin >> x;
            monsters.insert(x);
        }
        long long total_damage= 0;
        long long times = 0;
        auto it = prev(monsters.end());
        while(*it > total_damage && it != monsters.begin())
        {
            monsters.erase(it);
            it = prev(monsters.end());
            times++;
            total_damage+=r;
        }
        if(it == monsters.begin() && *it > total_damage){times++;}
        cout << times << endl;
    }
    return 0;
}