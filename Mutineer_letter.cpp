#include <iostream>
#include <vector>
using namespace std;
int main()
{
    long long n;
    cin >> n;
    char word[n];
    cin >> word;
    for (int i = 0; i < n; i++)
    {
        if (int(word[i]) < 97)
        {
            cout << word[i] << " " << i + 1;
            break;
        }
    }

    return 0;
}