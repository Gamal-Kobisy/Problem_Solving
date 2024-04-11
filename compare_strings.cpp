#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int out = 0;
    string s1, s2;
    cin >> s1 >> s2;
    for (char &c : s1)
    {
        c = tolower(c);
    }
    for (char &c : s2)
    {
        c = tolower(c);
    }
    for (int i = 0; i < s1.size(); i++)
    {
        if (s1[i] != s2[i])
        {
            out = -1;
            break;
        }
    }
    cout << out << "\n";
    return 0;
}