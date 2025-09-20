// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/problemset/problem/505/B
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
const int N = 100 + 5, M = 1e3, LOG = 20, inf = 0x3f3f3f3f;
ll infLL = 0x3f3f3f3f3f3f3f3f;
vector<pair<int , int>>adj[N];
vector<vector<bool>>vis(N , vector<bool>(N));

bool dfs(int v, int color, int end)
{
    vis[v][color] = true;
    if(v == end)
        return true;
    bool ret = false;
    for(auto [u , c] : adj[v])
    {
        if(not vis[u][color] and c == color)
        {
            ret |= dfs(u, c, end);
        }
    }
    return ret;
}

void solve() {
    int n , m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a , b , c;
        cin >> a >> b >> c;
        adj[a].emplace_back(b , c);
        adj[b].emplace_back(a , c);
    }
    int q;
    cin >> q;
    while(q--)
    {
        int st , ed , cnt = 0;
        cin >> st >> ed;
        for(auto [u , c] : adj[st])
        {
            vis[st][c] = true;
            if(not vis[u][c])
                cnt += dfs(u , c , ed);
        }
        vis = vector<vector<bool>>(N , vector<bool>(N));
        cout << cnt << nl;
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
    ll t = 1;
//     cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}