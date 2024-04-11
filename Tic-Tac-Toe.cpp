#include <iostream>
#include <string>

using namespace std;

int main()
{

    long long t;
    cin >> t;
    for (long long k = 0; k < t; k++)
    {
        bool win = false;
        string board[3];
        for (int i = 0; i < 3; i++)
        {
            cin >> board[i];
        }
        int i = 0;
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] == board[i + 1][j] && board[i + 1][j] == board[i + 2][j])
            {
                if (board[i][j] != '.')
                {
                    cout << board[i][j] << endl;
                    win = true;
                    break;
                }
            }
        }
        if (!win)
        {
            int j = 0;
            for (int i = 0; i < 3; i++)
            {
                if (board[i][j] == board[i][j + 1] && board[i][j + 1] == board[i][j + 2])
                {
                    if (board[i][j] != '.')
                    {
                        cout << board[i][j] << endl;
                        win = true;
                        break;
                    }
                }
            }
        }
        if (!win)
        {
            if ((board[0][0] == board[1][1] && board[1][1] == board[2][2]) || (board[0][2] == board[1][1] && board[1][1] == board[2][0]))
            {
                if (board[1][1] != '.')
                {
                    cout << board[1][1] << endl;
                    win = true;
                }
            }
        }
        if (!win)
        {
            cout << "DRAW\n";
        }
    }

    return 0;
}