#include <bits/stdc++.h>
using namespace std;


int main ()
{
    long long t ;
    cin >> t;
    for (long long i = 0; i < t; ++i) {
        vector <long long> ran;
        for (int j = 0; j < 4; ++j) {
            long long x;
            cin >> x;
            ran.push_back(x);
        }
        long long counter = 0;
        for (int j = 1; j < 4; ++j) {
            if(ran[0] < ran[j])
            {counter++;}
        }
        cout << counter << "\n";
    }

    return 0;
}