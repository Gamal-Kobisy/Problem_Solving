// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://cses.fi/alon/task/1691
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
const int N = 200000 + 5;
const int M = 400000 + 5;
int head[N], to[M * 2], nxt[M * 2], deg[N], ne, n;

int vis[M * 2];
int vid = 1;
int ans[M * 2], sz;

void init()
{
    memset(head, -1, (n+1) * sizeof(head[0]));
    memset(deg, 0, (n+1) * sizeof(deg[0]));
    ne = 0;
}

void addEdge(int u, int v)
{
    to[ne] = v;
    nxt[ne] = head[u];
    head[u] = ne++;
    deg[u]++;
}

void addBiEdge(int u, int v)
{
    addEdge(u, v);
    addEdge(v, u);
}

void euler(int u)
{
    for (int v, &e = head[u]; ~e;)
    {
        int ee = e;
        e = nxt[e]; // Move head pointer to the next edge
        if (vis[ee] == vid)
            continue;
        vis[ee] = vis[ee ^ 1] = vid;
        v = to[ee];
        euler(v);
        ans[sz++] = ee;
    }
}

// Returns true if Euler path/circuit exists.
// Sets 'st' = valid start node.
// 'm' is the total number of UNDIRECTED edges.
bool buildEulerUndirected(int st, int m)
{
    int odd = 0;
    for (int i = 1; i <= n; i++)
    {
        if (deg[i] & 1)
        {
            odd++;
//            st = i;
        }
        if (deg[i] > 0 && st == -1)
        {
//            st = i;
        }
    }

    if (odd != 0)
        return false;



    sz = 0;
    ++vid; // O(1) visited array reset
    euler(st);
    if (sz != m)
        return false;
    reverse(ans, ans + sz);

    return true;
}

void TC() {
    int m;
    cin >> n >> m;
    init();
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        addBiEdge(u, v);
    }
    bool ok = buildEulerUndirected(1 , m);
    if(not ok) return void(imp);
    cout << 1 << sp;
    for(int i = 0; i < sz; i++) {
        cout << to[ans[i]] << sp;
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
//     cin >> tc;
    while (tc--)
    {
        TC();
    }

    return 0;
}