#include <iostream>
#include <climits>
using namespace std;

int main()
{
    long long t;
    cin >> t;
    long long minutes[t];
    long long price[t];
    long long games[t];
    long long minn = LLONG_MAX;
    for (int i = 0; i < t; i++)
    {
        cin >> minutes[i] >> price[i] >> games[i];
    }
    for (int i = 0; i < t; i++)
    {
        (minutes[i] < games[i]) ? minn = min(minn, price[i]) : minn;
    }
    (minn == LLONG_MAX) ? cout << -1 << "\n" : cout << minn << "\n";
}