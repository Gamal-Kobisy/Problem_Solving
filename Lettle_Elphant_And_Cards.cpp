// https://vjudge.net/contest/585111#problem/G

#include <iostream>
#include <string>
#include <map>
#include <deque>
#include <utility>
#include <cmath>
#include <algorithm>
#include <limits.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    long long n;
    cin >> n;
    map<long long, long long> front, back;
    for (long long i = 0; i < n; i++)
    {
        long long frst, scnd;
        cin >> frst >> scnd;
        front[frst]++;
        if (frst != scnd)
        {
            back[scnd]++;
        }
    }
    auto it = front.begin();
    auto it_2 = back.begin();
    long long min_moves = LLONG_MAX;
    for (; it != front.end(); it++)
    {
        if (it->second >= ceil(double(n) / 2))
        {
            min_moves = 0;
            break;
        }
        else if (it->second + back[it->first] >= ceil(double(n) / 2))
        {
            min_moves = min(min_moves, (long long)(ceil(double(n) / 2) - it->second));
        }
        if (it_2->second >= ceil(double(n) / 2))
        {
            min_moves = min(min_moves, (long long)ceil(double(n) / 2));
        }
    }
    for (; it_2 != back.end(); it_2++)
    {
        if (it_2->second >= ceil(double(n) / 2))
        {
            min_moves = min(min_moves, (long long)ceil(double(n) / 2));
        }
    }
    if (min_moves == LLONG_MAX)
    {
        min_moves = -1;
    }
    cout << min_moves << endl;
    return 0;
}