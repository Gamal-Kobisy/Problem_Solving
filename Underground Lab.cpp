// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/problemset/problem/781/C
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
const int N = 2e5 + 5, M = 1e3, LOG = 20, inf = 0x3f3f3f3f;
ll infLL = 0x3f3f3f3f3f3f3f3f;

int tin[N], tout[N] , path[2 * N] , timer;
bool vis[N];
vector<int> adj[N];
void dfs(int u) {
    vis[u] = true;
    tin[u] = timer++;
    path[tin[u]] = u;
    for (auto v: adj[u]) {
        if (vis[v]) continue;
        dfs(v);
        path[timer++] = u;
    }

    tout[u] = timer - 1;
}
bool isAncestor(int u, int v) {
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}
void init(int n) {
    timer = 1;
    memset(tin, 0, (n + 1) * sizeof(int));
    memset(tout, 0, (n + 1) * sizeof(int));
    memset(vis , 0 , (n + 1) * sizeof(int));
    for (int i = 0; i <= n; i++) {
        adj[i].clear();
    }
}

void TC() {
    int n , m , k;
    cin >> n >> m >> k;
    init(n);
    for (int i = 0; i < m; ++i) {
        int u , v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(1);
    int idx = 1 , limit = ceil(2.0 * n / k);
    for (int i = 0; i < k; ++i) {
        vector<int>road;
        while(road.size() < limit and idx < timer){
            road.pb(path[idx++]);
        }
        if(road.empty()) road.pb(1);
        cout << road.size() << sp;
        for(int i : road) cout << i << sp;
        cout << nl;
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