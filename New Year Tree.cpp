// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/problemset/problem/620/E
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
const int N = 4e5 + 5, M = 1e3, LOG = 20, inf = 0x3f3f3f3f;
ll infLL = 0x3f3f3f3f3f3f3f3f;

int tin[N], tout[N];
vector<int> adj[N];
int timer;
void dfs(int u, int p) {
    tin[u] = timer++;

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


struct SEG {
    ll mask = 0;
    SEG() {}
    SEG(int c){
        mask = (1LL << c);
    }
};

struct LAZY {
    int ass = 0;

    LAZY() {}
    LAZY(int val){
        ass = val;
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
        ret.mask = lf.mask | rt.mask;
        return ret;
    }

    void propagate(int x, int lx, int rx) {
        if (lazy[x].ass == 0) return;

        seg[x].mask = (1LL << lazy[x].ass);

        if (lx != rx) {
            lazy[LF].ass = lazy[x].ass;
            lazy[RT].ass = lazy[x].ass;
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
            lazy[x].ass = val;
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
    int n , q;
    cin >> n >> q;
    init(n);
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
    dfs(1 , -1);
    segTree seg(n + 1);
    for(int i = 1 ; i <= n ; i++){
        seg.update(tin[i] , tin[i] , val[i]);
    }
    while(q--){
        int ty , v , c;
        cin >> ty;
        if(ty&1){
            cin >> v >> c;
            seg.update(tin[v] , tout[v], c);
        }else{
            cin >> v;
            cout << Ones(seg.query(tin[v] , tout[v]).mask) << nl;
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