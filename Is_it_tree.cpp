// LINK : https://www.spoj.com/problems/PT07Y/
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
template <typename T>
void get_vec(vector<T>& v) {
    for (ll i = 0; i < v.size(); ++i) {
        cin >> v[i];
    }
}
template <typename T>
void out_vec(vector<T>& v) {
    for (ll i = 0; i < v.size(); ++i) {
        cout << v[i] << ' ';
    }
    cout << nl;
}
// ————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
const ll N = 1e5 + 1;

vector<vector<ll>>adj(N);
vector<bool>vis(N , false);
bool cycle;
void dfs(ll v , ll parent)
{
    vis[v] = true;
    for (ll u: adj[v]) {
        if(parent == u)
        {
            continue;
        }
        if(vis[u])
        {
            cycle = true;
            return;
        }
        else
        {
            dfs(u , v);
        }
    }
}

void solve() {
    cycle = false;
    ll n , m;
    cin >> n >> m;
    if(m != n - 1)
    {
        no;
        return;
    }
    for (ll i = 0; i < m; ++i) {
        ll a , b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (ll i = 1; i <= n; ++i) {
        if(!vis[i])
        dfs(i ,-1);
    }
    (cycle)? no : yes;
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