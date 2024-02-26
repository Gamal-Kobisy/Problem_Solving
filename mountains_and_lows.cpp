#include <iostream>
#include <vector>
using namespace std;
int main ()
{
    int mountains = 0 , lows = 0 , n;
    cin >> n;
    vector <int> land(n) ;
    for (int i = 0 ; i < n ; i++ )
    {
        cin >> land[i];
    }
    for (int i = 1 ; i < n-1 ; i++ )
    {
        if(land[i-1]<land[i] && land[i]>land[i+1])
            mountains += 1;
        if(land[i-1]>land[i] && land[i]<land[i+1])
            lows += 1;
    }
cout << mountains << " " << lows;

//1 4 3 5 1 1


    return 0;
}