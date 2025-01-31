// LINK : https://vjudge.net/problem/CodeChef-TSORT
#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;
int main (){
    deque<int> D;
    int num,x,i;
    cin>>num;
    for( i=0;i<num;i++){
        cin>>x;
        D.push_front(x);
    }
    sort(D.begin(),D.end());
    for( i=0;i<num;i++){
        cout<<D[i]<<"\n";

    }



}