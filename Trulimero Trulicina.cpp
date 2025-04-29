// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/contest/2094/problem/F
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

string di[] = {"D", "L", "R", "U", "DR", "DL", "UR", "UL"};
int dx[] = {1, 0, 0, -1, 1, -1, 1, -1};
int dy[] = {0, -1, 1, 0, 1, -1, -1, 1};
int knightx[] = {2, 2, -2, -2, 1, 1, -1, -1};
int knighty[] = {1, -1, 1, -1, 2, -2, 2, -2};

bool valid(int x , int y , int n , int m)
{
    return x >= 0 && x < n && y >= 0 && y < m;
}

void solve() {
    ll n , m , k;
    cin >> n >> m >> k;
    ll num = 1;
    deque<deque<ll>>ans(n , deque<ll>(m));
    bool shift = false;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            ans[i][j] = num++;
            if(num > k)
                num = 1;
            if(i && ans[i][j] == ans[i - 1][j])
                shift = true;
        }
        if(shift)
        {
            ans[i].emplace_back(ans[i].front());
            ans[i].pop_front();
        }
        shift = false;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << ans[i][j] << sp;
        }
        cout << nl;
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
     cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}