// LINK : https://codeforces.com/problemset/problem/505/B
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
vector<vector<pair<ll , ll>>>adj;
vector<vector<bool>>vis;

bool dfsC(ll v , ll u , ll color)
{
    vis[v][color] = true;
    if(v == u)
    {
        return true;
    }
    bool can = false;
    for(auto i : adj[v])
    {
        if(i.second == color && !vis[i.first][i.second])
        {
            can += dfsC(i.first , u ,i.second);
        }
    }
    return can;
}

ll dfs(ll v , ll u)
{
    ll cnt = 0;
    for(auto i : adj[v])
    {
        if(!vis[i.first][i.second])
        {
            cnt += dfsC(i.first , u ,i.second);
        }
    }
    return cnt;
}

void solve() {
    cin >> n >> m;
    adj = vector<vector<pair<ll,ll>>>(n + 1);
    vis = vector<vector<bool>>(n + 1 , vector<bool>(m + 1));
    for (ll i = 0; i < m; ++i) {
        ll a , b , c;
        cin >> a >> b >> c;
        adj[a].push_back({b , c});
        adj[b].push_back({a , c});
    }
    ll q;
    cin >> q;
    for (ll i = 0; i < q; ++i) {
        ll u , v;
        cin >> u >> v;
        cout << dfs(v , u) << nl;
        vis = vector<vector<bool>>(n + 1 , vector<bool>(m + 1));
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