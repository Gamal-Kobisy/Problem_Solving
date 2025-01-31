// LINK : https://vjudge.net/problem/Gym-481102L
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    long long n, vowles = 0;
    cin >> n;
    vector<char> word(n);
    for (int i = 0; i < n; i++)
    {
        cin >> word[i];
    }
    for (char c : word)
    {
        if (int(c) == 65 || int(c) == 69 || int(c) == 73 || int(c) == 79 || int(c) == 85 || int(c) == 97 || int(c) == 101 || int(c) == 105 || int(c) == 111 || int(c) == 117)
        {
            vowles += 1;
        }
    }
    cout << vowles;
}