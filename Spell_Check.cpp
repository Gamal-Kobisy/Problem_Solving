#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{

    int t;
    cin >> t;
    for (int k = 0; k < t; k++)
    {
        int T = 0, i = 0, m = 0, u = 0, r = 0, x;
        cin >> x;
        string name;
        cin >> name;
        for (int j = 0; j < x; j++)
        {
            if (name[j] == 'T')
            {
                T++;
            }
            else if (name[j] == 'i')
            {
                i++;
            }
            else if (name[j] == 'm')
            {
                m++;
            }
            else if (name[j] == 'u')
            {
                u++;
            }
            else if (name[j] == 'r')
            {
                r++;
            }
            else
            {
                break;
            }
        }
        (T == 1 && i == 1 && m == 1 && u == 1 && r == 1 && x == 5) ? cout << "YES\n" : cout << "NO\n";
    }
    return 0;
}