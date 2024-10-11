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
const int N = 2e5 + 1;
int n , k , x , y ;
pair<int , int>y_dist;
vector<int>adj[N];
bool vis[N] , houses[N];
vector<vector<ll>>dist;
bool found = false;

void dfs(int v , pair<pair<int , int> , int>dis)
{
    vis[v] = true;
    if(houses[v])
    {
        dis.first.second = dis.first.first;
    }
    if(v == y)
    {
        y_dist = {dis.first.first , dis.second};
    }
    bool leaf = true;
    int idx = dis.second;
    for(int u : adj[v])
    {
        if(v == x){idx++;}
        if(!vis[u])
        {
            leaf = false;
            dfs(u , {{dis.first.first + 1, dis.first.second} , idx});
        }
    }
    if(leaf)
    {
        dist[dis.second - 1].emplace_back(dis.first.second);
    }
}

void solve() {
    cin >> n >> k;
    for (ll i = 0; i <= n; ++i) {
        adj[i].clear();
        vis[i] = false;
        houses[i] = false;
    }
    cin >> x >> y;
    for (ll i = 0; i < k; ++i) {
        int a;
        cin >> a ;
        houses[a] = true;
    }
    for (ll i = 0; i < n - 1; ++i) {
        int a , b;
        cin >> a >> b;
        adj[a].emplace_back(b);
        adj[b].emplace_back(a);
    }
    dist = vector<vector<ll>>((int)adj[x].size());
    ll total_dist = 0;
    dfs(x , {{0 , 0} , 0});
    for (ll i = 0; i < adj[x].size(); ++i) {
        if(dist[i].size() == 1)
        {
            total_dist += dist[i].front() * 2;
        }
        else
        {
            total_dist += dist[i].front();
            for(auto j : dist[i])
            {
                total_dist += j;
            }
        }
        for(auto j : dist[i])
        {
            cout << j << ' ';
        }
        cout << nl;
    }
    cout << y_dist.first << ' ' << y_dist.second << nl;
    cout << total_dist << nl;
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