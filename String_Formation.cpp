// https://vjudge.net/contest/583343#problem/N
#include <iostream>
#include <deque>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string str;
    cin >> str;
    long long sz = str.size();
    deque<char> s(sz);
    for (int i = 0; i < sz; i++)
    {
        s[i] = str[i];
    }

    long long q;
    cin >> q;
    bool reversed = false;
    while (q--)
    {
        int Ti;
        cin >> Ti;
        if (Ti == 1)
        {
            reversed = !reversed;
        }
        else if (Ti == 2)
        {
            int Fi;
            cin >> Fi;
            char c;
            cin >> c;
            if (Fi == 1)
            {
                (!reversed) ? s.push_front(c) : s.push_back(c);
            }
            else if (Fi == 2)
            {
                (reversed) ? s.push_front(c) : s.push_back(c);
            }
        }
    }
    if (reversed)
    {
        reverse(s.begin(), s.end());
    }
    for (char c : s)
    {
        cout << c;
    }
    cout << endl;
}