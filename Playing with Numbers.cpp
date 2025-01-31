// LINK : https://vjudge.net/problem/Gym-479619G
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


int main ()
{
    char temp;
    bool first = true;
    string num ;
    cin >> num;
    if (num.size() == 2)
    {
        temp = num[0];
        num[0]=num[1];
        num[1] = temp;
    }
    else if (num.size() == 1)
    {
        cout << num;
        return 0;
    }
    else
    {
        reverse(num.begin() , num.end());
    }

    for(int i = 0 ;  i < num.size() ; i++ )
    {
        if (num[i] == '0' && first)
            continue;

        cout << num[i];
        first = false;
    }



    return 0;
}
