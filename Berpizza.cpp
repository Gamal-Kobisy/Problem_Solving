// https://vjudge.net/contest/585111#problem/U
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
using ordered_set = tree<T, null_type, un_ordered, rb_tree_tag, tree_order_statistics_node_update>;
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif
    long long t;
    set <pair<long long , long long>>customers ;
    set <pair<long long , long long>>customers_reverse ;
    vector<long long>leavers;
    map <long long , long long>m;
    cin >> t;
    long long order = 0;
    for (long long i = 1; i <= t ; ++i) {
        int x;
        cin >> x;
        if(x == 1)
        {
            order++;
            long long money;
            cin >> money;
            customers.insert(make_pair(money , -order));
            customers_reverse.insert(make_pair(order , money));

        }
        else if (x == 2)
        {
            leavers.push_back((customers_reverse.begin()->first));
            customers.erase(make_pair(customers_reverse.begin()->second , -customers_reverse.begin()->first));
            customers_reverse.erase(customers_reverse.begin());

        }
        else if( x == 3)
        {
            auto it = customers.end();
            --it;
            leavers.emplace_back(-it->second);
            customers_reverse.erase(make_pair(-it->second , it->first));
            customers.erase(it);
        }
    }
    for (auto leaver: leavers) {
        cout << leaver << " ";
    }
    cout << endl;
    return 0;
}