// https://vjudge.net/contest/583343#problem/P

#include <iostream>
#include <deque>

using namespace std;

int main()
{
    int n;
    cin >> n;
    deque<int> d(n);
    for (int i = 0; i < n; i++)
    {
        cin >> d[i];
    }
    int sereja_score = 0, dimma_score = 0;
    int x;
    for (int i = 0; i < n; i++)
    {
        if (d.front() > d.back())
        {
            x = d.front();
            d.pop_front();
        }
        else
        {
            x = d.back();
            d.pop_back();
        }
        (i % 2 == 0) ? sereja_score += x : dimma_score += x;
    }
    cout << sereja_score << " " << dimma_score << "\n";

    return 0;
}