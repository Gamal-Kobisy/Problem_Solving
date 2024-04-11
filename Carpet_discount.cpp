#include <bits/stdc++.h>
using namespace std;


int main ()
{
     float price = 2.75 , discount = 0.15;
     int meters ;
     cin >> meters;
     float total =  meters * price;
     float discounted = max(0 , meters - 10) * price * discount;
     cout << total - discounted;
    return 0;
}