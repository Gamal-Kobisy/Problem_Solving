// https://vjudge.net/contest/585111#problem/C
#include <iostream>
#include <queue>
#include <utility>

using namespace std;

struct ComparePairs
{
    bool operator()(const pair<long long, long long> &a, const pair<long long, long long> &b) const
    {
        if (a.first > b.first)
        {
            return true;
        }
        else if (a.first == b.first)
        {
            return a.second < b.second;
        }
        else
        {
            return false;
        }
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, ComparePairs> mm;
        long long n;
        cin >> n;
        for (long long i = 0; i < n; i++)
        {
            long long key, value;
            cin >> key >> value;
            mm.push(make_pair(key, value));
        }
        while (!mm.empty())
        {
            auto it = mm.top();
            mm.pop();
            cout << it.first << " " << it.second << "\n";
        }
    }
    return 0;
}
