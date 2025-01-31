// LINK : https://vjudge.net/problem/Gym-479619D
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    long long begin, end, sum = 0;
    cin >> begin >> end;
    for (long long i = begin; i < end + 1; i++)
    {
        sum += i;
    }
    cout << sum;
}