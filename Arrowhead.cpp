// LINK : https://vjudge.net/problem/Gym-479619K
#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int main()
{
    long long n;
    string star = "*";
    cin >> n;
    for (long long i = 1; i <= n; i++)
    {
        cout << star << "\n";
        (n / 2 >= i) ? star += "*" : star = star.substr(0, star.length() - 1);
    }
}