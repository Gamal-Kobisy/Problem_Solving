// LINK : https://codeforces.com/problemset/problem/1365/D
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
int n , m;
vector<vector<char>>grid;
vector<vector<bool>>vis;

bool valid(int x , int y)
{
    return (x >= 0 && x < n && y >= 0 && y < m);
}
bool can_block(int i , int j)
{
    for (ll k = 0; k < 4; ++k) {
        int x = i + dx[k] , y = j + dy[k];
        if(valid(x , y))
        {
            if(grid[x][y] != 'G' )
            {
                grid[x][y] = '#';
            }
            else
            {
                return false;
            }
        }
    }
    return true;
}

bool can_escape(int x , int y)
{
    bool can = false;
    if(vis[x][y])
    {
        return true;
    }
    if(x == n - 1 && y == m - 1)
    {
        can =  true;
    }
    vis[x][y] = true;
    for (ll i = 0; i < 4; ++i) {
        int nx = x + dx[i] , ny = y + dy[i];
        if(valid(nx , ny) && !vis[nx][ny] && grid[nx][ny] != '#')
        {
            can += can_escape(nx , ny);
        }
    }
    return can;
}
void solve() {
    cin >> n >> m;
    grid = vector<vector<char>>(n , vector<char>(m));
    vis  = vector<vector<bool>>(n , vector<bool>(m , false));
    vector<pair<int , int>>good , bad;
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < m; ++j) {
            cin >> grid[i][j];
            if(grid[i][j] == 'B')
            {
                bad.push_back({i , j});
            }
            if(grid[i][j] == 'G')
            {
                good.push_back({i , j});
            }
        }
    }
    for (auto v: bad) {
        if(!can_block(v.first , v.second))
        {
            no;
            return;
        }
    }
    for (auto v: good) {
            if(!can_escape(v.first , v.second))
            {
                no;
                return;
            }
    }
    yes;
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
    while(t--)
    {
        solve();
    }

    return 0;
}