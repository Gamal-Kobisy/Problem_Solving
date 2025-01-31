// LINK : https://vjudge.net/problem/Aizu-ITP1_1_C
#include <iostream>
using namespace std;
int main() {
    long long a;
    long long b;
    cin>>a;
    cin>>b;
    long long area = (a*b);
    long long perimeter =(a+b)*2;
    cout<<area<<" "<<perimeter<<"\n";
    return 0;
}