#include <bits/stdc++.h>
using namespace std;


int main ()
{
    int t ;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;
        vector <long long > candies(n);
        for (int j = 0; j < n; ++j) {
            cin >> candies[j];
        }
        long long min = *min_element(candies.begin() , candies.end());
        long long deleted = 0;
        for (int j = 0; j < n; ++j) {
            deleted += (candies[j] - min);
        }
        cout << deleted << "\n";
    }

    return 0;
}