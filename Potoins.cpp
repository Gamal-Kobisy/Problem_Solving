//
// Created by Gamal on 5/15/2024.
// https://vjudge.net/contest/585111#problem/V
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
priority_queue<int> pq;
    long long health = 0, x, n;
    cin >> n;
    while (n--)
    {
        cin >> x;
        health += x;
        pq.push(-x);
        while (health < 0)
        {
            health += pq.top();
            pq.pop();
        }
    }
    cout << pq.size() << endl;

    return 0;
}