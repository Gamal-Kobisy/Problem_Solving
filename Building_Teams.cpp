// LINK : https://cses.fi/problemset/task/1668/
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
vector<vector<int>>adj(1e5 + 1);
vector<short>color(1e5 + 1);
int n , m;
bool IMPOSSIBLE = false;
void dfs(int v , short team)
{
    color[v] = team;
    short adj_color =  team == 2? 1 : 2;
    for (int u: adj[v]) {
        if(color[u] && color[u] != adj_color)
        {
            IMPOSSIBLE = true;
            return;
        }
        if(!color[u])
        {
            dfs(u , adj_color);
        }
    }
}
void solve() {
    cin >> n >> m;
    for (ll i = 0; i < m; ++i) {
        int a , b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (ll i = 1; i <= n ; ++i) {
        dfs(i , (color[i] == 1)? 1 : 2);
    }
    if(IMPOSSIBLE)
    {
        cout << "IMPOSSIBLE" << nl;
        return;
    }
    for (ll i = 1; i <= n ; ++i) {
        cout << color[i] << ' ';
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