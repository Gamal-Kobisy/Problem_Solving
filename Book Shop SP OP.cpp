// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://cses.fi/problemset/task/1158
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
const int N = 1e3 + 5, M = 1e5 + 5, LOG = 20, inf = 0x3f3f3f3f;
ll infLL = 0x3f3f3f3f3f3f3f3f;

int W[N], V[N], n, x;

void solve() {
    cin >> n >> x;
    for (ll i = 0; i < n; ++i)
        cin >> W[i];
    for (ll i = 0; i < n; ++i)
        cin >> V[i];
    vector<int>Prev(x + 1);
    for (int i = 1; i <= n; ++i) {
        vector<int>curr(x + 1);
        for (int j = 0; j <= x; ++j) {
            curr[j] = Prev[j];
            if (j >= W[i - 1])
                curr[j] = max(curr[j] , Prev[j - W[i - 1]] + V[i - 1]);
        }
        Prev = curr;
    }
    cout << Prev[x] << nl;
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