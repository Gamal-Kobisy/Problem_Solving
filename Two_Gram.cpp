// https://vjudge.net/contest/585111#problem/B

#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

int main()
{
    map<string, int> m;
    for (int i = 0; i < 26; i++)
    {
        for (int ii = 0; ii < 26; ii++)
        {
            m[to_string(('A' + i)) + to_string(('A' + ii))] = 0;
        }
    }
    int x;
    cin >> x;
    string s;
    cin >> s;
    for (int i = 0; i < x - 1; i++)
    {
        string sub = s.substr(i, 2);
        m[sub]++;
    }
    auto max_pair = max_element(m.begin(), m.end(), [](const auto &a, const auto &b)
                                { return a.second < b.second; });
    cout << max_pair->first << "\n";

    return 0;
}