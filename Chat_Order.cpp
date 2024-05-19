//
// Created by Gamal on 5/16/2024.
// https://vjudge.net/contest/585111#problem/AD
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
struct un_ordered
{
    bool operator()(const string &a, const string &b) const
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
    map<string , long long>name_freq;
    deque<string> result;
    set<string , un_ordered>set1;
    long long order = 0;
    while (t--) {
        string name;
        cin >> name;
        name_freq[name]++;
        result.push_front(name);
    }
    for (const auto &item: result) {
        if(name_freq[item] == 0)
        {
            continue;
        }
        else
        {
            name_freq[item] = 0;
            cout << item << endl;
        }
    }
}