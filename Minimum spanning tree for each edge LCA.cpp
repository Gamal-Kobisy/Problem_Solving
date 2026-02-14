// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/problemset/problem/609/E
#pragma GCC optimize("O3")
#pragma GCC optimize ("unroll-loops")
#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
#pragma GCC target("avx2")
using namespace std;
#define ll long long
#define ld long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define PI acos(-1)
#define Ones(n) __builtin_popcountll(n)
#define MSB(n) (63 - __builtin_clzll(n))
#define LSB(n) (__builtin_ctzll(n))
#define mem(arrr, xx) memset(arrr,xx,sizeof arrr)
#define fi first
#define se second
#define pb push_back
#define all(a) a.begin(),a.end()
#define allr(a) a.rbegin(),a.rend()
#define no cout<<"NO\n"
#define yes cout<<"YES\n"
#define imp cout<<"IMPOSSIBLE\n"
#define nl '\n'
#define sp ' '
#define ENG_GAMAL ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;
// ————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
const int N = 2e5 + 5, M = 1e3, LOG = 20, inf = 0x3f3f3f3f;
ll infLL = 0x3f3f3f3f3f3f3f3f;

vector<pii> adj[N];
int n , m, q, depth[N], up[N][LOG] , mx[N][LOG], timer, tin[N], tout[N] , par[N];

void dfs(int u, int p) {
    tin[u] = timer++;
    for (auto [v , w]: adj[u]) {
        if (v == p)continue;
        depth[v] = depth[u] + 1;
        up[v][0] = u;
        mx[v][0] = w;
        dfs(v, u);
    }
    tout[u] = timer - 1;
}

bool isAncestor(int u, int v) {
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int Kthancestor(int u,int k){
    if(k > depth[u]) return -1;
    for (int j = LOG - 1; j >= 0; --j) {
        if(k&(1<<j)){
            u = up[u][j];
        }
    }
    return u;
}

int GetMax(int u , int k){
    int ret = -inf;
    for (int j = LOG - 1; j >= 0; --j) {
        if(k&(1<<j)){
            ret = max(ret , mx[u][j]);
            u = up[u][j];
        }
    }
    return ret;
}

int LCA(int u, int v) {
    if (depth[u] < depth[v])
        swap(u, v);
    int k = depth[u] - depth[v];
    u = Kthancestor(u , k);
    if (u == v)
        return u;
    for (int i = LOG - 1; i >= 0; --i) {
        if (up[u][i] != up[v][i]) {
            u = up[u][i];
            v = up[v][i];
        }
    }
    return up[u][0];
}

void build() {
    timer = 0;
    for (int i = 1; i <= n; ++i) {
        depth[i] = 0;
        tin[i] = tout[i] = 0;
    }
    depth[1] = 0;
    dfs(1, 0);
    for (int j = 1; j < LOG; ++j) {
        for (int i = 1; i <= n; ++i) {
            up[i][j] = up[up[i][j - 1]][j - 1];
            mx[i][j] = max(mx[i][j - 1] , mx[ up[i][j - 1] ][j - 1]);
        }
    }
}

struct DSU{
    vector<int>par , sz;

    DSU(int n) : par(n + 1) , sz(n + 1, 1) {iota(all(par) , 0);}

    int find(int x){
        if(x == par[x]) return x;
        else return par[x] = find(par[x]);
    }

    bool same(int x , int y){
        return find(x) == find(y);
    }

    bool merge(int x , int y){
        x = find(x);
        y = find(y);
        if(same(x , y)) return false;
        if(sz[x] > sz[y]) swap(x , y);
        sz[y] += sz[x];
        par[x] = y;
        return true;
    }
};

void TC() {
    cin >> n >> m;
    vector<array<int , 4>>edges(m);
    int I = 0;
    for(auto& [w , u , v, idx] : edges){
        cin >> u >> v >> w;
        idx = I;
        ++I;
    }
    sort(all(edges));
    ll MST = 0;
    DSU dsu(n);
    vector<bool>mstEdge(m);
    for(auto& [w , u , v , idx] : edges){
        if(dsu.merge(u , v)){
            MST += w;
            adj[u].pb({v , w});
            adj[v].pb({u , w});
            mstEdge[idx] = true;
        }
    }
    build();
    vector<ll>ans(m);
    for(auto& [w , u , v , idx] : edges){
        if(mstEdge[idx]){
            ans[idx] = MST;
        }else{
            int lca = LCA(u , v);
            int ku = depth[u] - depth[lca];
            int kv = depth[v] - depth[lca];
            int mxu = GetMax(u , ku);
            int mxv = GetMax(v , kv);
            ans[idx] = MST - max(mxu , mxv) + w;
        }
    }
    for (int i = 0; i < m; ++i) {
        cout << ans[i] << nl;
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
    ll tc = 1;
//     cin >> tc;
    while (tc--)
    {
        TC();
    }

    return 0;
}