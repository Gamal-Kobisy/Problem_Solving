// LINK : https://vjudge.net/problem/Gym-481102C
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int sz;
    cin >> sz;
    long long arr[sz] , sort_arr[sz];
    for(int i = 0 ; i < sz ; i++){
        cin >> arr[i];
        sort_arr[i] = arr[i];
    }
    sort(sort_arr,sort_arr+sz);

    for(int i = 0 ; i < sz ; i++){
        if (sort_arr[i] != arr[i]){
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}