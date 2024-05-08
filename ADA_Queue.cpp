// https://vjudge.net/contest/583343#problem/B
#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main()
{
    iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    deque<long long> v(0);
    bool reversed = false;
    long long t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        string option;
        cin >> option;
        if (option == "back")
        {
            if (v.empty())
            {
                cout << "No job for Ada?\n";
            }
            else
            {
                if (!reversed)
                {

                    cout << v.back() << endl;
                    v.pop_back();
                }
                else
                {
                    cout << v.front() << endl;
                    v.pop_front();
                }
            }
        }
        else if (option == "front")
        {
            if (v.empty())
            {
                cout << "No job for Ada?\n";
            }
            else
            {
                if (!reversed)
                {
                    cout << v.front() << endl;
                    v.pop_front();
                }
                else
                {
                    cout << v.back() << endl;
                    v.pop_back();
                }
            }
        }
        else if (option == "reverse")
        {
            reversed = !reversed;
        }
        else if (option == "push_back")
        {
            int x;
            cin >> x;
            if (!reversed)
            {
                v.push_back(x);
            }
            else
            {
                v.push_front(x);
            }
        }
        else if (option == "toFront")
        {
            int x;
            cin >> x;
            if (!reversed)
            {
                v.push_front(x);
            }
            else
            {
                v.push_back(x);
            }
        }
    }
}