// https://codeforces.com/contest/1945/problem/B
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
        long long sum = 2;
        sum += (ABC[2] / ABC[0] + ABC[2] / ABC[1]);
        cout << sum << endl;
    }
}