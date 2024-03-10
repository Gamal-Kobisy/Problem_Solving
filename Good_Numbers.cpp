#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    long long num;
    cin >> num;
    for (long long i = 1; i <= num; i++)
    {
        if (num % i == 0)
            cout << i << " ";
    }
}