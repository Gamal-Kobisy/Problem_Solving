#include <iostream>
#include <string>

using namespace std;

int main()
{
    long long x;
    cin >> x;
    int arr1[x], arr2[x];
    for (long long i = 0; i < x; i++)
    {
        cin >> arr1[i];
    }
    for (long long i = 0; i < x; i++)
    {
        cin >> arr2[i];
    }
    long long sum = 0;
    for (long long i = 0; i < x; i++)
    {
        sum += arr1[i] * arr2[i];
    }
    (sum) ? cout << "No\n" : cout << "Yes\n";

    return 0;
}