// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK :
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#pragma GCC target("avx,avx2,fma")
#define ll long long
#define int ll
#define nl '\n'
#define sp ' '
#define all(a) a.begin(),a.end()
#define allr(a) a.rbegin(),a.rend()
#define no cout<<"NO\n"
#define yes cout<<"YES\n"
#define imp cout<<"IMPOSSIBLE\n"
#define ENG_GAMAL ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;
// ————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
const int N = 3000 + 5, M = 1e3, LOG = 20, inf = 0x3f3f3f3f;
ll infLL = 0x3f3f3f3f3f3f3f3f;
int n , vis[N][N];
string grid[N] , memo[N][N];
string di[] = {"D", "L", "R", "U", "DR", "DL", "UR", "UL"};
int dx[] = {1, 0, 0, -1, 1, -1, 1, -1};
int dy[] = {0, -1, 1, 0, 1, -1, -1, 1};
int knightx[] = {2, 2, -2, -2, 1, 1, -1, -1};
int knighty[] = {1, -1, 1, -1, 2, -2, 2, -2};
string solve(int i, int j) {
    if (vis[i][j]) return memo[i][j];
    if (i == n && j == n) return "";

    string best;
    bool have = false;

    if (j < n) {
        string right = string(1, grid[i][j + 1]) + solve(i, j + 1);
        if (!have || right < best) {
            best = right;
            have = true;
        }
    }
    if (i < n) {
        string down = string(1, grid[i + 1][j]) + solve(i + 1, j);
        if (!have || down < best) {
            best = down;
            have = true;
        }
    }

    // store and return
    vis[i][j] = true;
    memo[i][j] = best;
    return memo[i][j];
}

void TC() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> grid[i];
        grid[i] = "z" + grid[i];
    }
    for(int i : {0ll , n + 1}){
        for (int j = 1; j <= n; ++j) {
            grid[i][j] = 'z';
        }
    }
    memset(vis , 0 , sizeof vis);
    cout << grid[1][1] + solve(1 , 1) << nl;
}
void file()
{
#ifndef ONLINE_JUDGE
    freopen("Input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
    freopen("Error.txt", "w", stderr);
#endif
}

signed main() {
    file();
    ENG_GAMAL
// test-independent code ——————————————————————
// ————————————————————————————————————————————
    ll tc = 1;
//     cin >> tc;
    while (tc--)
    {
        TC();
    }

    return 0;
}