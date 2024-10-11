// LINK : https://vjudge.net/contest/657524#problem/X
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
int n , m;

int dx[] = {-1, 0, 1, 0, -1, 1, 1, -1};
int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};
char di[] = {'U', 'R', 'D', 'L'};
int knightx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int knighty[] = {1, 2, 2, 1, -1, -2, -2, -1};

int dx1[] = {-1 , -1 , -1 , -1 , +1 , +1 , +1 , +1 , +0 , +0 , +0 , +0};
int dy1[] = {+0 , +0 , +0 , +0 , +0 , +0 , +0 , +0 , -1 , -1 , +1 , +1};

int dx2[] = {-1 , -1 , +0 , +0 , +1 , +1 , +0 , +0 , -1 , +1 , -1 , +1};
int dy2[] = {+1 , -1 , -1 , +1 , +1 , -1 , +1 , -1 , -1 , -1 , +1 , +1};

vector<vector<char>>grid;

bool valid(int x , int y)
{
    return (x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == '*');
}
bool dfs(int x , int y)
{
    vector<pair<int , int>>pairs{{x , y}};
    int cnt = 1;
    for (ll i = 0; i < 8; ++i) {
        int nx = x + dx[i] , ny = y + dy[i];
        if(valid(nx , ny))
        {
            cnt++;
        }
    }
    if(cnt != 3){
        return false;
    }
    for (ll i = 0; i < 12; ++i) {
        int nx1 = x + dx1[i] , ny1 = y + dy1[i];
        int nx2 = x + dx2[i] , ny2 = y + dy2[i];
        if(valid(nx1 , ny1) && valid(nx2 , ny2))
        {
            pairs.emplace_back(nx1 , ny1);
            pairs.emplace_back(nx2 , ny2);
        }
    }
    return (pairs.size() == 3);
}
void solve() {
    cin >> n >> m;
    grid = vector<vector<char>>(n , vector<char>(m));

    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < m; ++j) {
            cin >> grid[i][j];
        }
    }

    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < m; ++j) {
            if(grid[i][j] == '*')
            {
                if(!dfs(i , j))
                {
                    no;
                    return;
                }
            }
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