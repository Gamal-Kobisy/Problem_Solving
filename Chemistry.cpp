// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/contest/1888/problem/A
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
        deque<long long> alpha(26, 0);
        long long n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        if (n - k == 1)
        {
            cout << "YES\n";
        }
        else
        {
            for (char c : s)
            {
                alpha[c - 'a']++;
            }
            int counter = count_if(alpha.begin(), alpha.end(), [&](int x)
            { return x % 2 == 1; });
            // cout << counter << "\n";
            if (counter == k)
            {
                cout << "YES\n";
            }
            else if (counter == 0)
            {
                cout << "YES\n";
            }

            else if (counter < k)
            {
                cout << "YES\n";
            }
            else if (counter > k)
            {
                if (counter - k == 1)
                {
                    cout << "YES\n";
                }
                else
                {
                    cout << "NO\n";
                }
            }
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