#include <iostream>

using namespace std;
int main(){
    long long sz_1 , sz_2;
    cin >> sz_1 ;
    cin >> sz_2 ;
    char str_1[sz_1] , str_2[sz_2];
    for(long long i = 0 ; i < sz_1 ; i++){
        cin >> str_1[i];
    }
    for(long long j = 0 ; j < sz_2 ; j++){
        cin >> str_2[j];
    }
    for(int i = 0 , j = 0; i < sz_1 && j < sz_2 ; i++ , j++)
    {
        if(str_1[i] <= str_2[j]) {
            for(int i = 0 ; i < sz_1 ; i++) {
                cout << str_1[i]; }
            break;
        }
        else if (str_1[i] >= str_2[j]) {
            for(int i = 0 ; i < sz_2 ; i++){
                cout << str_2[i];
            }
            break;
        }
    }
}