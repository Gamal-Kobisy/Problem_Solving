// https://vjudge.net/contest/583343#problem/F

#include <string>
#include <iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int op = 0;
        int cl = 0;
        int qus = 0;
        if (s.length() % 2 != 0 || s.front() == ')' || s.back() == '(')
        {
            cout << "NO\n";
        }
        else
        {
            for (int i = 0; i < s.length(); i++)
            {
                if (s[i] == '(')
                {
                    op++;
                }
                else if (s[i] == ')')
                {
                    cl++;
                }
                else
                {
                    qus++;
                }
            }
            if (((op - cl) + qus) % 2 == 0)
            {
                cout << "YES\n";
            }
            else
            {
                cout << "NO\n";
            }
        }
    }

    return 0;
}