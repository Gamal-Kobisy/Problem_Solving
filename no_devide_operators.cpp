#include <iostream>
using namespace std;

int main()
{
    int n1, n2, n3, n4, remainder = 0, result = 0;

    // Enter Divided number
    cout << "Please enter the number to divide: ";
    cin >> n1;
    n3 = abs(n1);

    // Enter Divided by number
    cout << "Please enter the number to divide by: ";
    cin >> n2;

    // Must not be zero
    while (n2 == 0)
    {
        cout << "Please enter the number to divide by: ";
        cin >> n2;
    }
    n4 = abs(n2);

    // Get results and reminder
    while (n3 >= n4)
    {
        n3 -= n4;
        result++;
    }
    remainder = n3;

    // Handle -ve cases
    if (n1 < 0 && n2 < 0)
    {
        remainder = -remainder;
    }
    else if (n1 < 0)
    {
        remainder = -remainder;
        result = -result;
    }
    else if (n2 < 0)
    {
        result = -result;
    }
    cout << endl
         << n1 << "/" << n2 << " = " << result << endl;
    cout << n1 << "%" << n2 << " = " << remainder << endl;
}