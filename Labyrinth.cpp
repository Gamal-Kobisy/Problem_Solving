// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://cses.fi/problemset/task/1193
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
const int N = 1e3 + 5, M = 1e3, LOG = 20, inf = 0x3f3f3f3f;
ll infLL = 0x3f3f3f3f3f3f3f3f;
int n , m;
vector<string>grid(N);
vector<vector<int>>par(N , vector<int>(N , -1));
vector<vector<bool>>vis(N , vector<bool>(N));
string di[] = {"D", "L", "R", "U", "DR", "DL", "UR", "UL"};
int dx[] = {1, 0, 0, -1, 1, -1, 1, -1};
int dy[] = {0, -1, 1, 0, 1, -1, -1, 1};
int knightx[] = {2, 2, -2, -2, 1, 1, -1, -1};
int knighty[] = {1, -1, 1, -1, 2, -2, 2, -2};
bool valid(int x , int y)
{
    return x >= 0 and x < n and y >= 0 and y <= m and not vis[x][y] and grid[x][y] != '#';
}

void bfs(pair<int , int> start)
{
    queue<pair<int , int>>q;
    q.emplace(start);
    vis[start.first][start.second] = true;
    while(not q.empty())
    {
        auto [x , y] = q.front();
        q.pop();
        for(int i = 0 ; i < 4 ; i++)
        {
            int nx  = x + dx[i] , ny = y + dy[i];
            if(valid(nx , ny))
            {
                q.emplace(nx , ny);
                par[nx][ny] = i;
                vis[nx][ny] = true;
            }
        }
    }
}
void solve() {
    cin >> n >> m;
    pair<int , int> st , ed;
    for(int i = 0 ; i < n ; i++)
    {
        cin >> grid[i];
        for(int j = 0 ; j < m ; j++)
        {
            if(grid[i][j] == 'A')
                st = {i , j};
            if(grid[i][j] == 'B')
                ed = {i , j};
        }
    }
    bfs(st);
    if(not vis[ed.first][ed.second])
        return void(no);
    string path;
    auto [x , y] = ed;
    while(par[x][y] != -1)
    {
        path += di[par[x][y]];
        int nx = x - dx[par[x][y]] , ny = y - dy[par[x][y]];
        x = nx , y = ny;
    }
    reverse(all(path));
    yes;
    cout << path.size() << nl << path << nl;
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
//     cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}