#include <iostream>

using namespace std;

int main()
{
    long long N, S, D;
    cin >> N >> S >> D;
    long long time[N];
    long long power[N];
    for (long long i = 0; i < N; i++)
    {
        cin >> time[i] >> power[i];
    }
    for (long long i = 0; i < N; i++)
    {
        if (time[i] < S && power[i] > D)
        {
            cout << "Yes\n";
            return 0;
        }
    }
    cout << "No\n";
    return 0;
}