//
// Created by Gamal on 5/16/2024.
// https://vjudge.net/contest/585111#problem/AA
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
    set<long long , less_equal<>> os;
    vector<string> operations;
    for (long long i = 0; i < t; ++i) {
        string operation;
        cin >> operation;
        if(operation == "insert")
        {
            long long num;
            cin >> num;
            os.insert(num);
            string op = operation + " " + to_string(num);
            operations.push_back(op);
        }
        else if(operation == "removeMin")
        {
            if(os.empty())
            {
                os.insert(0);
                operations.push_back("insert 0");
            }
            os.erase(os.begin());
            operations.push_back(operation);
        }
        else
        {
            long long num ;
            cin >> num;
            if(os.empty())
            {
                os.insert(num);
                operations.push_back("insert " + to_string(num));
            }
            while (*os.begin() < num && !os.empty()) {
                operations.push_back("removeMin");
                os.erase(os.begin());
            }
            if(num != *os.begin())
            {
                os.insert(num);
                operations.push_back("insert " + to_string(num));
            }
            operations.push_back(operation + " " + to_string(num));
        }

    }
    cout << operations.size() << endl;
    for (const auto &operation: operations) {
        cout << operation << endl;
    }
    return 0;
}