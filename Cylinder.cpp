// https://vjudge.net/contest/583343#problem/S
#include <iostream>
#include <string>
#include <deque>
#include <utility>
using namespace std;

int main()
{
    iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    long long n;
    cin >> n;

    deque<pair<long long, long long>> d;
    for (long long i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (x == 1)
        {
            long long num, times;
            cin >> num >> times;
            d.push_back(make_pair(num, times));
        }
        else
        {
            long long sum = 0, times;
            cin >> times;
            if (d.front().second >= times)
            {
                sum += d.front().first * times;
                d.front().second -= times;
                if (d.front().second == 0)
                {
                    d.pop_front();
                }
            }
            else
            {
                while (times != 0)
                {
                    if (d.front().second < times)
                    {
                        sum += d.front().first * d.front().second;
                        times -= d.front().second;
                        d.pop_front();
                    }
                    else
                    {
                        sum += d.front().first * times;
                        d.front().second -= times;
                        if (d.front().second == 0)
                        {
                            d.pop_front();
                        }
                        break;
                    }
                }
            }

            cout << sum << endl;
        }
    }

    return 0;
}