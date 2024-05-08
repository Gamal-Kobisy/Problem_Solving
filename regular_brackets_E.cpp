// https://vjudge.net/contest/583343#problem/E
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

    string s;
    cin >> s;
    int balance = 0;
    int move = 0;
    for (long long i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
        {
            balance++;
        }
        else
        {
            if (balance > 0)
            {
                balance--;
            }
            else
            {
                move++;
            }
        }
    }
    cout << s.size() - move - balance << '\n';
}