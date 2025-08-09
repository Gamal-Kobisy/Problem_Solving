// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK :
#include <bits/stdc++.h>
#define ll long long
#define nl '\n'
#define sp ' '
#define all(a) a.begin(), a.end()
#define allr(a) a.rbegin(), a.rend()
#define no cout << "NO\n"
#define yes cout << "YES\n"
#define ENG_GAMAL                     \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr);
using namespace std;
// ————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
const int N = 2e5 + 5, M = 1e3, LOG = 20, inf = 0x3f3f3f3f;
ll infLL = 0x3f3f3f3f3f3f3f3f;

void solve()
{
    ll n;
    cin >> n;
    vector<string> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        sort(all(a[i]));
    }
    for (int i = 1; i < n; ++i)
    {
        // If current string is already >= previous, continue
        if (a[i] >= a[i - 1])
        {
            continue;
        }

        // Find the next lexicographically larger permutation
        bool found = false;

        // Try to find a position where we can make the string larger
        for (int j = 0; j < min(a[i].size(), a[i - 1].size()); ++j)
        {
            if (a[i][j] < a[i - 1][j])
            {
                // Find the smallest character at position >= j that is > a[i-1][j]
                int best_pos = -1;
                char best_char = 'z' + 1;

                for (int k = j; k < a[i].size(); ++k)
                {
                    if (a[i][k] > a[i - 1][j] && a[i][k] < best_char)
                    {
                        best_char = a[i][k];
                        best_pos = k;
                    }
                }

                if (best_pos != -1)
                {
                    // Swap and sort the rest
                    swap(a[i][j], a[i][best_pos]);
                    sort(a[i].begin() + j + 1, a[i].end());
                    found = true;
                    break;
                }
            }
            else if (a[i][j] > a[i - 1][j])
            {
                found = true;
                break;
            }
        }

        // If we couldn't fix by character comparison, try other approaches
        if (!found)
        {
            // If current string is shorter and is a prefix of previous, impossible
            if (a[i].size() < a[i - 1].size() && a[i - 1].substr(0, a[i].size()) == a[i])
            {
                cout << -1 << nl;
                return;
            }

            // Try to find next permutation
            string original = a[i];
            sort(all(a[i]));

            do
            {
                if (a[i] >= a[i - 1])
                {
                    found = true;
                    break;
                }
            } while (next_permutation(all(a[i])));

            if (!found)
            {
                cout << -1 << nl;
                return;
            }
        }
    }
    for (int i = 0; i < n; ++i)
    {
        cout << a[i] << nl;
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

int main()
{
    file();
    ENG_GAMAL
    // test-independent code ——————————————————————
    // ————————————————————————————————————————————
    ll t = 1;
    //     cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}