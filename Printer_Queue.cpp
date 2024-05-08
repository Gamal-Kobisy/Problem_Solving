// https://vjudge.net/contest/583343#problem/J

#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <utility>
#include <queue>

using namespace std;

int main()
{

    iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        queue<pair<int, int>> q;
        priority_queue<int> pq;
        for (int i = 0; i < n; i++)
        {
            int job;
            cin >> job;
            q.push({job, i});
            pq.push(job);
        }
        int time = 0;
        while (!pq.empty())
        {
            auto job = q.front();
            q.pop();
            if (job.first == pq.top())
            {
                time++;
                pq.pop();
                if (job.second == m)
                {
                    cout << time << endl;
                    break;
                }
            }
            else
            {
                q.push(job);
            }
        }
    }

    return 0;
    /*
    3
 1 0
 5
 4 2
 1 2 3 4
 6 0
 1 1 9 1 1 1
    */
}