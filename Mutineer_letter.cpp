#include <iostream>
#include <vector>
using namespace std;
int main()
{
    long long n;
    cin >> n;
    vector<char> word(n);
    for (int i = 0; i < n; i++)
    {
        cin >> word[i];
    }
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