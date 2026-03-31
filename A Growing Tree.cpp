// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/problemset/problem/1891/F
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
const int N = 5e5 + 5, M = 1e3, LOG = 20, inf = 0x3f3f3f3f;
ll infLL = 0x3f3f3f3f3f3f3f3f;

int tin[N], tout[N] ,path[N];
vector<int> adj[N];
int timer;
void dfs(int u, int p) {
    tin[u] = timer++;
    path[tin[u]] = u;
    for (auto v: adj[u]) {
        if (v == p) continue;
        dfs(v, u);
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
    for (int i = 0; i <= n; i++) {
        adj[i].clear();
    }
}

struct Fenwick {
    int n;
    vector<ll> tree;
    Fenwick(int _n){
        n = _n;
        tree.assign(n + 1, 0);
    }
    void update(int idx, ll val) {
        while (idx <= n) {
            tree[idx] += val;
            idx += idx & -idx;
        }
    }
    ll query(int idx) {
        ll ret = 0;
        while (idx > 0) {
            ret += tree[idx];
            idx -= idx & -idx;
        }
        return ret;
    }
    ll query_range(int l , int r){
        return query(r) - query(l - 1);
    }
};

void TC() {
    int sz = 1 , q;
    cin >> q;
    init(q + 1);
    vector<array<int , 3>>queries;

    for (int i = 0; i < q; ++i) {
        int a  , b , c = 0;
        cin >> a >> b;
        if(a == 2) cin >> c;
        else{
            c = ++sz;
            adj[c].pb(b);
            adj[b].pb(c);
        }
        queries.pb({a , b , c});
    }
    dfs(1 , -1);
    Fenwick bit(sz);
    for(auto [ty , v , x] : queries){
        if(ty&1){
            ll val = bit.query(tin[x]);
            bit.update(tin[x] , -val);
            bit.update(tout[x] + 1 , +val);
        }else{
            bit.update(tin[v] , x);
            bit.update(tout[v] + 1 , -x);
        }
    }
    for(int i = 1 ; i <= sz ; i++){
        cout << bit.query(tin[i]) << sp;
    }
    cout << nl;
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