// https://vjudge.net/contest/585111#problem/E
#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <deque>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    deque<int> d(4);
    deque<int> sums3_1(301, 0);
    deque<int> sums2_2(201, 0);

    int sum = 0;

    for (int i = 0; i < 4; i++)
    {
        cin >> d[i];
        sums3_1[d[i]]++;
        sum += d[i];
    }

    if (sum % 2 == 1)
    {
        cout << "NO\n";
        return 0;
    }
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (sum - d[j] == d[i])
            {
                cout << "YES\n";
                return 0;
            }
        }
    }
    for (int i = 0; i < 4; i++)
    {
        for (int j = i + 1; j < 4; j++)
        {
            if (d[i] + d[j] == sum / 2)
            {
                cout << "YES" << endl;
                return 0;
            }
        }
    }
    cout << "NO\n";
    return 0;
}