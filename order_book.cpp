// https://vjudge.net/contest/585111#problem/M

#include <iostream>
#include <string>
#include <map>
#include <deque>
#include <set>
#include <algorithm>
#include <utility>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, ss;
    cin >> n >> ss;
    map<long long, long long> s, b;
    deque<pair<long long, long long>> s2, b2;
    for (long long i = 0; i < n; i++)
    {
        char c;
        long long price, q;
        cin >> c >> price >> q;
        if (c == 'S')
        {
            s[price] += q;
        }
        else if (c == 'B')
        {
            b[price] += q;
        }
    }
    for (auto i : s)
    {
        s2.push_back({i.first, i.second});
    }
    for (auto i : b)
    {
        b2.push_back({i.first, i.second});
    }
    sort(s2.begin(), s2.end());
    sort(b2.rbegin(), b2.rend());
    deque<pair<long long, long long>> dd;
    for (long long i = 0; i < ss && i < s.size(); i++)
    {
        dd.push_back(s2[i]);
    }
    sort(dd.rbegin(), dd.rend());
    for (long long i = 0; i < ss && i < s2.size(); i++)
    {
        cout << "S " << dd[i].first << " " << dd[i].second << endl;
    }
    for (long long i = 0; i < ss && i < b2.size(); i++)
    {
        cout << "B " << b2[i].first << " " << b2[i].second << endl;
    }

    return 0;
}
