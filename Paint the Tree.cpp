// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/problemset/problem/1975/D
#include <bits/stdc++.h>
#define ll long long
#define nl '\n'
#define sp ' '
#define all(a) a.begin(),a.end()
#define allr(a) a.rbegin(),a.rend()
#define no cout<<"NO\n"
#define yes cout<<"YES\n"
#define ENG_GAMAL ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;
// ————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
const int N = 2e5 + 5, M = 1e3, LOG = 20, inf = 0x3f3f3f3f;
ll infLL = 0x3f3f3f3f3f3f3f3f;

int n , a , b;
vector<vector<int>>adj(N);
vector<int>parent(N) , depth(N);

void find_root(int v , int par = -1)
{
    parent[v] = par;
    if(v == b)
        return;
    for(int u : adj[v])
    {
        if(u == par)
            continue;
        find_root(u , v);
    }
}

void dfs(int v , int par = -1)
{
    for(int u : adj[v])
    {
        if(u == par)
            continue;
        depth[u] = depth[v] + 1;
        dfs(u , v);
    }
}

void solve() {
    cin >> n >> a >> b;
    for (ll i = 1; i <= n; ++i) {
        adj[i].clear();
        parent[i] = 0;
    }
    for (ll i = 0; i < n - 1; ++i) {
        int x , y;
        cin >> x >> y;
        adj[x].emplace_back(y);
        adj[y].emplace_back(x);
    }
    find_root(a);
    vector<int>path;
    int curr = b;
    while (curr != -1)
    {
        path.emplace_back(curr);
        curr = parent[curr];
    }
    int root = path[path.size() / 2];
    depth[root] = 0;
    dfs(root);
    vector<int>dis;
    for (ll i = 1; i <= n; ++i) {
        if(adj[i].size() == 1)
            dis.emplace_back(depth[i]);
    }
    int maxi = *max_element(depth.begin() , depth.begin() + n + 1) , ans = path.size() / 2;
    ans += 2 * (n - 1);
    cout << ans - maxi << nl;
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
    ll t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}