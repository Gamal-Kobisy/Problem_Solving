// https://vjudge.net/contest/583343#problem/H

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{

    iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    long long n;
    cin >> n;
    vector<long long> v;
    while (n--)
    {
        int choice;
        cin >> choice;
        if (choice == 1)
        {
            long long x;
            cin >> x;
            v.push_back(x);
        }
        else if (choice == 2)
        {
            v.pop_back();
        }
        else
        {
            cout << *max_element(v.begin(), v.end()) << "\n";
        }
    }

    return 0;
}