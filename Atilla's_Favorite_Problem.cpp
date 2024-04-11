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
        string s;
        cin >> s;
        char maxx = s[0];
        for (int i = 0; i < x; i++)
        {
            maxx = max(maxx, s[i]);
        }
        cout << maxx - '`' << endl;
    }
    return 0;
}