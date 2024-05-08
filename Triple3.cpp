// https://vjudge.net/contest/589621#problem/S
#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <iterator> // For std::begin and std::end
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
        long long Frequency[n + 1] = {0};
        for (int i = 0; i < n; i++)
        {
            cin >> num[i];
            Frequency[num[i]]++;
            if (Frequency[num[i]] >= 3)
            {
                result = num[i];
            }
        }
        cout << result << "\n";
    }

    return 0;
}
