// LINK : https://codeforces.com/problemset/problem/1063/B
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

int n , m , r , c ,  x , y , ans = 0;
vector<vector<char>>grid;
vector<vector<pair<ll ,ll>>>dist;

bool valid(int i , int j)
{
    return (i < n && i >= 0 && j < m && j >= 0 && dist[i][j].first + dist[i][j].second == 20e10 && grid[i][j] == '.');
}
void bfs(int x1 , int y1)
{
    queue<pair<ll ,ll>>q;
    q.push({x1 , y1});
    dist[x1][y1] = {0 , 0};
    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();
        for (ll i = 0; i < 4; ++i) {
            int nx = cur.first + dx[i] , ny = cur.second + dy[i];
            if(valid(nx , ny))
            {
                int xx = nx +1;
                while (valid(xx , ny))
                {
                    ll l = dist[cur.first][cur.second].first + (i == 1), r = dist[cur.first][cur.second].second + (i == 3);
                    dist[xx][ny].first = dist[cur.first][cur.second].first + (i == 1);
                    dist[xx][ny].second = dist[cur.first][cur.second].second + (i == 3);
                    q.push({xx, ny});
                    xx++;
                }
                while (valid(nx , ny))
                {
                    ll l = dist[cur.first][cur.second].first + (i == 1), r = dist[cur.first][cur.second].second + (i == 3);
                    dist[nx][ny].first = dist[cur.first][cur.second].first + (i == 1);
                    dist[nx][ny].second = dist[cur.first][cur.second].second + (i == 3);
                    q.push({nx, ny});
                    nx--;
                }
            }
        }
    }
}
void solve() {
    cin >> n >> m >> r >> c >>  x >> y;
    grid = vector<vector<char>>(n , vector<char>(m));
    dist = vector<vector<pair<ll ,ll>>>(n , vector<pair<ll ,ll>>(m , {10e10 , 10e10}));
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < m; ++j) {
            cin >> grid[i][j];
        }
    }

    bfs(r - 1, c - 1);
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < m; ++j) {
            if(dist[i][j].first <= y && dist[i][j].second <= x)
            {
//                cout << '+';
                ans++;
            }
            else
            {
//                cout << grid[i][j];
            }
        }
//        cout << nl;
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
//    cin >> t;
    while(t--)
    {
        solve();
    }

    return 0;
}