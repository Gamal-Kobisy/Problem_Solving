// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://csacademy.com/app/graph_editor/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define PI acos(-1)
#define Ones(n) __builtin_popcountll(n)
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
int n, q, depth[N], up[N][LOG], mx[N][LOG], mn[N][LOG], timer, tin[N], tout[N] , par[N];

void dfs(int u, int p) {
    tin[u] = timer++;
    for (auto [v , w]: adj[u]) {
        if (v == p)continue;
        depth[v] = depth[u] + 1;
        up[v][0] = u;
        mx[v][0] = w;
        mn[v][0] = w;
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
        if (k & (1 << j)) {
            ret = max(ret, mx[u][j]);
            u = up[u][j];
            if (!u) break;
        }
    }
    return ret;
}

int GetMin(int u , int k){
    int ret = inf;
    for (int j = LOG - 1; j >= 0; --j) {
        if (k & (1 << j)) {
            ret = min(ret, mn[u][j]);
            u = up[u][j];
            if (!u) break;
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
            mx[i][j] = max(mx[i][j-1], mx[ up[i][j-1] ][ j-1 ]);
            mn[i][j] = min(mn[i][j-1], mn[ up[i][j-1] ][ j-1 ]);
        }
    }
}

void TC() {
    cin >> n;
    for (int i = 1; i < n; ++i) {
        int a , b , w;
        cin >> a >> b >> w;
        adj[a].pb({b, w});
        adj[b].pb({a, w});
    }
    build();
    cin >> q;
    while(q--){
        int a , b;
        cin >> a >> b;
        int lca = LCA(a , b);
        int ka = depth[a] - depth[lca];
        int kb = depth[b] - depth[lca];
        int maxi = max(GetMax(a , ka) , GetMax(b , kb));
        int mini = min(GetMin(a , ka) , GetMin(b , kb));
        cout << mini << sp << maxi << nl;
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