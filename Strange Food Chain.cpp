// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://www.spoj.com/problems/CHAIN/
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

struct ModuloDSU
{
    int par[N], dist[N];
    int k; // The modulo / number of groups

    void init(int n, int mod)
    {
        k = mod;
        memset(par, -1, n * sizeof(par[0]));
        memset(dist, 0, n * sizeof(dist[0]));
    }

    // Returns {root, distance_to_root}
    pair<int, int> find(int u)
    {
        if (par[u] < 0)
            return {u, 0};
        auto [root, d] = find(par[u]);

        // Path compression + modular addition
        dist[u] = (dist[u] + dist[par[u]]) % k;
        par[u] = root;

        return {root, dist[u]};
    }

    // Adds relationship: (val(u) - val(v)) % k == p
    // Returns: -1=conflict, 0=new edge ok, 1=redundant ok
    int addEdge(int u, int v, int p)
    {
        p = (p % k + k) % k; // Ensure p is positive
        auto [ru, du] = find(u);
        auto [rv, dv] = find(v);

        if (ru == rv)
        {
            // Check consistency safely handling negative modulo
            return (((du - dv - p) % k + k) % k == 0) ? 1 : -1;
        }

        // Union by size: par holds negative sizes.
        if (par[rv] < par[ru])
        {
            swap(ru, rv);
            swap(du, dv);
            p = (k - p) % k; // CRITICAL: Reverse relationship direction for modulo
        }

        par[ru] += par[rv]; // Update size of the larger root's tree
        par[rv] = ru;       // Attach smaller tree to larger tree

        // Set new distance for rv relative to ru
        dist[rv] = ((du - dv - p) % k + k) % k;

        return 0;
    }

    // Query relationship between u and v
    // Returns: -1 if not connected, otherwise (val(u) - val(v)) % k
    int query(int u, int v)
    {
        auto [ru, du] = find(u);
        auto [rv, dv] = find(v);

        if (ru != rv)
            return -1; // Not connected

        return ((du - dv) % k + k) % k;
    }
} dsu;

void TC() {
    int n , k;
    cin >> n >> k;
    dsu.init(n + 1 , 3);
    int cnt = 0;
    while(k--){
        int t , x , y;
        cin >> t >> x >> y;
        if(x > n or y > n) cnt++;
        else if(t == 2 and x == y) cnt++;
        else{
            if (dsu.addEdge(x, y, (t == 1) ? 0 : 1) == -1) {
                cnt++;
            }
        }
    }
    cout << cnt << nl;
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