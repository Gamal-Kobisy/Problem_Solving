//
// Created by Gamal on 3/13/2024.
//
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
int rec(int n, int m)
{
    if (n <= m)
    {
        return 1;
    }
    return rec(ceil(n / 2.0), m) + rec(floor(n / 2.0), m);
}
int main()
{
    long long int n, m;
    while (cin >> n >> m)
    {

        long long int x = pow(2, ceil(log2((n + m - 1) / m)));
        // cout << log2((n + m) / m) << endl;
        // cout << log2((2 * (n + m - 1)) / (m)) << endl;
        // cout << ceil(log2((n + m - 1) / m)) << endl;
        // cout << pow(2, ceil(log2((n + m - 1) / m))) << endl;
        // cout << pow(2, (floor(log2((2 * (n + m - 1)) / (m))))) << endl;

        long long int res = max(1ll, x / 2);
        if (2 * n / x == m)
        {
            res += (n - m * x / 2);
        }
        else
        {
            res += (x / 2);
        }
        cout << res << endl;
    }
    return 0;
}
