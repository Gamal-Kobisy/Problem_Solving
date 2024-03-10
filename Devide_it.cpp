#include <iostream>

using namespace std;

int main()
{
    long long n;
    int i = 1, q;
    cin >> q;
    for (int j = 0; j < q; j++)
    {
        cin >> n;
        while (n != 1)
        {
            if (n % 2 == 0)
                n = (n / 2);
            if (n % 3 == 0)
                n = (2 * n / 3);
            if (n % 5 == 0)
                n = (4 * n / 5);
            i++;
        }
        (n == 1) ? cout << i << "\n" : cout << -1 << "\n";
    }
}