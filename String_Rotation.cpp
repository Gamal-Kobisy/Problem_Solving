// https://vjudge.net/contest/583343#problem/O
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
    string str1, str2;
    cin >> str1 >> str2;
    long long sz = str1.size();
    deque<char> s1(sz), s2(sz);
    for (int i = 0; i < sz; i++)
    {
        s1[i] = str1[i];
        s2[i] = str2[i];
    }
    bool valid = false;
    for (int i = 0; i < 100; i++)
    {
        if (s1 == s2)
        {
            valid = true;
            break;
        }
        s1.push_front(s1.back());
        s1.pop_back();
    }
    cout << (valid ? "Yes\n" : "No\n");
}