// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://atcoder.jp/contests/abc087/tasks/arc090_b
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
#define no cout<<"No\n"
#define yes cout<<"Yes\n"
#define imp cout<<"IMPOSSIBLE\n"
#define nl '\n'
#define sp ' '
#define ENG_GAMAL ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;
// ————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
const int N = 2e5 + 5, M = 1e3, LOG = 20, inf = 0x3f3f3f3f;
ll infLL = 0x3f3f3f3f3f3f3f3f;

struct WeightedDSU
{
    int par[N];
    long long w[N]; // w[u] = value[u] - value[root]

    void init(int n)
    {
        memset(par, -1, n * sizeof(par[0]));
        memset(w, 0, n * sizeof(w[0]));
    }

    pair<int, long long> find(int u)
    {
        if (par[u] < 0)
            return {u, 0}; // par[u]<0 means u is root
        auto [root, wr] = find(par[u]);
        par[u] = root;
        w[u] += wr; // path compression: accumulate weight
        return {root, w[u]};
    }

    // Constraint: value[v] - value[u] = d
    // Returns false if contradiction
    bool join(int u, int v, long long d)
    {
        auto [ru, wu] = find(u); // wu = value[u] - value[ru]
        auto [rv, wv] = find(v); // wv = value[v] - value[rv]
        if (ru == rv)
        {
            return (wv - wu) == d; // check: value[v]-value[u] = wv-wu
        }
        par[rv] = ru;
        w[rv] = wu - wv + d; // so that value[v]-value[u] = d holds
        return true;
    }

    // Query: value[v] - value[u] (must be in same component)
    long long query(int u, int v)
    {
        auto [ru, wu] = find(u);
        auto [rv, wv] = find(v);
        if (ru != rv)
            return -infLL; // not connected
        return wv - wu;
    }
} dsu;

void TC() {
    int n , m;
    cin >> n >> m;
    dsu.init(n + 1);
    bool ok = true;
    while(m--){
        int l , r , d;
        cin >> l >> r >> d;
        ok &= dsu.join(l , r , d);
    }
    ok ? yes : no;
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