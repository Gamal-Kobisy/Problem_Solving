#include <iostream>
#include <vector>
using namespace std;
int main ()
{
    int n;
    bool palindorme;
    cin >> n;
    vector <char> array (n);
    for (int i = 0 ; i < n ; i++)
    {
        cin >> array[i];
    }
    for (int i = 0 ; i < (n/2) ; i++)
    {
        if (array[i] == array[(n-1)-i])
        {
            palindorme = true;
        }
        else
        {
            palindorme = false;
            break;
        }
    }
    (palindorme) ? cout << "YES" : cout << "NO";



    return 0;
}