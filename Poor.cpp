// LINK : https://vjudge.net/problem/AtCoder-abc155_a
#include <iostream>
using namespace std;
int main() {
    int x,y,z;
    cin>>x>>y>>z;
    if(x==y&&y==z){
        cout<<"No";
    }else if (x==y&&y!=z){
        cout<<"Yes";
    }else if (x==z&&z!=y){
        cout<<"Yes";
    }else if(y==z&&y!=x){
        cout<<"Yes";
    }else{
        cout<<"No";
    }


    return 0;}