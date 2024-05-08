// https://vjudge.net/problem/CodeForces-1526C2

#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
    priority_queue<int> pq;
    long long health = 0, x, n;
    cin >> n;
    while (n--)
    {
        cin >> x;
        health += x;
        pq.push(-x);
        while (health < 0)
        {
            health += pq.top();
            pq.pop();
        }
    }
    cout << pq.size() << endl;
    return 0;
}