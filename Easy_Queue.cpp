#include <iostream>
#include <deque>
using namespace std;

int main()
{
    iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    deque<long long> v;
    long long x, y, z;
    cin >> x;
    for (int i = 0; i < x; i++)
    {
        cin >> y;
        if (y == 1)
        {
            cin >> z;
            v.push_back(z);
        }
        else if (y == 2)
        {
            if (v.empty() == false)
            {
                v.pop_front();
            }
        }
        else if (y == 3)
        {
            if (v.empty() == true)
            {
                cout << "Empty!"
                     << "\n";
            }
            else
            {
                cout << v.front() << "\n";
            }
        }
    }
}