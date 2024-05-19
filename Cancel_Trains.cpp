//
// Created by Gamal on 5/15/2024.
// https://vjudge.net/contest/585111#problem/W
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
    int t;
    cin>>t;
    while (t--)
    {
        int n , m;
        cin >> n >> m;
        map<int,int> trains;
        for (int i = 0; i < n + m; ++i) {
            int train ;
            cin >> train;
            trains[train]++;
        }
        int canceled_train = count_if(trains.begin() , trains.end() , [&](pair<int,int> x){return 1 < x.second;});
        cout << canceled_train << endl;
    }
    return 0;
}
