// LINK :
#include <bits/stdc++.h>
#define ll long long
#define nl '\n'
#define all(a) a.begin(),a.end()
#define allr(a) a.rbegin(),a.rend()
#define no cout<<"NO\n"
#define yes cout<<"YES\n"
#define ENG_GAMAL ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

/*
 ███████╗███╗   ██╗ ██████╗       ██████╗  █████╗ ███╗   ███╗ █████╗ ██╗
 ██╔════╝████╗  ██║██╔════╝      ██╔════╝ ██╔══██╗████╗ ████║██╔══██╗██║
 █████╗  ██╔██╗ ██║██║  ███╗     ██║  ███╗███████║██╔████╔██║███████║██║
 ██╔══╝  ██║╚██╗██║██║   ██║     ██║   ██║██╔══██║██║╚██╔╝██║██╔══██║██║
 ███████╗██║ ╚████║╚██████╔╝     ╚██████╔╝██║  ██║██║ ╚═╝ ██║██║  ██║███████╗
 ╚══════╝╚═╝  ╚═══╝ ╚═════╝       ╚═════╝ ╚═╝  ╚═╝╚═╝     ╚═╝╚═╝  ╚═╝╚══════╝
*/
// ————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
const int N = 1e5 + 5, M = 1e3, LOG = 20, inf = 0x3f3f3f3f;
int MOD = 1e9 + 7;
ll infLL = 0x3f3f3f3f3f3f3f3f;
int n , m;

vector<vector<pair<int  , int>>>adj(N);
vector<ll>dist(N , infLL) , parent(N , -1);
void dijkstra()
{
    priority_queue<pair<ll , int> , vector<pair<ll , int>> , greater<>>pq;
    pq.push({0, 1});
    dist[1] = 0;

    while (!pq.empty())
    {
        auto [curDis , curNode] = pq.top();
        pq.pop();
        if(curDis != dist[curNode])
            continue;
        for(auto [v , w] : adj[curNode])
        {
            if(dist[v] > curDis + w)
            {
                dist[v] = curDis + w;
                pq.push({dist[v] , v});
                parent[v] = curNode;
            }
        }
    }
}

void solve() {
    cin >> n >> m;
    for (ll i = 0; i < m; ++i) {
        int a , b , w;
        cin >> a >> b >> w;
        adj[a].push_back({b , w});
        adj[b].push_back({a , w});
    }
    dijkstra();
    if(dist[n] == infLL)
    {
        cout << -1 << nl;
        return;
    }
    vector<int>ans;
    int cur = n;
    while (cur != -1)
    {
        ans.push_back(cur);
        cur = parent[cur];
    }
    reverse(all(ans));
    for (ll i = 0; i < ans.size(); ++i) {
        cout << ans[i] << ' ';
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
//    cin >> t;
    while(t--)
    {
        solve();
    }

    return 0;
}