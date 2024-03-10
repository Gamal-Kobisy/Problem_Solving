#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n / 2; ++i)
    {
        for (int ii = 0; ii < n; ++ii)
        {
            if (ii == n / 2 - i || ii == n / 2 + i)
                cout << "*";
            if (ii == n / 2 + i)
                break;
            ;
            else
            {
                cout << " ";
            }
            cout << "\n";
        }
    }
    for (int iii = 0; iii < n; ++iii)
    {
        cout << "*";
    }
    return 0;
}