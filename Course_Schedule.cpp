// LINK : https://cses.fi/problemset/task/1679
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
const ll N = 1e5 + 1;
ll n , m;
vector<ll> adj[N];
vector<bool>vis(N , false) , acs(N , false);
vector<ll>ans;
bool cycle;
void dfs(ll v)
{
    vis[v] = true;
    acs[v] = true;
    for(ll u : adj[v])
    {
        if(acs[u])
        {
            cycle = true;
            return;
        }
        if(!vis[u])
        {
            dfs(u);
        }
    }
    acs[v] = false;
    ans.push_back(v);
}
void solve() {
    cycle = false;
    cin >> n >> m;
    for (ll i = 0; i < m; ++i) {
        ll  a, b;
        cin >> a >> b;
        adj[b].push_back(a);
    }
    for (ll i = 1; i <= n; ++i) {
        if(!vis[i])
        {
            dfs(i);
        }
        if(cycle)
        {
            cout << "IMPOSSIBLE" << nl;
            return;
        }
    }
    for (ll i = 0; i < n; ++i) {
        cout << ans[i] << ' ';
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
//    cin >> t;
    while(t--)
    {
        solve();
    }

    return 0;
}