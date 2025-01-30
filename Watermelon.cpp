#include <iostream>
#include <deque>
// Link : https://codeforces.com/contest/4/problem/A
using namespace std;
int main()
{
    long long n;
    cin >> n;
    cout << (n % 2 == 0 && n > 2 ? "YES\n" : "NO\n");
}