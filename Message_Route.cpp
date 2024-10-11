// LINK : https://cses.fi/problemset/task/1667/
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
const ll N = 2e5 + 1;
ll n , m;
vector<vector<ll>>adj(N);
vector<ll>dist(N) , parent(N);

void bfs()
{
    queue<ll>q;
    q.emplace(1);
    dist[1] = 1;
    while (!q.empty())
    {
        ll curr = q.front();
        q.pop();
        for(ll u : adj[curr])
        {
            if(dist[u] == 1e9)
            {
                q.emplace(u);
                dist[u] = dist[curr] + 1;
                parent[u] = curr;
            }
        }
    }
}
void solve() {
    cin >> n >> m;

    for (ll i = 0; i < m; ++i) {
        ll a , b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (ll i = 0; i < n; ++i) {
        dist[i + 1] = 1e9;
        parent[i + 1] = -1;
    }

    bfs();

    if(dist[n] == 1e9)
    {
        cout << "IMPOSSIBLE" << nl;
        return;
    }
    cout << dist[n] << nl;
    vector<ll>ans{n};
    ll cur = parent[n];
    while (cur != -1)
    {
        ans.push_back(cur);
        cur = parent[cur];
    }
    reverse(all(ans));
    for (ll i: ans) {
        cout << i << ' ';
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
}z