// LINK : https://vjudge.net/problem/HackerRank-ctci-fibonacci-numbers
#include <iostream>
#include <string>

using namespace std;

int fabonacci(int x)
{
    if (x <= 1)
    {
        return x;
    }
    int result = fabonacci(x - 1) + fabonacci(x - 2);
    return result;
}

int main()
{

    int x;
    cin >> x;
    cout << fabonacci(x) << endl;

    return 0;
}