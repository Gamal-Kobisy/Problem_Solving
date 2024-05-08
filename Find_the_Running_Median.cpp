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
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("errors.txt", "w", stderr);
#endif
     ios_base::sync_with_stdio(false);
     cin.tie(nullptr);
     cout.tie(nullptr);

    long long n;
    cin >> n;

    ordered_set<long long> os;

    while (n--)
    {
        long long x;
        cin >> x;
        os.insert(x);
        if (os.size() % 2 == 1)
        {
            cout << fixed << setprecision(1) << (long double)*os.find_by_order(os.size() / 2) << endl;
        }
        else
        {
            long double median = (long double)(*os.find_by_order(os.size() / 2) + *os.find_by_order((os.size() - 1) / 2)) / 2.0;
            cout << fixed << setprecision(1) << median << endl;
        }
    }
    return 0;
}

/*
6
12
4
5
3
8
7
*/