// https://vjudge.net/contest/585111#problem/N

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
    map<string, long long> m;
    for (long long i = 0; i < n; i++)
    {
        string name;
        cin >> name;
        if (m[name] == 0)
        {
            cout << "OK\n";
        }
        else
        {
            cout << name << m[name] << endl;
        }
        m[name]++;
    }

    return 0;
}
