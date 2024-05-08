// https://vjudge.net/contest/585111#problem/P

#include <iostream>
#include <string>
#include <map>
#include <deque>
#include <set>
#include <algorithm>
#include <utility>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    long long n;
    cin >> n;
    while (n--)
    {
        string s1, s2;
        cin >> s1 >> s2;
        if (s1 == s2)
        {
            cout << 0 << endl;
            continue;
        }
        string min_string, max_string;
        if (s1.size() > s2.size())
        {
            max_string = s1;
            min_string = s2;
        }
        else
        {
            max_string = s2;
            min_string = s1;
        }
        string similar;
        for (int i = 0; i < min_string.size(); i++)
        {
            auto it = find(max_string.begin(), max_string.end(), min_string[i]);
            if (it != max_string.end())
            {
                string s;
                int index = it - max_string.begin(), j = i;
                while (min_string[j] == max_string[index] && j < min_string.size() && index < max_string.size())
                {
                    s += min_string[j];
                    j++;
                    index++;
                }
                if (s.size() > similar.size())
                {
                    similar = s;
                }
                while (find(it + 1, max_string.end(), min_string[i]) != max_string.end())
                {
                    it = find(it + 1, max_string.end(), min_string[i]);
                    s = "";
                    index = it - max_string.begin();
                    j = i;
                    while (min_string[j] == max_string[index] && j < min_string.size() && index < max_string.size())
                    {
                        s += min_string[j];
                        j++;
                        index++;
                    }
                    if (s.size() > similar.size())
                    {
                        similar = s;
                    }
                }
            }
        }
        int operations = (max_string.size() - similar.size()) + (min_string.size() - similar.size());
        cout << operations << endl;
    }

    return 0;
}