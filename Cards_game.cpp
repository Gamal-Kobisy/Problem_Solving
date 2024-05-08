// https://vjudge.net/contest/600165#problem/D
#include <iostream>
#include <string>

using namespace std;

int main()
{
    int t;
    cin >> t;
    int cards[t];
    for (int x = 0; x < t; x++)
    {
        cin >> cards[x];
    }
    bool sereja_turn = true;
    int left = 0;
    int right = t - 1;
    int sereja_sum = 0, dima_sum = 0;
    while (left <= right)
    {
        if (sereja_turn)
        {
            if (cards[left] >= cards[right])
            {
                sereja_sum += cards[left];
                left++;
            }
            else
            {
                sereja_sum += cards[right];
                right--;
            }
            sereja_turn = false;
        }
        else
        {
            if (cards[left] >= cards[right])
            {
                dima_sum += cards[left];
                left++;
            }
            else
            {
                dima_sum += cards[right];
                right--;
            }
            sereja_turn = true;
        }
    }
    cout << sereja_sum << " " << dima_sum;

    return 0;
}