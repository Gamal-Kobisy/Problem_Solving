// LINK : https://vjudge.net/problem/Gym-481102E
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int main(){
    long long x , min_diff = LLONG_MAX , max_diff = LLONG_MIN;
    cin >> x ;
    long long arr [x];
    for(int i = 0 ; i < x ; i++){
        cin >> arr[i] ;
    }
    for(int i = 0 ; i < x ; i++){
        min_diff = min(min_diff , arr[i]);
        max_diff = max(max_diff , arr[i]);
    }
    cout << max_diff << " " << min_diff << endl;
}