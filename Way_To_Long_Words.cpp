#include <iostream>
#include <deque>
#include <string>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        (s.size() > 10) ? cout << s[0] << s.size() - 2 << s[s.size() - 1] << "\n" : cout << s << "\n";
    }
}