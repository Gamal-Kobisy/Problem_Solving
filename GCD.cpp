#include <bits/stdc++.h>
using namespace std;

int findGCF(int num1, int num2)
{
    int mininum = min(num1, num2);
    for (int i = mininum; i >= 1; i--)
    {
        if ((num1 % i == 0) && (num2 % i == 0))
        {
            return i;
        }
    }
    return 1;
}

int main ()
{
    long long t ;
    cin >> t;
    for (long long i = 0; i < t; ++i) {
        iostream::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
        bool isbreak = false;
        vector <string> pairs;
        vector <long long> dif;
        long long a , b;
        cin >> a >> b;
        cin.ignore();
        if(abs(a-b) == 1)
        {
            for (int j = b; j >= a ; j--) {
                for (int k = a; k <= b ; k++) {

                    if(findGCF(k , j) >= a && !isbreak) {
                        cout << k << " " << j << "\n";
                        isbreak = true;
                        break;
                    }
                    if(isbreak)
                        break;
                }
            }
        }
        else
        {
            for (int j = b; j > a ; j--) {
                for (int k = a; k < b ; k++) {

                    if(findGCF(k , j) >= a && !isbreak) {
                        cout << k << " " << j << "\n";
                        isbreak = true;
                        break;
                    }
                    if(isbreak)
                        break;
                }
            }
        }
    }
    cout << "\n";


    return 0;
}