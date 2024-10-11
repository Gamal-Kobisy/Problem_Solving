// LINK :
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
int r , c , x , y , X , Y;
vector<string>grid;
vector<vector<ll>>dist;
int dx[] = {-1, 0, 1, 0, -1, 1, 1, -1};
int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};
char di[] = {'U', 'R', 'D', 'L'};
int knightx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int knighty[] = {1, 2, 2, 1, -1, -2, -2, -1};

bool valid(int i , int j)
{
    return (i < r && i >= 0 && j < c && j >= 0 && dist[i][j] == 1e9);
}
void bfs(int i , int j)
{
    deque<pair<ll ,ll>>q;
    q.push_front({i , j});
    dist[i][j] = 0;
    while (!q.empty())
    {
        auto cur = q.front();
        q.pop_front();
        for (ll k = 0; k < 4; ++k) {
            int nx = cur.first + dx[k] , ny = cur.second + dy[k];
            if(valid(nx , ny))
            {
                dist[nx][ny] = dist[cur.first][cur.second] + (grid[nx][ny] - '0');
                if(grid[nx][ny] - '0')
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
    cin >> r >> c >> x >> y >> X >> Y;
    grid = vector<string>(r);
    dist = vector<vector<ll>>(r , vector<ll>(c , 1e9));
    for (ll i = 0; i < r; ++i) {
        cin >> grid[i];
    }
    bfs(x - 1 , y - 1);
//    for (ll i = 0; i < r; ++i) {
//        for (ll j = 0; j < c; ++j) {
//            cout << dist[i][j] << ' ';
//        }
//        cout << nl;
//    }
    cout << dist[X - 1][Y - 1] << nl;
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