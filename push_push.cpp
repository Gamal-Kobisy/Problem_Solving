// https://vjudge.net/contest/583343#problem/M
#include <iostream>
#include <deque>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    long long t;
    cin >> t;
    deque<long long> d;
    int mod = (t % 2 != 0);
    for (long long i = 0; i < t; i++)
    {
        int x;
        cin >> x;
        (i % 2 == mod) ? d.emplace_back(x) : d.emplace_front(x);
    }
    for (long long i = 0; i < t; i++)
    {
        cout << d[i] << (i == t - 1 ? "\n" : " ");
    }

    return 0;
}
