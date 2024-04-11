#include <bits/stdc++.h>
using namespace std;


int main ()
{
    int t ;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        int n, nn;
        cin >> n >> nn;
        vector<string> candies(n);
        vector<long long> diffrence;
        for (int j = 0; j < n; ++j) {
            cin >> candies[j];
        }
        for (int j = 0; j < n; ++j) {
            for (int k = j; k < n; ++k) {
                if(j == k)
                { continue;}
                long long dif = 0;
                for (int l = 0; l < nn; ++l) {
                    dif += abs(candies[k][l] - candies[j][l]);
                }
                diffrence.push_back(dif);
            }
        }
        long long min = *min_element(diffrence.begin(),diffrence.end());
        cout << min << "\n";
    }
    return 0;
}