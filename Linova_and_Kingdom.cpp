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
ll n , k;
vector<vector<ll>>adj(N);
vector<bool>vis(N) , industry(N);

ordered_set<ll>happinesses;

void dfs(ll v , ll happ)
{
    if(industry[v])
    {
        happinesses.insert(happ);
    }
    vis[v] = true;
    for(ll u : adj[v])
    {
        if(!vis[u])
        {
            dfs(u , (industry[u] ? happ : happ + 1));
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
    ll leafs = 0;
    for (ll i = 2; i <= n; ++i) {
        if(adj[i].size() == 1)
        {
            industry[i] = true;
            leafs++;
        }
    }
    dfs(1 , 1);
    ll ans = 0;
    auto it = happinesses.begin();
    for (ll i = 0; i < k; ++i) {
        ans += *it;
        it++;
    }
    cout << (leafs < k ? ans + k - leafs : ans) << nl;
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