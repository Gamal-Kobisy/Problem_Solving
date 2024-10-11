// LINK : https://codeforces.com/contest/1105/problem/D
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
int n , m , s;
vector<vector<char>>grid;
vector<vector<bool>>vis;
vector<pair<int , int>>players;
vector<int>speed , ans;
vector<queue<pair<int , int>>>q(10);
int dx[] = {-1, 0, 1, 0, -1, 1, 1, -1};
int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};
char di[] = {'U', 'R', 'D', 'L'};
int knightx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int knighty[] = {1, 2, 2, 1, -1, -2, -2, -1};

bool valid(int x , int y)
{
    return (x >= 0 && x < n && y >= 0 && y < m && !vis[x][y] && grid[x][y] != '#');
}
void bfs()
{
    while (true)
    {
        bool ok = false;
        for (ll i = 0; i < s; ++i) {
            for (ll l = 0; l < speed[i]; ++l) {
                int sz = q[i].size();
                for (ll j = 0; j < sz; ++j) {
                    int x = q[i].front().first , y = q[i].front().second;
                    q[i].pop();
                    for (ll k = 0; k < 4; ++k) {
                        int nx = x + dx[k] , ny = y + dy[k];
                        if(valid(nx , ny))
                        {
                            vis[nx][ny] = true;
                            q[i].emplace(nx , ny);
                            ans[i]++;
                        }
                    }
                }
                if(q[i].empty())
                {
                    break;
                }
            }
            ok |= q[i].size();
        }
        if(!ok)
        {
            break;
        }
    }
}

void solve() {
    cin >> n >> m >> s;
    grid = vector<vector<char>>(n , vector<char>(m));
    vis = vector<vector<bool>>(n , vector<bool>(m));
    players = vector<pair<int , int>>(s , {0 , 0});
    speed = vector<int>(s);
    ans = vector<int>(s , 0);
    for (ll i = 0; i < s; ++i) {
        cin >> speed[i];
    }
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < m; ++j) {
            cin >> grid[i][j];
            if(isdigit(grid[i][j]))
            {
                q[grid[i][j] - '1'].emplace(i , j);
                vis[i][j] = true;
                ans[grid[i][j] - '1']++;
            }
        }
    }

    bfs();
    for (ll i = 0; i < s; ++i) {
        cout << ans[i] << ' ';
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