// https://vjudge.net/contest/585111#problem

#include <iostream>
#include <set>
#include <cctype>
#include <string>

using namespace std;

int main()
{
    char x;
    string s;

    while (x != '}')
    {
        cin >> x;
        s += x;
    }

    set<char> res;
    for (char c : s)
    {
        if (isalpha(c))
        {
            res.insert(c);
        }
    }
    cout << res.size() << endl;
    return 0;
}