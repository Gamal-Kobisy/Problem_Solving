// https://vjudge.net/contest/585111#problem/O

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
    long long n;
    cin >> n;
    while (n--)
    {
        string s;
        cin >> s;
        set<char> ss;
        long long days = 1;
        for (long long i = 0; i < s.size(); i++)
        {
            if (ss.size() < 3)
            {
                ss.insert(s[i]);
            }
            else if (ss.count(s[i]) == 1)
            {
                ss.insert(s[i]);
            }
            else
            {
                ss.clear();
                ss.insert(s[i]);
                days++;
            }
        }
        cout << days << endl;
    }

    return 0;
}
