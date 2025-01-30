// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/contest/1971/problem/C
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
    long long t;
    cin >> t;
    while (t--)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if (abs(a - b) == 1 || abs(c - d) == 1)
        {
            cout << "NO\n";
            continue;
        }
        int a2, b2, c2, d2;
        a2 = min(a, b);
        b2 = max(a, b);
        c2 = min(c, d);
        d2 = max(c, d);
        deque<int> hours(b2 - a2);
        for (int i = a2 + 1; i < b2; i++)
        {
            hours[i - a2 - 1] = i;
        }
        auto it_1 = find(hours.begin(), hours.end(), c2);
        auto it_2 = find(hours.begin(), hours.end(), d2);
        if (it_1 == hours.end() && it_2 == hours.end())
        {
            cout << "NO\n";
        }
        else if (it_1 != hours.end() && it_2 != hours.end())
        {
            cout << "NO\n";
        }
        else
        {
            cout << "YES\n";
        }
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