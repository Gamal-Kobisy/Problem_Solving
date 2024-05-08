// https://vjudge.net/contest/583343#problem/I

#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

int main()
{

    iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n = -1;
    vector<long long> v;
    while (true)
    {
        cin >> n;
        if (n == 0)
        {
            break;
        }
        deque<int> cards(n, 0);
        for (int i = 0; i <= n; i++)
        {
            cards[i] += i + 1;
        }
        cout << "Discarded cards:";
        if (n == 1)
        {
            cout << "\n";
        }
        else
        {
            cout << " ";
        }
        for (int i = 0; i < n - 1; i++)
        {
            cout << cards[0] << (i == n - 2 ? "\n" : ", ");
            cards.pop_front();
            cards.push_back(cards.front());
            cards.pop_front();
        }
        cout << "Remaining card: " << cards[0] << "\n";
    }

    return 0;
}