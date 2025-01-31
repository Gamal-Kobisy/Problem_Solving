// LINK : https://vjudge.net/problem/CodeForces-1626A
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int times;
    cin>>times;
    for(int i=0;i<times;i++){
        string s;
        cin>>s;
        sort(s.begin(),s.end());
        cout<<s<<endl;
    }


}