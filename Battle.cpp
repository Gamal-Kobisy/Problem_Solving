#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    float a, b, c, d;
    cin >> a >> b >> c >> d;
    int takashi = ceil(c / b);
    int aoki = ceil(a / d);
    (takashi <= aoki) ? cout << "Yes\n" : cout << "No\n";
}