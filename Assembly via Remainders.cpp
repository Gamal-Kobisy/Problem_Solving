// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/contest/1968/problem/C
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
        int n;
        cin >> n;
        n;
        deque<int> d(n);
        for (int i = 0; i < n - 1; i++)
        {
            cin >> d[i];
        }
        deque<int> res(n + 1);
        res[0] = 500 + n - 1;
        for (int i = 0; i < n - 1; i++)
        {
            long long num = res[i];
            if (d[i] > res[i])
            {
                while (num % res[i] != d[i])
                {
                    num--;
                }
            }
            else
            {
                while (num % res[i] != d[i])
                {
                    num++;
                }
            }
            res[i + 1] = num;
        }
        for (int i = 0; i < n; i++)
        {
            cout << res[i] << (i == n - 1 ? "\n" : " ");
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