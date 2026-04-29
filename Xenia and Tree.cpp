// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/problemset/problem/342/E
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
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
// ————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
const int N = 1e5 + 5, M = 2e5 + 5, LOG = 20, inf = 0x3f3f3f3f;
ll infLL = 0x3f3f3f3f3f3f3f3f;
const int SQ = 460;
int head[N], to[M], nxt[M], ne;

void init_graph() {
    ne = 0;
    mem(head, -1);
}

void addEdge(int u, int v) {
    to[ne] = v;
    nxt[ne] = head[u];
    head[u] = ne++;
}

void addBiEdge(int u, int v) {
    addEdge(u, v);
    addEdge(v, u);
}int n, q, depth[N], up[N][LOG], timer, tin[N], tout[N] , par[N], dist[N];

void dfs(int u, int p) {
    tin[u] = timer++;
    for (int e = head[u]; ~e; e = nxt[e]) {
        int v = to[e];
        if (v == p) continue;
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
        }
    }
}

void TC() {
    cin >> n >> q;
    init_graph();
    for (int i = 0; i < n - 1; ++i) {
        int a , b;
        cin >> a >> b;
        addBiEdge(a, b);
    }
    build();
    vector<int>painted = {1};
    auto bfs = [&](vector<int>& starts){
        queue<int>qu;
        for(int u : starts) dist[u] = 0 , qu.push(u);
        while(not qu.empty()){
            int u = qu.front();
            qu.pop();
            for (int e = head[u]; ~e; e = nxt[e]) {
                int v = to[e];
                if(dist[u] + 1 < dist[v]){
                    dist[v] = dist[u] + 1;
                    qu.push(v);
                }
            }
        }
    };
    mem(dist , inf);
    while(q--){
        int ty , u;
        cin >> ty >> u;
        if(ty&1){
            painted.pb(u);
            if(painted.size() == SQ){
                bfs(painted);
                painted.clear();
            }
        }else{
            int ans = dist[u];
            for(int v : painted){
                int lca = LCA(u , v);
                int cand = depth[u] + depth[v] - 2 * depth[lca];
                ans = min(ans , cand);
            }
            cout << ans << nl;
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