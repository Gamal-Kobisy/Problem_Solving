// LINK : https://codeforces.com/problemset/problem/377/A
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
int dx[] = {-1, 0, 1, 0, -1, 1, 1, -1};
int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};
int knightx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int knighty[] = {1, 2, 2, 1, -1, -2, -2, -1};
int n , m , k , dots;
vector<vector<char>>grid;
vector<vector<bool>>vis;
bool valid(int nx , int ny)
{
    return (nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny] && grid[nx][ny] == 'X');
}
int count_adj(int x , int y , int cnt)
{
    vis[x][y] = true;
    cnt++;
    for (ll i = 0; i < 4; ++i) {
        if(valid(x + dx[i] , y + dy[i]))
        {
            cnt = count_adj(x + dx[i] , y + dy[i] , cnt);
        }
    }
    return cnt;
}

void dfs(int x , int y)
{
    if(dots <= 0)
    {
        return;
    }
    dots--;
    grid[x][y] = '.';

    vis[x][y] = true;
    for (ll i = 0; i < 4; ++i) {
        if(valid(x + dx[i] , y + dy[i]))
        {
            dfs(x + dx[i] , y + dy[i]);
        }
    }
}
void solve() {
    cin >> n >> m >> k;
    grid = vector<vector<char>>(n, vector<char>(m));
    vis = vector<vector<bool>>(n, vector<bool>(m, false));
    int s = 0;
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < m; ++j) {
            cin >> grid[i][j];
            if(grid[i][j] == '.')
            {
                s++;
                grid[i][j] = 'X';
            }
        }
    }
    dots = s - k;
    bool Done = false;
    for (ll i = 0; i < n && !Done; ++i) {
        for (ll j = 0; j < m && !Done; ++j) {
            if(grid[i][j] == 'X')
            {
                if(count_adj(i , j , 0) >= dots)
                {
                    vis = vector<vector<bool>>(n, vector<bool>(m, false));
                    dfs(i , j);
                    Done = true;
                }
            }
        }
    }
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < m; ++j) {
            cout << grid[i][j];
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
//    cin >> t;
    while(t--)
    {
        solve();
    }

    return 0;
}