// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/problemset/problem/916/E
#include <bits/stdc++.h>
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
#define fr first
#define sc second
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
const int N = 1e5 + 5, M = 1e3, LOG = 20, inf = 0x3f3f3f3f;
ll infLL = 0x3f3f3f3f3f3f3f3f;

vector<int> adj[N];
int n, q, depth[N], up[N][LOG], timer, tin[N], tout[N] , par[N];
ll sum[N][LOG];

void dfs(int u, int p) {
    tin[u] = timer++;
    par[u] = p;
    for (auto v: adj[u]) {
        if (v == p)continue;
        depth[v] = depth[u] + 1;
        up[v][0] = u;

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
    timer = 1;
    for (int i = 1; i <= n; ++i) {
        depth[i] = 0;
        tin[i] = tout[i] = 0;
    }
    depth[1] = 0;
    up[1][0] = 1;
    dfs(1, 0);
    for (int j = 1; j < LOG; ++j) {
        for (int i = 1; i <= n; ++i) {
            up[i][j] = up[up[i][j - 1]][j - 1];
        }
    }
}

struct SEG {
    ll sum = 0;

    SEG() {}
    SEG(ll x){
        sum = x;
    }
};

struct LAZY {
    ll add = 0;

    LAZY() {}
    LAZY(ll val){
        add = val;
    }
};

struct segTree {

#define LF 2*x+1
#define RT 2*x+2
#define md (lx+rx)/2

    int n;
    int sz = 1;
    vector<SEG> seg;
    vector<LAZY> lazy;

    segTree(int n){
        this->n = n;

        while(sz < n)
            sz *= 2;

        seg.assign(2 * sz , SEG());
        lazy.assign(2 * sz , LAZY());
    }

    SEG merge(SEG lf , SEG rt){
        SEG ret;
        ret.sum = lf.sum + rt.sum;
        return ret;
    }

    void propagate(int x, int lx, int rx) {
        if (lazy[x].add == 0) return;

        seg[x].sum += lazy[x].add * (rx - lx + 1);

        if (lx != rx) {
            lazy[LF].add += lazy[x].add;
            lazy[RT].add += lazy[x].add;
        }
        lazy[x] = LAZY();
    }

    void build(vector<int> &v , int x , int lx , int rx){

        if(lx == rx){
            if(lx < n)
                seg[x] = SEG(v[lx]);
            return;
        }

        build(v , LF , lx , md);
        build(v , RT , md + 1 , rx);

        seg[x] = merge(seg[LF] , seg[RT]);
    }

    void build(vector<int> &v){
        build(v , 0 , 0 , sz - 1);
    }

    void update(int l, int r, ll val, int x, int lx, int rx){
        propagate(x, lx, rx);

        if(rx < l || lx > r)
            return;

        if(l <= lx && rx <= r){
            lazy[x].add += val;

            propagate(x, lx, rx);
            return;
        }
        update(l , r , val , LF , lx , md);
        update(l , r , val , RT , md + 1 , rx);

        seg[x] = merge(seg[LF] , seg[RT]);
    }

    void update(int l , int r , ll val){
        update(l , r , val , 0 , 0 , sz - 1);
    }

    SEG query(int l , int r , int x , int lx , int rx){
        propagate(x, lx, rx);

        if(rx < l || lx > r)
            return SEG();

        if(l <= lx && rx <= r)
            return seg[x];

        return merge(
                query(l , r , LF , lx , md),
                query(l , r , RT , md + 1 , rx)
        );
    }

    SEG query(int l , int r){
        return query(l , r , 0 , 0 , sz - 1);
    }

#undef LF
#undef RT
#undef md
};

void TC() {
    cin >> n >> q;
    vector<int>val(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> val[i];
    }
    for (int i = 0; i < n - 1; ++i) {
        int u , v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    build();
    segTree seg(n + 1);
    for(int i = 1 ; i <= n ; i++){
        seg.update(tin[i] , tin[i] , val[i]);
    }
    int root = 1;
    auto dynamicLca = [&](int u , int v){
        int lca1 = LCA(u , v);
        int lca2 = LCA(u , root);
        int lca3 = LCA(v , root);
        int res = lca1;
        if (depth[lca2] > depth[res]) res = lca2;
        if (depth[lca3] > depth[res]) res = lca3;
        return res;
    };
    auto update_subtree = [&](int u, ll x) {
        if (u == root) {
            seg.update(1, n, x);
        } else if (isAncestor(u, root)) {
            int child = Kthancestor(root, depth[root] - depth[u] - 1);
            seg.update(1, n, x);
            seg.update(tin[child], tout[child], -x);
        } else {
            seg.update(tin[u], tout[u], x);
        }
    };
    auto query_subtree = [&](int u) {
        if (u == root) {
            return seg.query(1, n).sum;
        } else if (isAncestor(u, root)) {
            int child = Kthancestor(root, depth[root] - depth[u] - 1);
            return seg.query(1, n).sum - seg.query(tin[child], tout[child]).sum;
        } else {
            return seg.query(tin[u], tout[u]).sum;
        }
    };
    while(q--){
        int ty , u , v , x;
        cin >> ty;
        if(ty == 1){
            cin >> v;
            root = v;
        }else if(ty == 2){
            cin >> u >> v >> x;
            int lca = dynamicLca(u , v);
            update_subtree(lca, x);
        }else{
            cin >> u;
            cout << query_subtree(u) << nl;
        }
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