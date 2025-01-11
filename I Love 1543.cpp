// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/problemset/problem/2036/D
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

int dx[] = {0, 1, 0, -1, -1, 1, 1, -1};
int dy[] = {1, 0, -1, 0, 1, 1, -1, -1};

void solve() {
    int n , m;
    cin >> n >> m;
    vector<string>grid(n);
    for (ll i = 0; i < n; ++i) {
        cin >> grid[i];
    }
    ll ans = 0;
    for (ll i = 0; i < min(n , m) / 2; ++i) {
        string layer = "***";
        int x = i , y = i , direction = 0;
        for (ll j = 0; j < 2 * ((n - 2 * i) + (m - 2 * i) - 2) + 3; ++j) {
            layer += grid[x][y];
            if(layer[layer.size() - 4] == '1' && layer[layer.size() - 3] == '5' &&layer[layer.size() - 2] == '4' &&layer[layer.size() - 1] == '3' )
                ans++;
            if(x + dx[direction] >= n - i || y + dy[direction] >= m - i || x + dx[direction] < i || y + dy[direction] < i)
                direction++ , direction %= 4;
            x += dx[direction];
            y += dy[direction];
        }
    }

    cout << ans << nl;
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
     cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}