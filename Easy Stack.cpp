// LINK : https://vjudge.net/problem/SPOJ-STACKEZ
#include <iostream>
#include <deque>
using namespace std;

int main() {
    iostream::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    deque<int>v;
    int x,y,z;
    cin>>x;
    for(int i=0;i<x;i++){
        cin>>y;
        if(y==1){
            cin>>z;
            v.push_back(z);
        }
        else if(y==2)
        {
            if(v.empty()!=true){
                v.pop_back();
            }
        }else if(y==3){
            if(v.empty() == true){
                cout<<"Empty!"<<"\n";
            }
            else{
                cout<<v.back()<<"\n";
            }
        }
    }


}