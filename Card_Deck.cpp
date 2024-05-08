// https://vjudge.net/contest/583343#problem/C
#include <iostream>
#include <deque>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    long long sz, q;
    cin >> sz >> q;
    deque<int> v(sz);
    for (long long i = 0; i < v.size(); i++)
    {
        cin >> v[i];
    }
    for (int i = 0; i < q; i++)
    {
        int x;
        cin >> x;
        auto it = find(v.begin(), v.end(), x);
        cout << it - v.begin() + 1 << " ";
        v.erase(it);
        v.push_front(x);
    }
    cout << endl;
}