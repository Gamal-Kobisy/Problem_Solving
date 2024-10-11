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
ll n;
vector<vector<ll>>adj;
map<pair<ll , ll> , ll>wight;
vector<bool>vis;

void dfs(ll v , ll w)
{
    vis[v] = true;
    for(ll &u : adj[v])
    {
        if(!vis[u])
        {
            wight[{min(u , v) , max(u , v)}] = w;
            dfs(u , 5 - w);
        }
    }
}

void solve() {
   cin >> n ;
   adj = vector<vector<ll>>(n + 1);
   vis = vector<bool>(n + 1 , false);
   vector<pair<ll , ll>>edges(n - 1);
    for (ll i = 0; i < n - 1; ++i) {
        ll a , b;
        cin >> a >> b;
        edges[i] = {a , b};
        adj[a].emplace_back(b);
        adj[b].emplace_back(a);
    }
    for (ll i = 1; i <= n; ++i) {
        if(adj[i].size() > 2)
        {
            cout << -1 << nl;
            return;
        }
    }
    for (ll i = 1; i <= n; ++i) {
        if(adj[i].size() == 1)
        {
            dfs(i , 3);
            break;
        }
    }
    for (ll i = 1; i <= n - 1; ++i) {
        ll a = edges[i - 1].first , b = edges[i - 1].second;
        cout << wight[{min(a , b) , max(a , b)}] << ' ';
    }
    cout << nl;
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