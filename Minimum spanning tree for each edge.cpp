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

struct DSU{
    vector<int>par , sz;

    DSU(int n) : par(n) , sz(n , 1) {iota(all(par) , 0);}

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
struct DSU2{
    vector<int> par , sz;
    vector<vector<pii>> queries;
    vector<int> queryAns;

    DSU2(int n, int m) : par(n) , sz(n , 1), queries(n), queryAns(m) {
        iota(all(par) , 0);
    }

    int find(int x){
        if(x == par[x]) return x;
        else return par[x] = find(par[x]);
    }

    void add_query(int u, int v, int idx) {
        queries[u].pb({v, idx});
        queries[v].pb({u, idx});
    }

    void merge(int x , int y , int w){
        x = find(x);
        y = find(y);
        if(x == y) return;
        if(sz[x] > sz[y]) swap(x , y);

        for(auto& q : queries[x]){
            if(find(q.fi) == y){
                queryAns[q.se] = w;
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
    int n , m;
    cin >> n >> m;
    vector<array<int , 4>>edges(m);
    int I = 0;
    for(auto& [w , u , v , idx] : edges){
        cin >> u >> v >> w;
        idx = I;
        --u , --v , ++I;
    }
    sort(all(edges));

    DSU dsu(n);
    ll MST = 0;
    vector<bool> inMST(m, false);

    for (int i = 0; i < m; ++i) {
        auto& [w , u , v , idx] = edges[i];
        if(dsu.merge(u , v)){
            MST += w;
            inMST[idx] = true;
        }
    }

    DSU2 dsu2(n, m);

    for(auto& [w , u , v , idx] : edges){
        if(!inMST[idx]){
            dsu2.add_query(u, v, idx);
        }
    }
    for(auto& [w , u , v , idx] : edges){
        if(inMST[idx]){
            dsu2.merge(u, v, w);
        }
    }
    vector<ll>ans(m);
    for(auto& [w , u , v , idx] : edges){
        if(inMST[idx]){
            ans[idx] = MST;
        } else {
            ans[idx] = MST + w - dsu2.queryAns[idx];
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