//
// Created by Gamal on 5/16/2024.
// https://vjudge.net/contest/585111#problem/Y

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
    deque<long long> dq;
    ordered_set<long long> os;

    while (t--) {
        int x;
        cin >> x;
        if (x == 1) {
            long long num;
            cin >> num;
            dq.push_back(num);
        } else if (x == 2) {
            long long num;
            if(os.empty())
            {
                num = dq.front();
                dq.pop_front();
            }
            else
            {
                num = *os.begin();
                os.erase(os.find_by_order(os.order_of_key(num)));
            }
            cout << num << endl;
        } else if (x == 3) {
            for (auto &num : dq) {
                os.insert(num);
            }
            dq.clear();
        }
    }

    return 0;
}
