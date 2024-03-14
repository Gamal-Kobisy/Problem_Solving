//
// Created by Gamal on 3/13/2024.
//
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main()
{
    long long k , n , trucks = 0;
    vector <long long> trucks1 ;
    vector <long long> trucks2 ;


    while(cin >> k >> n)
    {
        long long k1 = k ;
        trucks1.clear();
        trucks2.clear();
        trucks1.push_back(k1);
        trucks2.push_back(k1);

        for (int i = 0 ; k1 > n ; i++ )
        {
            k1 = k1/2;
            for (int j = 0 ; j < i ; j++)
            {
                if (trucks1.back()-j > n)
                trucks1.push_back(trucks1.back()-j);
                if (trucks2.back()-j > n)
                trucks2.push_back(ceil(trucks2.back()-j));
            }
        }
//       while (true)
//        {
//            k1 = k1/2;
//            if (trucks1.back() > n)
//            trucks1.push_back(k1);
//            if (trucks2.back() > n)
//            trucks2.push_back(ceil(k1));
//            if (trucks1.back() <= n && trucks2.back() <= n)
//                break;
//        }
       for(long long truck : trucks1)
        {
            if(truck <= n )
            {
                trucks++;
            }

        }
        for(long long truck : trucks2)        {
            if(truck <= n )
            {
                trucks++;
            }

        }
        cout << trucks*2 << "\n";
        trucks = 0 ;
    }

    return 0;
}
