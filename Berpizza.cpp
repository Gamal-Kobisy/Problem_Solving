// https://vjudge.net/contest/585111#problem/T

#include <iostream>
#include <iomanip>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

struct un_ordered
{
    bool operator()(const long long &a, const long long &b) const
    {
        return true;
    }
};

template <class T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main()
{
     ios_base::sync_with_stdio(false);
     cin.tie(nullptr);
     cout.tie(nullptr);

    return 0;
}