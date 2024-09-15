// LINK : https://cses.fi/problemset/task/1194/
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
char di[] = {'U', 'R', 'D', 'L'};
int knightx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int knighty[] = {1, 2, 2, 1, -1, -2, -2, -1};
const int N = 1e3 + 1;
int n , m;
vector<vector<char>>grid(N , vector<char>(N));
// index 0 beta3 el mon index 1 beta3 el person
queue<pair<int , int>> q[2];
int dist[N][N][2];
int parent[N][N];
bool valid(int nx , int ny)
{
    return (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] != '#');
}
void bfs(int idx)
{
    queue<pair<int , int>> &qq = q[idx];

    while (!qq.empty())
    {
        int x = qq.front().first , y = qq.front().second;
        qq.pop();
        for (ll i = 0; i < 4; ++i) {
            int nx = x + dx[i] , ny = y + dy[i];
            if(valid(nx , ny)  && dist[nx][ny][idx] > dist[x][y][idx] + 1)
            {
                dist[nx][ny][idx] = dist[x][y][idx] + 1;
                qq.push({nx , ny});
                if(idx == 1)
                parent[nx][ny] = i;
            }
        }
    }
}

void solve() {
    cin >> n >> m;
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < m; ++j) {
            cin >> grid[i][j];
            parent[i][j] = -1;
            dist[i][j][0] = dist[i][j][1] = 1e9;
            if (grid[i][j] == 'A') {
                q[1].push({i , j});
                dist[i][j][1] = 0;
            }
            if (grid[i][j] == 'M') {
                q[0].push({i , j});
                dist[i][j][0] = 0;
            }
        }
    }

    bfs(0);
    bfs(1);

    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < m; ++j) {
            if(i == 0 || j == 0 || i == n - 1 || j == m - 1)
            {
                if(grid[i][j] != '#' && dist[i][j][1] < dist[i][j][0])
                {
                    yes;
                    cout << dist[i][j][1] << nl;
                    vector<char>ans;
                    int x = i , y = j;
                    while (parent[x][y] != -1)
                    {
                        ans.push_back(di[parent[x][y]]);
                        ll d = parent[x][y];
                        x -= dx[d] ;
                        y -= dy[d];
                    }
                    reverse(all(ans));
                    for (char d: ans) {
                      cout << d;
                    }
                    cout << nl;
                    return;
                }
            }
        }
    }
    no;
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