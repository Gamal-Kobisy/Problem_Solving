#include <iostream>
#include <queue>
#include <vector>
#include <stack>
#include <utility>
#include <string>
#include <set>
#include <algorithm>
using namespace std;
bool compare(pair<long, long> &a, pair<long, long> &b)
{
    if (a.first == b.first)
        return a.second > b.second;
    return a.first < b.first;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string ss;
    string s, save = "";
    set<string> st;
    while (getline(cin, s))
    {
        save = save + ' ';
        save = save + s;
    }
    for (long long i = 0; i < save.size(); i++)
    {
        char sl = tolower(save[i]);
        if (isalpha(sl))
        {
            ss = ss + sl;
        }
        else
        {
            if (!ss.empty())
            {
                st.insert(ss);
            }
            ss = "";
        }
    }
    if (!ss.empty())
    {
        st.insert(ss);
    }
    // cout << st.size() << '\n';
    for (auto x : st)
    {
        cout << x << '\n';
    }

    return 0;
}