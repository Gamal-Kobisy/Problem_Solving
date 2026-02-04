// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/problemset/problem/1843/F2
//#pragma GCC optimize("O3")
//#pragma GCC optimize ("unroll-loops")
//#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
//#pragma GCC target("avx2")
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

struct val{
    int mxPre , mxSuf , mxSub;
    int mnPre , mnSuf , mnSub;
    int sum;

    val() {
        mxPre = mxSuf = mxSub = 0;
        mnPre = mnSuf = mnSub = 0;
        sum = 0;
    }

    val(int v){
        mxPre = mxSuf = mxSub = max(0 , v);
        mnPre = mnSuf = mnSub = min(0 , v);
        sum = v;
    }
};

val merge(val l , val r){
    val res;
    res.mxPre = max(l.mxPre , l.sum + r.mxPre);
    res.mnPre = min(l.mnPre , l.sum + r.mnPre);

    res.mxSuf = max(r.mxSuf , r.sum + l.mxSuf);
    res.mnSuf = min(r.mnSuf , r.sum + l.mnSuf);

    res.mxSub = max({l.mxSub , r.mxSub , l.mxSuf + r.mxPre});
    res.mnSub = min({l.mnSub , r.mnSub , l.mnSuf + r.mnPre});

    res.sum = l.sum + r.sum;

    return res;
}

vector<int> adj[N];
int n, nodeCnt, q, depth[N], up[N][LOG], timer, tin[N], tout[N] , par[N] , weight[N];
val value[N][LOG];

void dfs(int u, int p) {
    tin[u] = timer++;
    for (auto v: adj[u]) {
        if (v == p)continue;
        depth[v] = depth[u] + 1;
        up[v][0] = u;
        value[v][0] = val(weight[v]);
        dfs(v, u);
    }
    tout[u] = timer - 1;
}

bool isAncestor(int u, int v) {
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

val getValueUp(int u , int k){
    val res;
    for (int j = LOG - 1; j >= 0; --j) {
        if(k&(1<<j)){
            res = merge(res , value[u][j]);
            u = up[u][j];
        }
    }
    return res;
}

val getValueDown(int u , int k){
    val res;
    for (int j = LOG - 1; j >= 0; --j) {
        if(k&(1<<j)){
            res = merge(value[u][j] , res);
            u = up[u][j];
        }
    }
    return res;
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
    weight[1] = 1;
    dfs(1, 0);
    for (int j = 1; j < LOG; ++j) {
        for (int i = 1; i <= nodeCnt; ++i) {
            up[i][j] = up[up[i][j - 1]][j - 1];
            value[i][j] = merge(value[i][j - 1] , value[ up[i][j-1] ][ j-1 ]);
        }
    }
}

void TC() {
    cin >> n;
    for(int i = 1; i <= n + 2; i++) {
        adj[i].clear();
    }
    nodeCnt = 1;
    vector<tuple<int , int , int>>queries;
    for (int i = 0; i < n; ++i) {
        char type;
        cin >> type;
        if(type == '+'){
            nodeCnt++;
            int b , w;
            cin >> b >> w;
            weight[nodeCnt] = w;
            adj[nodeCnt].pb(b);
            adj[b].pb(nodeCnt);
        }else{
            int u , v , k;
            cin >> u >> v >> k;
            queries.pb({u , v , k});
        }
    }
    build();
    for(auto [u , v , k] : queries){
        int lca = LCA(u , v);
        int ku = depth[u] - depth[lca];
        int kv = depth[v] - depth[lca];
        val leftPath = getValueUp(u , ku);
        val rightPath = getValueUp(v , kv);
        swap(rightPath.mxPre, rightPath.mxSuf);
        swap(rightPath.mnPre, rightPath.mnSuf);
        val lcaVal = val(weight[lca]);
        val ans = merge(leftPath, merge(lcaVal, rightPath));
        if(k <= ans.mxSub && k >= ans.mnSub) yes;
        else no;
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
     cin >> tc;
    while (tc--)
    {
        TC();
    }

    return 0;
}