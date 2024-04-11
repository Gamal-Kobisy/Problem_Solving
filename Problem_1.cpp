#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int main() {
    long long t = 1;
    cin >> t;

    vector<int> vec(t);

    for (long long i = 0; i < t; ++i) {
        cin >> vec[i];
    }

    sort(vec.begin(), vec.end());

    int sum = 0;
    for (int i = t - 1; i >= ceil(t / 2); i--) {
        sum += vec[i];
    }
    if(t % 2 == 1){sum -= vec[t / 2];}
    cout << sum << "\n";

    return 0;
}
