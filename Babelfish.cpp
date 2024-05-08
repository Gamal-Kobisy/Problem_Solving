// https://vjudge.net/contest/585111#problem/H

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
    map<string, string> dict;
    deque<string> translated_words;

    // Read mapping from foreign to English
    string statement;
    while (getline(cin, statement))
    {
        string forien_word, eng_word;
        if (statement.empty())
        {
            break;
        }
        bool eng = true;
        for (char c : statement)
        {
            if (c == ' ')
            {
                eng = false;
                continue;
            }
            if (eng)
            {
                eng_word += c;
            }
            else
            {
                forien_word += c;
            }
        }
        dict[forien_word] = eng_word;
    }

    // Translate foreign words to English
    string word;
    while (cin >> word)
    {
        if (dict.find(word) != dict.end())
        {
            translated_words.push_back(dict[word]);
        }
        else
        {
            translated_words.push_back("eh");
        }
    }

    // Output translated words
    for (const string &s : translated_words)
    {
        cout << s << "\n";
    }

    return 0;
}

/*
dog ogday
cat atcay
pig igpay
froot ootfray
loops oopslay

atcay
ittenkay
oopslay
*/
