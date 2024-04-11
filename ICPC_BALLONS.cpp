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
        int x, count = 0;
        cin >> x;
        int alph[26] = {0};
        string problems;
        cin >> problems;
        for (int i = 0; i < x; i++)
        {
            alph[problems[i] - 'A']++;
        }
        for (int j = 0; j < 26; j++)
        {
            if (alph[j] != 0)
            {
                count += (alph[j] + 1);
            }
        }
        cout << count << endl;
    }
    return 0;
}