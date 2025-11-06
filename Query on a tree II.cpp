// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://www.spoj.com/problems/QTREE2/cstart=20
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
int n, q, depth[N], sum[N][LOG], up[N][LOG], timer, tin[N], tout[N] , par[N];

void dfs(int u, int p) {
    tin[u] = timer++;
    for (auto [v , w]: adj[u]) {
        if (v == p)continue;
        depth[v] = depth[u] + 1;
        up[v][0] = u;
        sum[v][0] = w;
        dfs(v, u);
    }
    tout[u] = timer - 1;
}

bool isAncestor(int u, int v) {
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int Kthancestor(int u,int k){
    for (int j = LOG - 1; j >= 0; --j) {
        if(k&(1<<j)){
            u = up[u][j];
        }
    }
    return u;
}

int GetSum(int u , int k){
    int ret = 0;
    for (int j = LOG - 1; j >= 0; --j) {
        if(k&(1<<j)){
            ret += sum[u][j];
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
            sum[i][j] = sum[i][j - 1] + sum[ up[i][j - 1] ][j - 1];
        }
    }
}

void TC() {
    cin >> n;
    for (int i = 1; i < n; ++i) {
        int a , b , w;
        cin >> a >> b >> w;
        adj[a].pb({b , w});
        adj[b].pb({a , w});
    }
    build();
    string choice;
    while (true){
        cin >> choice;
        if(choice == "DIST"){
            int a , b;
            cin >> a >> b;
            int lca = LCA(a , b);
            int ka = depth[a] - depth[lca];
            int kb = depth[b] - depth[lca];
            cout << GetSum(a , ka) + GetSum(b , kb) << nl;
        }else if(choice == "KTH"){
            int a , b , k;
            cin >> a >> b >> k;
            int lca = LCA(a , b);
            int dist = depth[a] + depth[b] - 2 * depth[lca];
            if(k <= depth[a] - depth[lca] + 1){
                cout << Kthancestor(a , k - 1) << nl;
            }else{
                cout << Kthancestor(b , dist - k + 1) << nl;
            }
        }else{
            break;
        }
    }
    for (int i = 0; i <= n; ++i) {
        adj[i].clear();
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