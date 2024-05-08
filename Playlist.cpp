// https://codeforces.com/gym/102961/problem/M
#include <iostream>
#include <map>
#include <deque>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    long long n;
    cin >> n;

    deque<long long> d(n);
    map<long long, long long> lastIndex;

    long long max_size = 0;
    long long start_index = 0;
    for (long long i = 0; i < n; i++)
    {
        cin >> d[i];
        if (lastIndex.find(d[i]) != lastIndex.end() && lastIndex[d[i]] >= start_index)
        {
            max_size = max(max_size, i - start_index);
            start_index = lastIndex[d[i]] + 1;
        }
        lastIndex[d[i]] = i;
    }
    max_size = max(max_size, n - start_index);

    cout << max_size << endl;

    return 0;
}
