#include <iostream>
#include <string>


using namespace std;

int main()
{
    long long t;
    cin >> t;
    for (long long x = 0; x < t; x++)
    {
        unsigned long long n, k, operations = 0;
        cin >> n >> k;
        string line;
        cin >> line;
        for (int i = 0; i < n;)
        {
            if (line[i] == 'B')
            {
                for (int j = 0; j < k && i + k < n; j++)
                {
                    line[i + j] = 'W';
                }
                i += k;
                ++operations;
            }
            else
            {
                i++;
            }
        }
        cout << operations << "\n";
    }

    return 0;
}