// https://vjudge.net/contest/600165#problem/F
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<char> vec_a_to_z;
    for (char c = 'a'; c <= 'z'; ++c)
    {
        vec_a_to_z.push_back(c);
    }

    // Vector from 'z' to 'a'
    vector<char> vec_z_to_a;
    for (char c = 'z'; c >= 'a'; --c)
    {
        vec_z_to_a.push_back(c);
    }
    string word;
    cin >> word;
    int moves = 0;
    int clockwise = 0;
    for (int i = 0; i < 26; i++)
    {
        if ()
    }
    return 0;
}