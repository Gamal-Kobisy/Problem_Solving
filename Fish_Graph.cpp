// LINK : https://codeforces.com/contest/1817/problem/B
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
ll n , m;
vector<vector<int>>adj , cycles;
vector<int>color ;
vector<int>parent;

void dfs(int v , int par)
{
    if(color[v] == 2)
    {
        return;
    }
    if(color[v] == 1)
    {
        vector<int>temp;
        int cur = par;
        temp.push_back(v);
        while (true) {
            if (cur == v)
                break;
            temp.push_back(cur);
            cur = parent[cur];
        }
        cycles.push_back(temp);
        return;
    }
    color[v] = 1;
    parent[v] = par;
    for(ll u : adj[v])
    {
        if(u != par)
        {
            dfs(u , v);
        }

    }
    color[v] = 2;
}

void solve(ll t) {
    cin >> n >> m;
    adj    = vector<vector<int>>(n + 1);
    color  = vector<int>(n + 1);
    parent = vector<int>(n + 1);
    cycles.clear();
    for (ll i = 0; i < m; ++i) {
        ll a , b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (ll i = 1; i <= n; ++i) {
        dfs(i , 0);
    }
    for(auto cycle : cycles)
    {
        vector<bool>vis(n + 1);
        for(ll node : cycle)
        {
            vis[node] = 1;
        }
        for(ll node : cycle)
        {
            vector<int>tail;
            for(ll u : adj[node])
            {
                if(!vis[u]){
                    tail.push_back(u);
                }
            }
            if(tail.size() >= 2)
            {
                yes;
                cout << cycle.size() + 2 << nl;
                for (ll i = 0; i < 2; ++i) {
                    cout << node << ' ' << tail[i] << nl;
                }
                for (ll i = 0; i < cycle.size(); ++i) {
                    cout << cycle[i] << ' ' << cycle[(i + 1) % cycle.size()] << nl;
                }
                return;
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
    cin >> t;
    while(t--)
    {
        solve(t + 1);
    }

    return 0;
}