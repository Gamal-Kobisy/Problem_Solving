// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/contest/1890/problem/A
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
    int n;
    cin >> n;
    while (n--)
    {
        int x;
        cin >> x;
        vector<long long> v(x);
        bool valid = true;
        long long n1, n2;
        int n1_counter = 0, n2_counter = 0;
        for (long long i = 0; i < x; i++)
        {
            cin >> v[i];
        }
        sort(v.rbegin(), v.rend());
        n1 = v[0];
        n2 = v[v.size() - 1];
        if (n1 == n2)
        {
            cout << "YES\n";
        }
        else if (v.size() == 2)
        {
            cout << "YES\n";
        }
        else
        {
            for (int i = 0; i < x; i++)
            {
                if (v[i] == n1)
                {
                    n1_counter++;
                }
                else if (v[i] == n2)
                {
                    n2_counter++;
                }
                else
                {
                    valid = false;
                }
            }
            if (!valid)
            {
                cout << "NO\n";
            }
            else if (valid)
            {
                if (x % 2 == 0)
                {
                    (n1_counter == n2_counter) ? cout << "YES\n" : cout << "NO\n";
                }
                else
                {
                    (abs(n1_counter - n2_counter) == 1) ? cout << "YES\n" : cout << "NO\n";
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