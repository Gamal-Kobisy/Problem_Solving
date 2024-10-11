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
int n , m , ans = -1;
int dx[] = {-1, 0, 1, 0, -1, 1, 1, -1};
int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};
char di[] = {'U', 'R', 'D', 'L'};
int knightx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int knighty[] = {1, 2, 2, 1, -1, -2, -2, -1};
vector<vector<int>>rows , cols , dist;
queue<pair<int , int>>q;

void bfs(int r , int c)
{
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
//        cout << x  << ' ' << y << nl;
        q.pop();
        if(x == 0)
        {
            ans = dist[x][y];
            return;
        }

        while (!rows[x].empty())
        {
            int col = rows[x].back();
            if(!dist[x][col])
            {
                dist[x][col] = dist[x][y] + 1;
                q.emplace(x , col);
            }
            rows[x].pop_back();
        }

        while (!cols[y].empty())
        {
            int row = cols[y].back();
            if(!dist[row][y])
            {
                dist[row][y] = dist[x][y] + 1;
                q.emplace(row , y);
            }
            cols[y].pop_back();
        }
    }
}

void solve()
{
    cin >> n >> m;
    rows = vector<vector<int>>(n);
    cols = vector<vector<int>>(m);
    dist = vector<vector<int>>(n , vector<int>(m , 0));
    string s;

    for (ll i = 0; i < n; ++i) {
        cin >> s;
        for (ll j = 0; j < m; ++j) {
            if(s[j] == '#')
            {
                rows[i].push_back(j);
                cols[j].push_back(i);
                if(i == n - 1)
                {
                    q.emplace(i , j);
                    dist[i][j] = 0;
                }
            }
        }
    }
    if(rows[0].empty() || rows[n - 1].empty())
    {
        cout << -1 << nl;
        return;
    }
    bfs(n - 1 ,m - 1);
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