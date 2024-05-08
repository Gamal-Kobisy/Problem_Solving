// https://vjudge.net/contest/585111#problem/J

#include <iostream>
#include <string>
#include <map>
#include <deque>
#include <unordered_set>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    map<long long, long long> nums;
    deque<long long> s;
    long long num;
    while (cin >> num)
    {
        if (nums[num] == 0)
        {
            s.push_back(num);
        }
        nums[num]++;
    }
    for (long long i : s)
    {
        cout << i << " " << nums[i] << endl;
    }
    // 3 1 2 2 1 3 5 3 3 2

    return 0;
}
