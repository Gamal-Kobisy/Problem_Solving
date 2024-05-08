// https://vjudge.net/contest/585111#problem/K

#include <iostream>
#include <string>
#include <map>
#include <deque>
#include <set>
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
        long long n;
        cin >> n;
        deque<long long> nums(n);
        set<long long> s;
        for (long long i = 0; i < n; i++)
        {
            cin >> nums[i];
            s.emplace(nums[i]);
        }
        long long minn = s.size();
        for (long long i = 1; i <= n; i++)
        {
            if (i > s.size())
            {
                cout << i << " ";
            }
            else
            {
                cout << minn << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
