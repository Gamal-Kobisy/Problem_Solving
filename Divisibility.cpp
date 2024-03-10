#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    bool y = false;
    long long n, x;
    cin >> n >> x;
    for (int i = 1; i < n + 1; i++)
    {
        if (i % x == 0)
        {
            cout << i << " ";
            y = true;
        }
        else
            continue;
    }
    if (!y)
    {
        cout << -1;
    }
}