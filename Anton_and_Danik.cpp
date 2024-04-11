#include <iostream>

using namespace std;

int main()
{
    long long N;
    cin >> N;
    string game;
    cin >> game;
    long long A_D[2] = {0};
    for (char c : game)
    {
        (c == 'A') ? A_D[0]++ : A_D[1]++;
    }
    if (A_D[0] == A_D[1])
    {
        cout << "Friendship\n";
    }
    else if (A_D[0] > A_D[1])
    {
        cout << "Anton\n";
    }
    else
    {
        cout << "Danik\n";
    }

    return 0;
}