#include <bits/stdc++.h>
using namespace std;


int main ()
{
    long long t ;
    cin >> t;
    for (long long i = 0; i < t; ++i) {
        vector<long long> arr;
        long long n;
        cin >> n;
        for (int j = 0; j < n; ++j) {
            long long x;
            cin >> x;
            arr.push_back(x);
        }
        set<int> distinctValues;

        for (int num : arr) {
            distinctValues.insert(num);
        }

        int out = distinctValues.size();
        if((n - out) % 2 ==1 ){out -= 1;}
        cout << out << "\n";
    }

    return 0;
}