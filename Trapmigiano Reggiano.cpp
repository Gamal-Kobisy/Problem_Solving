// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/contest/2071/problem/C
#include <bits/stdc++.h>
#define ll long long
#define nl '\n'
#define sp ' '
#define all(a) a.begin(),a.end()
#define allr(a) a.rbegin(),a.rend()
#define no cout<<"NO\n"
#define yes cout<<"YES\n"
#define ENG_GAMAL ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;
// ————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
const int N = 1e5 + 5, M = 1e3, LOG = 20, inf = 0x3f3f3f3f;
ll infLL = 0x3f3f3f3f3f3f3f3f;
ll n , st , ed;
vector<vector<ll>>adj(N);
vector<ll>road(N) , parent(N) , subtree_size(N);

void dfs1(ll v = st , ll par = -1)
{
    parent[v] = par;
     if(v == ed)
     {
         ll curr = ed;
         while (curr != -1)
         {
             road[curr] = 1;
             curr = parent[curr];
         }
     }
     for(ll u : adj[v])
     {
         if(u == par)
             continue;
         dfs1(u , v);
     }
}

ll dfs2(ll v, ll par) {
    ll size = 1;
    for (ll u : adj[v]) {
        if (u == par || road[u]) continue;
        size += dfs2(u, v);
    }
    return subtree_size[v] = size;
}

void solve() {
    cin >> n >> st >> ed;
    for (ll i = 0; i <= n; ++i) {
        adj[i].clear();
        road[i] = parent[i] = subtree_size[i] = 0;
    }
    for (ll i = 0; i < n - 1; ++i) {
        ll a , b;
        cin >> a >> b;
        adj[a].emplace_back(b);
        adj[b].emplace_back(a);
    }
    dfs1();
    if(dfs2(st , -1) != dfs2(ed , -1))
        return void(cout << -1 << nl);
    cout << dfs2(st , -1) << sp << dfs2(ed , -1) << nl;
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
    while (t--)
    {
        solve();
    }

    return 0;
}