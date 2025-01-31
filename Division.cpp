// LINK : https://vjudge.net/problem/CodeForces-1669A
#include <iostream>

using namespace std;

int main()
{
    long long t, rating;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> rating;
        if (rating >= 1900)
        {
            cout << "Division 1\n";
        }
        else if (1600 <= rating && rating <= 1899)
        {
            cout << "Division 2\n";
        }
        else if (1400 <= rating && rating <= 1599)
        {
            cout << "Division 3\n";
        }
        else if (rating <= 1399)
        {
            cout << "Division 4\n";
        }
    }
}