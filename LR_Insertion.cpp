// https://vjudge.net/contest/583343#problem/L
#include <iostream>
#include <list>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    long long t;
    cin >> t;
    list<long long> d = {0};
    string s;
    cin >> s;
    auto it = d.begin();

    for (long long i = 0; i < t; i++)
    {
        if (s[i] == 'L')
        {
            it = d.insert(it, i + 1);
        }
        else
        {
            ++it;
            it = d.insert(it, i + 1);
        }
    }
    long long sz = d.size();
    for (long long i : d)
    {
        cout << i << " ";
    }

    return 0;
}
