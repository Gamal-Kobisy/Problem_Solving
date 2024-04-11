#include <iostream>

using namespace std;

int main()
{
    long long N;
    cin >> N;
    long long sum = 0;
    for (long long i = 1; sum < N; i++)
    {
        sum += i;
        if (sum >= N)
        {
            cout << i << "\n";
        }
    }

    return 0;
}