// https://vjudge.net/contest/585111#problem/Q

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
    string s;
    cin >> s;
    set<char> ss;
    for (char c : s)
    {
        ss.insert(c);
    }
    cout << (ss.size() % 2 == 0 ? "CHAT WITH HER!\n" : "IGNORE HIM!\n");

    return 0;
}