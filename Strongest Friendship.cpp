// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://usaco.org/index.php?page=viewproblem2&cpid=1259
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
struct DSU
{
    // par[u] < 0  ->  root, component size = -par[u]
    // par[u] >= 0 ->  non-root, parent = par[u]
    int par[N], ncmp, sets[N], pos[N];
    int tail[N], nxt[N];

    void init(int n)
    {
        memset(par, -1, n * sizeof par[0]); // -1 = root of size 1 (-(-1)=1)
        iota(sets, sets + n, 0);            // active root list: sets[0..ncmp-1]
        iota(pos, pos + n, 0);              // pos[u] = index of u in sets[]
        iota(tail, tail + n, 0);            // tail[u] = last node in u's linked list
        ncmp = n;
        memset(nxt, -1, n * sizeof nxt[0]);
    }

    int find(int u)
    {
        return par[u] < 0 ? u : par[u] = find(par[u]); // path compression
    }

    // s = small, b = big (by convention - swap if inconsistent).
    // Returns false if s and b are already in the same component.
    bool join(int s, int b)
    {
        s = find(s);
        b = find(b);
        if (s == b) return false;
        if (par[b] > par[s])
            swap(s, b);   // par more negative = bigger; ensure b is bigger
        par[b] += par[s]; // merge sizes: both negative, sum = larger size
        par[s] = b;       // s becomes child of b
        int &t = tail[b];
        nxt[t] = s;
        t = tail[s];
        int p = pos[s];
        sets[p] = sets[--ncmp];
        pos[sets[p]] = p;
        return true;
    }

    // Returns all nodes in the component containing u.
    vector<int> getCmp(int u)
    {
        u = find(u);
        vector<int> ret;
        ret.reserve(-par[u]); // preallocate with component size
        for (int v = u; v != -1; v = nxt[v])
            ret.push_back(v);
        return ret;
    }

    // Returns all components as a list of node lists.
    vector<vector<int>> getCmps()
    {
        vector<vector<int>> ret;
        ret.reserve(ncmp); // preallocate with number of components
        for (int i = 0; i < ncmp; i++)
            ret.push_back(getCmp(sets[i]));
        return ret;
    }
} dsu;

vector<int>adj[N];
void TC() {
    int n, m;
    cin >> n >> m;
    vector<int> inDeg(n, 0);
    for (int i = 0; i < n; ++i) {
        adj[i].clear();
    }

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        inDeg[a]++;
        inDeg[b]++;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    set<pii> st;
    for (int i = 0; i < n; ++i) {
        st.insert({inDeg[i], i});
    }

    ll ans = 0;
    int sz = n;
    while (!st.empty()) {
        int min_deg = st.begin()->fr;
        int u = st.begin()->sc;

        ll cand = 1ll * sz * min_deg;
        ans = max(ans, cand);

        st.erase(st.begin());
        sz--;

        for (int v : adj[u]) {
            if (st.count({inDeg[v], v})) {
                st.erase({inDeg[v], v});
                inDeg[v]--;
                st.insert({inDeg[v], v});
            }
        }
    }

    cout << ans << nl;
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
//    file();
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