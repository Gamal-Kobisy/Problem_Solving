// https://vjudge.net/contest/585111#problem/F

#include <iostream>
#include <string>
#include <map>
#include <deque>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    map<string, long long> points;
    for (int i = 0; i < n; i++)
    {
        string key;
        long long value;
        cin >> key >> value;
        points[key] = value;
    }
    for (int i = 0; i < m; i++)
    {
        deque<string> d;
        string word = " ";
        while (word != ".")
        {
            cin >> word;
            d.push_back(word);
        }
        long long Hay_Points = 0;
        for (string s : d)
        {
            Hay_Points += points[s];
        }
        cout << Hay_Points << "\n";
    }
    return 0;
}
/* 7 2
 administer 100000
 spending 200000
 manage 50000
 responsibility 25000
 expertise 100
 skill 50
 money 75000
 the incumbent will administer the spending of kindergarden milk money
 and exercise responsibility for makingchange he or she will share
 responsibility for thet ask of managing the money with the assistant
 whose skill and expertise shall ensure the successful spending exercise
 .
 this individual must have the skill to perform a heart transplant and
 expertise in rocketscience
 .*/