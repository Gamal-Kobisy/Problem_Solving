// LINK : https://www.spoj.com/problems/KATHTHI/en/
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
const ll N = 1e3;
int n , m;
char grid[N][N];
int dist[N][N];

bool valid(ll x , ll y)
{
    return (x >= 0 && x < n && y >= 0 && y < m);
}
void bfs()
{
    deque<pair<int , int>>q;
    q.emplace_front(0 , 0);
    dist[0][0] = 0;

    while (!q.empty())
    {
        int x = q.front().first , y = q.front().second;
        q.pop_front();

        for (ll i = 0; i < 4; ++i) {
            int nx = x + dx[i] , ny = y + dy[i];
            bool b = grid[nx][ny] != grid[x][y];
            if(valid(nx , ny) && dist[nx][ny] > dist[x][y] + b)
            {
                dist[nx][ny] = dist[x][y] + b;
                if (b)
                {
                    q.emplace_back(nx , ny);
                }
                else
                {
                    q.emplace_front(nx , ny);
                }
            }
        }
    }
}

void solve() {
    cin >> n >> m;
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < m; ++j) {
            cin >> grid[i][j];
            dist[i][j] = 1e9;
        }
    }

    bfs();

    cout << dist[n - 1][m - 1] << nl;
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