#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    cin >> N;
    int board[N];
    for (int i = 0; i < N; i++)
    {
        cin >> board[i];
    }
    sort(board, board + N);
    for (int i = 0; i < N; i++)
    {
        cout << board[i];
        (i != N - 1) ? cout << " " : cout << "\n";
    }
}