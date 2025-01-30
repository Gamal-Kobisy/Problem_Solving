// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/contest/1971/problem/D
#include <bits/stdc++.h>
#define ll long long
#define nl '\n'
#define sp ' '
#define all(a) a.begin(),a.end()
#define allr(a) a.rbegin(),a.rend()
#define no cout<<"NO\n"
#define yes cout<<"YES\n"
#define ENG_GAMAL ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;
// ————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
const int N = 2e5 + 5, M = 1e3, LOG = 20, inf = 0x3f3f3f3f;
ll infLL = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int counter = 1;
        char last = s[0];
        bool found_01 = false;
        for (int i = 1; i < s.size(); i++)
        {
            if (last == '0')
            {
                if (s[i] == '0')
                {
                    continue;
                }
                else if (s[i] == '1')
                {
                    if (!found_01)
                    {
                        found_01 = true;
                        last = '1';
                        continue;
                    }
                    else
                    {
                        last = '1';
                        counter++;
                    }
                }
            }
            else
            {
                if (s[i] == '1')
                {
                    continue;
                }
                else
                {
                    counter++;
                    last = '0';
                    continue;
                }
            }
        }
        cout << counter << endl;
    }
}
void file()
{
#ifndef ONLINE_JUDGE
    freopen("Input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
    freopen("Error.txt", "w", stderr);
#endif
}

int main() {
    file();
    ENG_GAMAL
// test-independent code ——————————————————————
// ————————————————————————————————————————————
    ll t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}