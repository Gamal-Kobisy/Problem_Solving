// https://vjudge.net/contest/583343#problem/D
#include <iostream>
#include <deque>
#include <string>
#include <algorithm>
#include <limits.h>
using namespace std;

int main()
{
    iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int x;
        cin >> x;
        string s;
        cin >> s;
        int minn = INT_MAX;
        int v = 0;
        for (char c : s)
        {
            (c == ')') ? v-- : v++;
            minn = min(minn, v);
        }
        cout << abs(minn) << '\n';
    }
}