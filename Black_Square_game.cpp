// https://vjudge.net/contest/600165#problem/E
#include <iostream>
#include <string>

using namespace std;

int main()
{
    long long calories[4];
    for (int i = 0; i < 4; i++)
    {
        cin >> calories[i];
    }
    string squares;
    cin >> squares;
    int cal_sum = 0;
    for (char &c : squares)
    {
        if (c == '1')
        {
            cal_sum += calories[0];
        }
        else if (c == '2')
        {
            cal_sum += calories[1];
        }
        else if (c == '3')
        {
            cal_sum += calories[2];
        }
        else
        {
            cal_sum += calories[3];
        }
    }
    cout << cal_sum << endl;

    return 0;
}