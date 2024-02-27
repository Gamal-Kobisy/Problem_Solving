#include <iostream>
#include <cctype>
#include <vector>
using namespace std;
int main()
{
    long long n, Slytherin = 0, Gryffindor = 0;
    cin >> n;
    vector<char> text(n);
    for (int i = 0; i < n; i++)
    {
        cin >> text[i];
    }
    for (char c : text)
    {
        (c == '0') ? Slytherin += 1 : Gryffindor += 1;
    }
    (Slytherin == Gryffindor) ? cout << "Good" : cout << "Bad";
}