#include <iostream>

using namespace std;

int main()
{
    int p, q, r;
    cin >> p >> q >> r;
    if (r >= q && r >= p)
    {
        cout << p + q;
    }

    else if (p >= q && p >= r)
    {
        cout << q + r;
    }

    else if (q >= r && q >= p)
    {
        cout << p + r;
    }
}