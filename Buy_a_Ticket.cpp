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
const int N = 2e5, M = 1e3, LOG = 20, inf = 0x3f3f3f3f;
int MOD = 1e9 + 7;
ll infLL = 0x3f3f3f3f3f3f3f3f;
int n , m;
vector<pair<int , ll>>adj[N];
vector<ll>dist(N , infLL);

void dijkstra()
{
    priority_queue<pair<ll , int> , vector<pair<ll , int>> , greater<>>pq;
    for (ll i = 0; i < n; ++i) {
        pq.push({dist[i] , i});
    }
    while (!pq.empty())
    {
        auto [curDis , curNode] = pq.top();
        pq.pop();
        if(curDis > dist[curNode])
            continue;

        for(auto [v , w] : adj[curNode])
        {
            if(dist[v] > curDis + w)
            {
                dist[v] = curDis + w;
                pq.push({dist[v] , v});
            }
        }
    }

}
void solve() {
    cin >> n >> m;
    for (ll i = 0; i < m; ++i) {
        int a , b;
        ll w;
        cin >> a >> b >> w;
        a-- , b-- , w *= 2;
        adj[a].push_back({b , w});
        adj[b].push_back({a , w});
    }
    for (ll i = 0; i < n; ++i) {
        cin >> dist[i];
    }
    dijkstra();
    for (ll i = 0; i < n; ++i) {
        cout << dist[i] << ' ';
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