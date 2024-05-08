// https://vjudge.net/contest/589621#problem/S
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    long long t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        long long n, result = -1;
        cin >> n;
        long long num[n];
        for (int i = 0; i < n; i++)
        {
            cin >> num[i];
        }
        sort(num, num + n);
        for (int i = 0; i < n; i++)
        {
            if (num[i] == num[i + 2])
            {
                result = num[i];
                break;
            }
        }
        cout << result << "\n";
    }

    return 0;
}
