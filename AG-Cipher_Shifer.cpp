#include <iostream>
#include <string>

using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int x;
        cin >> x;
        string encrypted, decrypted;
        cin >> encrypted;
        char c = encrypted[0];
        for (int j = 1; j < encrypted.size(); j++)
        {
            if (encrypted[j] == c)
            {
                decrypted += c;
                if (j != x)
                {
                    c = encrypted[j + 1];
                    j++;
                }
            }
        }
        cout << decrypted << "\n";
    }
    return 0;
}