// https://codeforces.com/contest/1888/problem/A
#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <deque>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    long long t;
    cin >> t;
    while (t--)
    {
        deque<long long> alpha(26, 0);
        long long n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        if (n - k == 1)
        {
            cout << "YES\n";
        }
        else
        {
            for (char c : s)
            {
                alpha[c - 'a']++;
            }
            int counter = count_if(alpha.begin(), alpha.end(), [&](int x)
                                   { return x % 2 == 1; });
            // cout << counter << "\n";
            if (counter == k)
            {
                cout << "YES\n";
            }
            else if (counter == 0)
            {
                cout << "YES\n";
            }

            else if (counter < k)
            {
                cout << "YES\n";
            }
            else if (counter > k)
            {
                if (counter - k == 1)
                {
                    cout << "YES\n";
                }
                else
                {
                    cout << "NO\n";
                }
            }
        }
    }

    return 0;
}
