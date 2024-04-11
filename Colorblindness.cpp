#include <iostream>
#include <string>

using namespace std;

int main()
{

    int t;
    cin >> t;
    for (int k = 0; k < t; k++)
    {
        int x;
        cin >> x;
        string line1, line2;
        cin >> line1 >> line2;
        for (int j = 0; j < x; j++)
        {
            if (line1[j] == 'G')
            {
                line1[j] = 'B';
            }
            if (line2[j] == 'G')
            {
                line2[j] = 'B';
            }
        }
        (line1 == line2) ? cout << "YES\n" : cout << "NO\n";
    }
    return 0;
}