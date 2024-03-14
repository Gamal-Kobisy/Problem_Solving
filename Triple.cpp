//
// Created by Gamal on 3/13/2024.
//
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


int main()
{
    long long t;
    cin >> t;
    for(int i = 0 ; i < t ; i++)
    {
        long long n , result = -1;
        cin >> n;
        long long num[n];
        for (int i = 0 ; i < n ; i++ )
        {
            cin >> num[i];
        }
        sort(num , num +n);
        for (int i = 0 ; i < n ; i++)
        {
            if (count(num + i , num + i + 3 , num[i])>=3)
            {
                result = num[i];
                break;
            }

        }
        cout << result << "\n";



    }


    return 0;
}
