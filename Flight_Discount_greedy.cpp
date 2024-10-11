// LINK : https://cses.fi/problemset/result/10792535/
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
// index 0 from start to end and index 1 from end to start
vector<pair<int , int>>adj[N][2];
vector<vector<ll>>dist(N , vector<ll>(2 , infLL));

void dijkstra(int start , int idx)
{
    priority_queue<pair<ll , int > , vector<pair<ll ,  int>> , greater<>>pq;
    pq.push({0 , start});
    dist[start][idx] = 0;

    while (!pq.empty())
    {
        auto [curDis , curNode] = pq.top();
        pq.pop();

        if(curDis != dist[curNode][idx])
            continue;
        for(auto [v , w] : adj[curNode][idx])
        {
            if(dist[v][idx] > curDis + w)
            {
                dist[v][idx] = curDis + w;
                pq.push({dist[v][idx], v});
            }
        }
    }
}

struct edge
{
    int a , b , w;
};
void solve() {
    cin >> n >> m;
    vector<edge>edges(m);
    for (ll i = 0; i < m; ++i) {
        int a , b , w;
        cin >> a >> b >> w;
        a-- , b--;
        adj[a][0].emplace_back(b , w);
        adj[b][1].emplace_back(a , w);
        edges[i] = {a , b , w};
    }
    dijkstra(0 , 0);
    dijkstra(n - 1 , 1);
    ll ans =  infLL;
    for(auto edge : edges)
    {
        ans = min(ans , dist[edge.a][0] + dist[edge.b][1] + edge.w / 2);
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