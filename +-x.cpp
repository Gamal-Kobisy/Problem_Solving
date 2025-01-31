// LINK : https://vjudge.net/problem/AtCoder-abc137_a
#include <iostream>
using namespace std;
int main() {
    long long A,B;
    cin>>A>>B;
    if((A+B)>=(A-B)&&(A+B)>=(A*B)){
        cout<<A+B;
    }else if((A-B)>=(A+B)&&(A-B)>=(A*B)){
        cout<<A-B;
    }else if ((A*B)>=(A+B)&&(A*B)>=(A-B)){
        cout<<A*B;
    }
}
 