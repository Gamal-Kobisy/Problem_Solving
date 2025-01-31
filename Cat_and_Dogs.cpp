// LINK : https://vjudge.net/problem/AtCoder-abc094_a
#include <iostream>

using namespace std;

int main()
{
    int a, b, x;
    cin >> a >> b >> x;
    (a + b >= x && x >= a) ? cout << "YES\n" : cout << "NO\n";
}