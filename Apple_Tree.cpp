// LINK : https://codeforces.com/problemset/problem/1843/D
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
ll n , q;
vector<vector<ll>>adj;
vector<bool>vis;
vector<ll>leafs;
int dfs(ll v)
{
    vis[v] = true;
    ll cnt = 0;
    bool leaf = true;
    for(ll u : adj[v])
    {
        if(!vis[u])
        {
            leaf = false;
            cnt += dfs(u);
        }
    }
    if(leaf)
    {
        leafs[v] = 1;
        return 1;
    }
    else
    {
        leafs[v] = cnt;
        return cnt;
    }
}

void solve() {
    cin >> n;
    adj = vector<vector<ll>>(n + 1);
    vis = vector<bool>(n + 1, false);
    leafs = vector<ll>(n + 1);
    for (ll i = 0; i < n - 1; ++i) {
        ll a , b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1);
    cin >> q;
    for (ll i = 0; i < q; ++i) {
        ll x , y;
        cin >> x >> y;
       cout << leafs[x] * leafs[y] << nl;
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
    cin >> t;
    while(t--)
    {
        solve();
    }

    return 0;
}