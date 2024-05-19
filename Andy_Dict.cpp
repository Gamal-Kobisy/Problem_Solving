// https://vjudge.net/contest/585111#problem/D

#include <iostream>
#include <queue>
#include <string>
#include <set>
#include <fstream>
using namespace std;

struct CompareStrings
{
    bool operator()(string &a, string &b) const
    {
        string s1 = " ", s2 = " ";
        for (char &c : a)
        {
            if (isalpha(c))
            {
                s1 += tolower(c);
            }
        }
        a = s1;
        for (char &c : b)
        {
            if (isalpha(c))
            {
                s2 += tolower(c);
            }
        }
        b = s2;
        return a > b;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    priority_queue<string, vector<string>, CompareStrings> mm;
    string s = " ";
    ifstream in("text.txt");
    ofstream out("out.txt");
    while (in >> s)
    {
        mm.push(s);
    }
    string prev = " ";
    while (!mm.empty())
    {
        auto cur = mm.top();
        mm.pop();
        if (prev != cur)
        {
            out << cur << "\n";
            prev = cur;
        }
    }

    return 0;
}
