// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/contest/58/problem/A
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
    string s;
    cin >> s;
    bool h = false, e = false, l1 = false , l2 = false , o = false;
    for (int i = 0; i < s.size(); i++)
    {
        if (!h)
        {
            if (s[i] == 'h')
            {
                h = true;
            }
        }
        else if (!e)
        {
            if (s[i] == 'e')
            {
                e = true;
            }
        }
        else if (!l1)
        {
            if (s[i] ==  'l')
            {
                l1 = true;
            }
        }
        else if (!l2)
        {
            if (s[i] ==  'l')
            {
                l2 = true;
            }
        }
        else if (!o)
        {
            if (s[i] == 'o')
            {
                o = true;
                break;
            }
        }
    }
    cout << ((h && e && l1 && l2 && o) ? "YES\n" : "NO\n");
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