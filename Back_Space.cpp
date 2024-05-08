// https://vjudge.net/contest/583343#problem/R

#include <iostream>
#include <string>
#include <deque>
#include <algorithm>
using namespace std;

int main()
{
    iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string s;
    deque<char> d;
    cin >> s;
    long long back_space = 0;
    for (int i = s.size() - 1; i >= 0; i--)
    {
        if (s[i] == '<')
        {
            back_space++;
        }
        else if (back_space > 0)
        {
            back_space--;
            continue;
        }
        else
        {
            d.push_front(s[i]);
        }
    }
    
    for (char c : d)
    {
        cout << c;
    }
    cout << endl;

    return 0;
}