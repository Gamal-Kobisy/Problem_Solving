// https://vjudge.net/contest/589621#problem/A
#include <iostream>
#include <cmath>
#include <deque>
using namespace std;
int main()
{
    int x;
    cin >> x;
    long long arr[x][x];

    for (int i = 0; i < x; i++)
    {
        arr[i][0] = 1;
        arr[0][i] = 1;
    }
    for (int i = 1; i < x; i++)
    {
        for (int j = 1; j < x; j++)
        {
            arr[i][j] = arr[i - 1][j] + arr[i][j - 1];
        }
    }
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < x; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
