// https://codeforces.com/contest/1945/problem/A
#include <iostream>
#include <deque>
#include <cmath>
using namespace std;

int main()
{
    long long t;
    cin >> t;
    while (t--)
    {
        deque<long long> ABC(3);
        for (int i = 0; i < 3; i++)
        {
            cin >> ABC[i];
        }
        long long sum = 0;
        sum += ABC[0];
        bool valid = true;
        while (ABC[1] % 3 != 0)
        {
            if (ABC[2] == 0)
            {
                valid = false;
                break;
            }
            ABC[2]--;
            ABC[1]++;
        }
        if (valid)
        {
            sum += ABC[1] / 3;
            sum += ceil(ABC[2] / 3.0);
            cout << sum << endl;
        }
        else
        {
            cout << -1 << endl;
        }
    }
}