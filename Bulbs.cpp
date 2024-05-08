// https://vjudge.net/contest/585111#problem/S

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
    set<int> bulbs;
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        bulbs.insert(i);
    }
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        for (int ii = 0; ii < x; ii++)
        {
            int lamp;
            cin >> lamp;
            bulbs.erase(lamp);
        }
    }
    cout << (bulbs.size() > 0 ? "NO\n" : "YES\n");
    return 0;
}