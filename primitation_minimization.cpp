// https://vjudge.net/contest/583343#problem/K

#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <utility>
#include <queue>

using namespace std;

int main()
{

    iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        deque<long long> d;
        long long x;
        cin >> x;
        d.push_back(x);
        for (int i = 1; i < n; i++)
        {
            cin >> x;
            (d[0] > x) ? d.push_front(x) : d.push_back(x);
        }
        // auto it_1 = find(d.begin(), d.end(), 1ll);
        // long long temp = *it_1;
        // *it_1 = d[0];
        // d[0] = temp;
        for (int i = 0; i < n; i++)
        {
            cout << d[i] << (i == n - 1 ? "\n" : " ");
        }
    }

    return 0;
}