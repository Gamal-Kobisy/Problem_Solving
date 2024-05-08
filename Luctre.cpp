// https://vjudge.net/contest/585111#problem/I

#include <iostream>
#include <string>
#include <map>
#include <deque>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    map<string, string> mm;
    int n, m;
    cin >> n >> m;
    while (m--)
    {
        string frst, scnd;
        cin >> frst >> scnd;
        mm[frst] = scnd;
    }
    while (n--)
    {
        string s;
        cin >> s;
        if (s.size() <= mm[s].size())
        {
            cout << s << " ";
        }
        else
        {
            cout << mm[s] << " ";
        }
    }
    cout << endl;
    return 0;
}

/*
dog ogday
cat atcay
pig igpay
froot ootfray
loops oopslay

atcay
ittenkay
oopslay
*/
