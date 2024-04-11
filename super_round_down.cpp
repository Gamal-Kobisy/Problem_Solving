#include <iostream>
#include <string>

using namespace std;

int main()
{
    string num;
    cin >> num;
    for (char c : num)
    {
        if (c == '.')
        {
            cout << "\n";
            break;
        }
        cout << c;
    }

    return 0;
}