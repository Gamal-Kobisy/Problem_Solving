// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://cses.fi/problemset/task/1137
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

int n , q , s[N] , in[N] , out[N] , timer = 1;
vector<int>adj[N];
void dfs(int v , int par){
    in[v] = timer++;
    for(int u : adj[v]){
        if(u != par)
            dfs(u , v);
    }
    out[v] = timer++;
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
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        cin >> s[i];
        adj[i].clear();
    }
    for (int i = 1; i < n; ++i) {
        int a , b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    timer = 1;
    dfs(1 , -1);
    Fenwick tree(2 * n + 5);
    for(int i = 1 ; i <= n ; i++){
        tree.update(in[i] , s[i]);
    }
    while(q--){
        int op;
        cin >> op;

        if(op == 1){
            int a , b;
            cin >> a >> b;
            tree.update(in[a] , b - s[a]);
            s[a] = b;
        }
        else{
            int a;
            cin >> a;
            cout << tree.query_range(in[a] , out[a]) << nl;
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