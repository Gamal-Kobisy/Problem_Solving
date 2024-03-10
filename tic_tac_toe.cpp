#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;

// Function to display a list of numbers
void display_list(const vector<int> &list)
{
    cout << "{";
    for (size_t i = 0; i < list.size() - 1; i++)
    {
        cout << list[i];
        (i != list.size() - 2) ? cout << "," : cout << " ";
    }
    cout << "}";
}

// Function to display the Tic-Tac-Toe board
void display_screen(const vector<char> &x)
{
    cout << "\n-------------\n"
         << "| "
         << x[0] << " | " << x[1] << " | " << x[2] << " |"
         << "\n-------------\n"
         << "| " << x[3] << " | " << x[4] << " | " << x[5] << " |"
         << "\n-------------\n"
         << "| " << x[6] << " | " << x[7] << " | " << x[8] << " |"
         << "\n-------------\n";
}

// Function to check if a player has won
bool check_winner(const vector<char> &screen)
{
    for (int i = 0; i < 3; ++i)
    {
        // Check rows and columns
        if ((screen[i] - 48) + (screen[i + 3] - 48) + (screen[i + 6] - 48) == 15 ||
            (screen[i * 3] - 48) + (screen[i * 3 + 1] - 48) + (screen[i * 3 + 2] - 48) == 15)
        {
            return true;
        }
    }

    // Check diagonals
    if ((screen[0] - 48) + (screen[4] - 48) + (screen[8] - 48) == 15 ||
        (screen[2] - 48) + (screen[4] - 48) + (screen[6] - 48) == 15)
    {
        return true;
    }

    return false;
}

int main()
{
    vector<int> list1 = {1, 3, 5, 7, 9, 0};
    vector<int> list2 = {0, 2, 4, 6, 8, 0};
    vector<int> pos_list = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    int pl1, pl2, pos = 10;
    char pl1_c, pl2_c;
    vector<char> board(9, '-');

    for (int i = 0; i < 9; i++)
    {
        display_screen(board);

        // Player 1's turn
        cout << "player (1) turn \n";
        cout << "Enter the number from ";
        display_list(list1);
        cout << ":";
        cin >> pl1;
        auto it1 = find(list1.begin(), list1.end(), pl1);

        // Validate input for player 1
        while (cin.fail() || it1 == list1.end() || pl1 < 1)
        {
            cout << "Invalid number. Choose a number from ";
            display_list(list1);
            cout << ":";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> pl1;
            it1 = find(list1.begin(), list1.end(), pl1);
        }

        // Choose position for player 1
        cout << "chose position from";
        display_list(pos_list);
        cout << ":";
        cin >> pos;
        auto it_p = find(pos_list.begin(), pos_list.end(), pos);

        // Validate chosen position for player 1
        while (cin.fail() || it_p == pos_list.end() || pos > 0)
        {
            cout << "Invalid chose, please chose from";
            display_list(pos_list);
            cout << ":";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> pos;
            it_p = find(pos_list.begin(), pos_list.end(), pos);
        }

        // Update the board and lists for player 1
        pl1_c = char(pl1) + 48;
        board[pos - 1] = pl1_c;
        list1.erase(it1);
        pos_list.erase(it_p);

        // Check if player 1 has won
        if (check_winner(board))
        {
            display_screen(board);
            cout << "Player 1 wins!" << endl;
            return 0;
        }

        display_screen(board);

        // Player 2's turn
        cout << "player (2) turn \n";
        cout << "Chose a number from ";
        display_list(list2);
        cout << ":";
        cin >> pl2;
        auto it2 = find(list2.begin(), list2.end(), pl2);

        // Validate input for player 2
        while (cin.fail() || it2 == list2.end() || pl2 > 0)
        {

            cout << "Invalid number. Choose a number from ";
            display_list(list2);
            cout << ":";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> pl2;
            it2 = find(list2.begin(), list2.end(), pl2);
        }

        // Choose position for player 2
        cout << "Chose position from";
        display_list(pos_list);
        cout << ":";
        cin >> pos;
        it_p = find(pos_list.begin(), pos_list.end(), pos);

        // Validate chosen position for player 2
        while (cin.fail() || it_p == pos_list.end() || pos > 0)
        {
            cout << "Invalid chose, please chose from";
            display_list(pos_list);
            cout << ":";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> pos;
            it_p = find(pos_list.begin(), pos_list.end(), pos);
        }

        // Update the board and lists for player 2
        pl2_c = char(pl2) + 48;
        board[pos - 1] = pl2_c;
        list2.erase(it2);
        pos_list.erase(it_p);

        // Check if player 2 has won
        if (check_winner(board))
        {
            display_screen(board);
            cout << "Player 2 wins!" << endl;
            return 0;
        }
    }

    // If no one wins, it's a draw
    cout << "It's a draw!" << endl;

    return 0;
}