// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://www.spoj.com/problems/BUGLIFE/
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

struct ParityDSU
{
    int par[N], dist[N]; // dist[u] = XOR parity to root

    void init(int n)
    {
        memset(par, -1, n * sizeof(par[0]));
        memset(dist, 0, n * sizeof(dist[0]));
    }

    // Returns {root, distance_to_root}
    pair<int, int> find(int u)
    {
        if (par[u] < 0)
            return {u, 0}; // par[u]<0 means u is root
        auto [root, d] = find(par[u]);
        dist[u] ^= dist[par[u]]; // path compression + parity
        par[u] = root;
        return {root, dist[u]};
    }

    // p=0: u and v same group, p=1: different group
    // Returns: -1=conflict, 0=new edge ok, 1=redundant ok
    int addEdge(int u, int v, int p)
    {
        auto [ru, du] = find(u);
        auto [rv, dv] = find(v);

        if (ru == rv)
        {
            return (du ^ dv) == p ? 1 : -1; // check consistency
        }

        // Union by size: par holds negative sizes.
        // More negative means a larger tree.
        if (par[rv] < par[ru])
        {
            swap(ru, rv);
            swap(du, dv); // Must swap distances to match the swapped roots
        }

        par[ru] += par[rv];     // Update the size of the larger root's tree
        par[rv] = ru;           // Attach the smaller tree's root to the larger one
        dist[rv] = du ^ dv ^ p; // Set parity so dist[v] is correct

        return 0;
    }
} dsu;

void TC(int t) {
    int n, m;
    cin >> n >> m;
    dsu.init(n + 1);
    bool ok = true;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        if (ok) {
            if (dsu.addEdge(u, v, 1) == -1) {
                ok = false;
            }
        }
    }

    cout << "Scenario #" << t << ":" << nl;
    if (ok) {
        cout << "No suspicious bugs found!" << nl;
    } else {
        cout << "Suspicious bugs found!" << nl;
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
    for (int t = 1; t <= tc; t++)
    {
        TC(t);
    }

    return 0;
}