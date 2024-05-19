//
// Created by Gamal on 5/16/2024.
// https://vjudge.net/contest/585111#problem/AC
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
    string statement;
    set<char,less_equal<>> ordered_statement;
    cin >> statement;
    for (auto item: statement) {
        if(item != '+')
        ordered_statement.insert(item);
    }
    auto it = ordered_statement.begin();
    for (long long i = 0; i < ordered_statement.size(); ++i) {
        cout << *(it++) << (i == ordered_statement.size()- 1 ? "\n" : "+" );
    }
    return 0;
}