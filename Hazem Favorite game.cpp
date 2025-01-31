// LINK : https://vjudge.net/problem/Gym-481102D
#include <iostream>
using namespace std;

int main(){
    bool index = true ;
    long long sz ,  tile ;
    cin >> sz ;
    long long arr[sz];
    for(int i = 0 ; i < sz ; i++) {
        cin >> arr[i];
    }
    cin >> tile ;
    for(int i = 0 ; i < sz ; i++) {
        if(tile == arr[i]) {
            cout << i ;
            index = false;
            break;
        }
    }
    if(index) cout << -1 << endl ;
    return 0;




}