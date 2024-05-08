// https://vjudge.net/contest/585111#problem/L

#include <iostream>
#include <string>
#include <map>
#include <deque>
#include <set>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    long long n, m;
    while (true)
    {
        cin >> n >> m;
        if (n == 0 && m == 0)
        {
            break;
        }
        map<long long, long long> mm;
        for (long long i = 0; i < n + m; i++)
        {
            long long x;
            cin >> x;
            mm[x]++;
        }
        long long counter = 0;
        for (auto i : mm)
        {
            if (i.second == 2)
            {
                counter++;
            }
        }
        cout << counter << endl;
    }

    return 0;
}
/*
 3 3
 1
 2
 3
 1
 2
 4
 0 0
*/