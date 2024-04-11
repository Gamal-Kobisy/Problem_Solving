#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    cin >> s;
    bool is_unreadable = true;
    for (int i = 1; i <= s.size(); i++)
    {
        (i % 2 == 1) ? ((s[i - 1] < 'a' || s[i - 1] > 'z') ? is_unreadable = false : is_unreadable) : ((s[i - 1] < 'A' || s[i - 1] > 'Z') ? is_unreadable = false : is_unreadable);
    }
    /*for (int i = 1; i <= s.size(); i++) {
    if (i % 2 == 1) {
        if (s[i - 1] < 'a' || s[i - 1] > 'z') {
            is_unreadable = false;
            break;
        }
    } else {
        if (s[i - 1] < 'A' || s[i - 1] > 'Z') {
            is_unreadable = false;
            break;
        }
    }
}
*/
    (is_unreadable) ? cout << "Yes\n" : cout << "No\n";
    return 0;
}