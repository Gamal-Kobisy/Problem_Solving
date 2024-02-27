#include <iostream>
#include <deque>
using namespace std;
int main()
{
    long long n;
    cin >> n;
    deque<char> queue(n);
    deque<int> again;
    for (int i = 0; i < n; i++)
    {
        cin >> queue[i];
    }
    for (int i = 1; i < n; i++)
    {
        if (queue[i] == queue[i - 1])
        {
            again.push_front(i);
        }
    }
    for (int i : again)
    {
        queue.erase(queue.begin() + i);
    }
    for (int i = 0; i < n - again.size(); i++)
    {
        cout << queue[i];
    }
}