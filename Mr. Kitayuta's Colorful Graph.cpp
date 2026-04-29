// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/problemset/problem/506/D
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
int curID , curColor;
vector<int>adj[N];
vector<pii> info[N];
vector<pii>edges_of_color[N];
vector<bool>vis(N);
map<pii , int>cache;
void dfs(int u){
    vis[u] = true;
    info[u].pb({curColor , curID});
    for(int v : adj[u]){
        if(not vis[v]) dfs(v);
    }
}

void TC() {
    int n , m , q;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a , b , c;
        cin >> a >> b >> c;
        edges_of_color[c].pb({a , b});
    }
    int ID = 0;
    for (int c = 0; c < N; ++c) {
        auto edges = edges_of_color[c];
        curColor = c;
        vector<int> used;
        for(auto [a , b] : edges){
            adj[a].pb(b);
            adj[b].pb(a);
            used.pb(a);
            used.pb(b);
        }
        sort(all(used));
        used.erase(unique(all(used)) , used.end());
        for(int node : used){
            if(not vis[node]){
                curID = ID++;
                dfs(node);
            }
        }
        for(int node : used){
            adj[node].clear();
            vis[node] = false;
        }
    }
    for (int i = 1; i <= n; ++i) {
        sort(all(info[i]));
    }
    cin >> q;
    while(q--){
        int u , v;
        cin >> u >> v;
        if(info[u].size() > info[v].size()) swap(u , v);
        if(cache.count({u , v})){
            cout << cache[{u , v}] << nl;
            continue;
        }
        int cnt = 0;
        for(auto p : info[u]){
            auto it = lower_bound(all(info[v]) , p);
            if(it != info[v].end() and *it == p) cnt++;
        }
        cache[{u , v}] = cnt;
        cout << cnt << nl;
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