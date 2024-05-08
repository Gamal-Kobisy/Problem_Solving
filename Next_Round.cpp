// https://codeforces.com/problemset/problem/158/A
#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    int m = n;
    int counter = 0;
    int sum = 0;
    int x;

    while (n--)
    {
        cin >> x;
        sum += x;
        if (x > k)
        {
            counter++;
        }
    }
    if (sum / m == k)
    {
        cout << m << endl;
    }
    else
    {
        cout << counter << endl;
    }
}