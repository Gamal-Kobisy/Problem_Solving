// https://vjudge.net/contest/583343#problem/G

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
        int balance1 = 0, move = 0, balance2 = 0;
        for (char i : s)
        {
            if (i == '(')
            {
                balance1++;
            }
            else if (i == '[')
            {
                balance2++;
            }
            else if (i == ')' && balance1 > 0)
            {
                balance1--;
                move++;
            }
            else if (i == ']' && balance2 > 0)
            {
                balance2--;
                move++;
            }
        }
        cout << move << "\n";
    }

    return 0;
}