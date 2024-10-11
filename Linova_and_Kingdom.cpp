// LINK : https://codeforces.com/problemset/problem/1337/C
#include <bits/stdc++.h>
#define ll long long
#define nl '\n'
#define all(a) a.begin(),a.end()
#define allr(a) a.rbegin(),a.rend()
#define no cout<<"NO\n"
#define yes cout<<"YES\n"
#define ENG_GAMAL ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T>
using ordered_set = tree<T, null_type, greater_equal<>, rb_tree_tag, tree_order_statistics_node_update>;

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
ll n , k , ans = 0;
vector<vector<ll>>adj(N);
vector<bool>vis(N) , ind(N);
vector<ll>road(N) , depth(N);
int dfs(ll v , ll d)
{
    vis[v] = true;
    ll c = 0;
    for(ll u : adj[v])
    {
        if(!vis[u])
        {
            c += dfs(u , d + 1);
            c++;
        }
    }
    depth[v] = d;
    road[v] += c;
    return c;
}

void dfs_happ(ll v , ll happ)
{
    vis[v] = true;
    if(ind[v])
    {
        ans += happ;
    }
    for(ll u : adj[v])
    {
        if(!vis[u])
        {
            dfs_happ(u , (ind[v]? happ : happ + 1));
        }
    }
}
void solve() {
    cin >> n >> k;
    for (ll i = 0; i < n - 1; ++i) {
        ll a , b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1 , 1);
    vector<pair<pair<ll , ll>, ll>>cities(n);
    for (ll i = 1; i <= n; ++i) {
        cities[i - 1] = {{road[i] , -depth[i]}, i};
    }
    sort(all(cities) , [](pair<pair<ll,ll> , ll>a , pair<pair<ll , >>));
    for (ll i = 0; i < k; ++i) {
        ind[cities[i].second] = true;
    }
    vis = vector<bool>(N , false);
    dfs_happ(1 , 0);
    cout << ans << nl;
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