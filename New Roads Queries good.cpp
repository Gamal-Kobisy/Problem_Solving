// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://cses.fi/problemset/task/2101
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


struct DSU{
    vector<int> par , sz , ans;
    vector<vector<pii>> queries;

    DSU(int n, int q) : par(n) , sz(n , 1), queries(n), ans(q, -1) {
        iota(all(par) , 0);
    }

    int find(int x){
        if(x == par[x]) return x;
        else return par[x] = find(par[x]);
    }

    void add_query(int u, int v, int idx) {
        if(u == v) return void(ans[idx] = 0);
        queries[u].pb({v, idx});
        queries[v].pb({u, idx});
    }

    void merge(int x , int y , int w){
        x = find(x);
        y = find(y);
        if(x == y) return;
        if(sz[x] > sz[y]) swap(x , y);

        for(auto& q : queries[x]){
            if(find(q.fr) == y){
                ans[q.sc] = w;
            }else{
                queries[y].pb(q);
            }
        }
        queries[x].clear();

        sz[y] += sz[x];
        par[x] = y;
    }
};

void TC() {
    int n, m, q;
    cin >> n >> m >> q;
    DSU dsu(n + 1 , q);
    vector<pii>edges(m);
    for(auto &[a , b] : edges) cin >> a >> b;
    for (int i = 0; i < q; ++i) {
        int u , v;
        cin >> u >> v;
        dsu.add_query(u , v , i);
    }
    for (int i = 0; i < m; ++i) {
        auto [u, v] = edges[i];
        dsu.merge(u , v , i + 1);
    }
    for (int i = 0; i < q; ++i) {
        cout << dsu.ans[i] << nl;
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