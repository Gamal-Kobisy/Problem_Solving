// LINK : https://www.spoj.com/problems/ABCPATH/en/
#include <bits/stdc++.h>
#define ll long long
#define nl '\n'
#define all(a) a.begin(),a.end()
#define allr(a) a.rbegin(),a.rend()
#define no cout<<"NO\n"
#define yes cout<<"YES\n"
#define ENG_GAMAL ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

/*
 ███████╗███╗   ██╗ ██████╗       ██████╗  █████╗ ███╗   ███╗ █████╗ ██╗
 ██╔════╝████╗  ██║██╔════╝      ██╔════╝ ██╔══██╗████╗ ████║██╔══██╗██║
 █████╗  ██╔██╗ ██║██║  ███╗     ██║  ███╗███████║██╔████╔██║███████║██║
 ██╔══╝  ██║╚██╗██║██║   ██║     ██║   ██║██╔══██║██║╚██╔╝██║██╔══██║██║
 ███████╗██║ ╚████║╚██████╔╝     ╚██████╔╝██║  ██║██║ ╚═╝ ██║██║  ██║███████╗
 ╚══════╝╚═╝  ╚═══╝ ╚═════╝       ╚═════╝ ╚═╝  ╚═╝╚═╝     ╚═╝╚═╝  ╚═╝╚══════╝
*/
// ————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
int h , w , t = 1;
int dx[] = {-1, 0, 1, 0, -1, 1, 1, -1};
int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};
int knightx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int knighty[] = {1, 2, 2, 1, -1, -2, -2, -1};
vector<vector<char>>grid;
vector<vector<bool>>vis;

bool valid(int x , int y)
{
    return (x >= 0 && x < h && y >= 0 && y < w && !vis[x][y]);
}
int dfs(int x , int y)
{
    vis[x][y] = true;
    int longest = 1;
    for (ll i = 0; i < 8; ++i) {
        int nx = x + dx[i] , ny = y + dy[i];
            if(valid(nx , ny) && (grid[nx][ny] - 1) == grid[x][y])
            {
                longest = max(longest , 1 + dfs(nx , ny));
            }
    }
    return longest;
}

void solve() {
    grid = vector<vector<char>>(h , vector<char>(w));
    vis  = vector<vector<bool>>(h , vector<bool>(w , false));
    for (ll i = 0; i < h; ++i) {
        for (ll j = 0; j < w; ++j) {
            cin >> grid[i][j];
        }
    }
    int ans = 0;
    for (ll i = 0; i < h; ++i) {
        for (ll j = 0; j < w; ++j) {
            if(grid[i][j] == 'A')
            {
                ans = max((int)(dfs(i , j)) , ans);
            }
        }
    }
    cout << "Case " << t++ << ": " << ans << nl;
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
//    ll t = 1;
//    cin >> t;
    cin >> h >> w;
    while(h != 0 && w != 0)
    {
        solve();
        cin >> h >> w;
    }

    return 0;
}