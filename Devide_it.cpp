#include <iostream>

using namespace std;

int main()
{
    long long n;
    int q;
    cin >> q;
    for (int j = 0; j < q; j++)
    {
        cin >> n;
        long long n_copy = n;
        int i = 0;
        while (n != 1)
        {
            if((n % 2 == 0) || (n % 3 == 0) || (n % 5 == 0))
            {
                if (n % 2 == 0)
                    n_copy = (n / 2);
                if (n % 3 == 0)
                    n_copy = (2 * n / 3);
                if (n % 5 == 0)
                    n_copy = (4 * n / 5);
                n = n_copy;
            }

            else
                break;
            i++;
        }
        (n == 1) ? cout << i << "\n" : cout << -1 << "\n";
    }
}