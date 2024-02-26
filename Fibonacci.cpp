#include <iostream>
#include <vector>
using namespace std;
int main ()
{
    vector <int> fibonacci = {0,1,1};
    int n ;
    cin >> n;
    for (int i = 3 ; i < n ; i++ )
    {
        int x = fibonacci.size();
        fibonacci.push_back(fibonacci[x-1]+fibonacci[x-2]);
    }
    for (int i = 0 ; i < n ; i++)
    {
        cout << fibonacci[i] << " ";
    }


    return 0;
}