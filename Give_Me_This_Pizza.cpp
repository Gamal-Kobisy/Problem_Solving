#include <iostream>
#include <deque>
#include <stack>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    long long n;
    cin >> n;
    deque<int> dq;
    for (long long i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        dq.push_back(x);
    }
    deque<int> res;
    stack<int> s;
    for (auto it = dq.rbegin(); it != dq.rend(); ++it)
    {
        while (!s.empty() && *it >= s.top())
        {
            s.pop();
        }
        int next_greater = s.empty() ? -1 : s.top();
        res.push_front(next_greater);
        s.push(*it);
    }
    for (int i : res)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
