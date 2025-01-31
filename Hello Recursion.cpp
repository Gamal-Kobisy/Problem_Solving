// LINK : https://vjudge.net/problem/SPOJ-HRECURS
#include <iostream>
#include <string>

using namespace std;

int recursive_sum(int arr[], int i, int x)
{
    if (i == x)
    {
        return 0;
    }
    int result = arr[i] + recursive_sum(arr, i + 1, x);
    return result;
}

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int x;
        cin >> x;
        int arr[x];
        for (int j = 0; j < x; j++)
        {
            cin >> arr[j];
        }
        cout << "Case " << i + 1 << ": " << recursive_sum(arr, 0, x) << "\n";
    }

    return 0;
}