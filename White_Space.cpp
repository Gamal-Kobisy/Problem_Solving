#include <iostream>
#include <string>
using namespace std;

int main()
{
    string number;
    cin >> number;
    for (char c : number)
    {
        cout << c << ' ';
    }
}