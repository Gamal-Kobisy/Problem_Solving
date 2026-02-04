// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK :
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
    vector<ll>par , sz;
    multiset<ll>pop;
    DSU(int n, vector<int>& a) {
        par.resize(n);
        iota(all(par), 0);
        sz.assign(all(a));
        for (int i = 0; i < n; i++) pop.insert(sz[i]);
    }

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
        pop.erase(pop.find(sz[x]));
        pop.erase(pop.find(sz[y]));
        par[x] = y;
        sz[y] += sz[x];
        pop.insert(sz[y]);
        return true;
    }

    void update_val(int node, ll old_val, ll new_val) {
        int root = find(node);
        pop.erase(pop.find(sz[root]));
        sz[root] = sz[root] - old_val + new_val;
        pop.insert(sz[root]);
    }
};

void TC() {
    int n , m , q;
    cin >> n >> m >> q;
    vector<int>a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<bool>keep(m , true);
    map<int , pii>edge;
    map<pii , int>idx;
    for (int i = 0; i < m; ++i) {
        int u , v;
        cin >> u >> v;
        --u , --v;
        idx[{u , v}] = idx[{v , u}] = i;
        edge[i] = {u , v};
    }
    vector<array<int , 3>>queries;
    for (int i = 0; i < q; ++i) {
        char t;
        cin >> t;
        if(t == 'D'){
            int k;
            cin >> k;
            --k;
            keep[k] = false;
            queries.pb({0 , k , -1});
        }else{
            int x , y;
            cin >> x >> y;
            --x;
            queries.pb({1 , x , a[x]});
            a[x] = y;
        }
    }
    DSU dsu(n , a);
    for (int i = 0; i < m; ++i) {
        if(keep[i]){
            dsu.merge(edge[i].fi , edge[i].se);
        }
    }
    reverse(all(queries));
    vector<ll> ans;
    for(auto [t, x, y] : queries) {
        ans.pb(*dsu.pop.rbegin());
        if(t == 1) {
            int current_val = a[x];
            int prev_val = y;
            dsu.update_val(x, current_val, prev_val);
            a[x] = prev_val;
        } else {
            dsu.merge(edge[x].fi, edge[x].se);
        }
    }
    reverse(all(ans));
    for(ll i : ans) cout << i << nl;
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