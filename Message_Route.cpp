// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://cses.fi/problemset/task/1667/
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
const int N = 1e5 + 5, M = 1e3, LOG = 20, inf = 0x3f3f3f3f;
ll infLL = 0x3f3f3f3f3f3f3f3f;

int n , m;

vector<vector<int>>adj(N);
vector<int>dis(N , inf) , parent(N);

void bfs()
{
    queue<int>q;
    q.push(1);
    dis[1] = 1;

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        for(int u : adj[cur])
        {
            if(dis[u] == inf)
                q.emplace(u) , dis[u] = dis[cur] + 1 , parent[u] = cur;
        }
    }
}

void solve() {
    cin >> n >> m;
    for (ll i = 1; i <= n; ++i) {
        adj[i].clear();
        dis[i] = inf;
        parent[i] = 0;
    }

    for (ll i = 0; i < m; ++i) {
        int a , b;
        cin >> a >> b;
        adj[a].emplace_back(b);
        adj[b].emplace_back(a);
    }
    bfs();
    if(dis[n] == inf)
        cout << "IMPOSSIBLE" << nl;
    else
    {
        cout << dis[n] << nl;
        vector<int>ans;
        int cur = n;
        while (cur != 0)
        {
            ans.emplace_back(cur);
            cur = parent[cur];
        }
        reverse(all(ans));
        for (ll i = 0; i < ans.size(); ++i) {
            cout << ans[i] << sp;
        }
        cout << nl;
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
    // cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}