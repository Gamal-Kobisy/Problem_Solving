// LINK : https://cses.fi/problemset/task/1669/
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
const ll N = 1e5 + 1 ;
ll n , m;
vector<vector<ll>> adj(N);
vector<bool> vis(N , false);
ll start = - 1 , last;
vector<ll> parent(N);

bool dfs(ll v , ll par)
{
    vis[v] = true;
    parent[v] = par;
    for(ll u : adj[v])
    {
        if(u == par)
        {
            continue;
        }
        if(vis[u])
        {
            start = u;
            last = v;
            return true;
        }
        parent[u] = v;
        if(dfs(u , v))
        {
            return true;
        }
    }
    return false;
}
void solve() {

    cin >> n >> m;
    for (ll i = 0; i < m; ++i) {
        ll a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (ll i = 1; i <= n; ++i) {
        if(!vis[i] && dfs(i , -1))
        {
            break;
        }
    }
    if(start == -1)
    {
        cout << "IMPOSSIBLE" << nl;
    }
    else
    {
        vector<ll>ans;
        ans.push_back(start);
        for (ll i = last; i != start ; i = parent[i]) {
            ans.push_back(i);
        }
        ans.push_back(start);
        cout << ans.size() << nl;
        for (ll i: ans) {
            cout << i << ' ';
        }
        cout << nl;
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