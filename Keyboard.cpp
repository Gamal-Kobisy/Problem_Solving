// https://vjudge.net/contest/585111#problem/R

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
    string s = "qwertyuiopasdfghjkl;zxcvbnm,./";
    char action;
    cin >> action;
    map<char, char> m;
    if (action == 'R')
    {
        for (int i = 1; i < s.size(); i++)
        {
            m[s[i]] = s[i - 1];
        }
    }
    else if (action == 'L')
    {
        for (int i = 0; i < s.size() - 1; i++)
        {
            m[s[i]] = s[i + 1];
        }
    }
    string keyboard;
    cin >> keyboard;
    for (char c : keyboard)
    {
        cout << m[c];
    }
    cout << endl;
    return 0;
}