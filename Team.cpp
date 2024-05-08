// https://codeforces.com/problemset/problem/231/A
#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
    int t;
    cin >> t;
    int x = 0;
    while (t--)
    {
        string s;
        cin >> s;
        (s[1] == '+') ? x++ : x--;
    }
    cout << x << endl;
}