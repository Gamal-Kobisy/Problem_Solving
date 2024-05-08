#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_set>
#include <deque>
using namespace std;

int main()
{
    long long x;
    cin >> x;
    string s;
    cin >> s;
    deque<char> deq(26);
    for (int i = 0; i < 26; i++)
    {
        deq[i] = char(i + 'a');
    }
    long long t;
    cin >> t;
    char c1, c2;

    for (long long i = 0; i < t; i++)
    {
        cin >> c1 >> c2;
        for (int ii = 0; ii < 26; ii++)
        {
            if (deq[ii] == c1)
            {
                deq[ii] = c2;
            }
        }
    }
    for (long long i = 0; i < s.size(); i++)
    {
        cout << deq[s[i] - 'a'];
    }

    return 0;
}