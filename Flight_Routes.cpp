// LINK : https://cses.fi/problemset/result/10791034/
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
int n , m , k;
vector<pair<int , int>>adj[N];
vector<multiset<ll>>dist(N);

void dijkstra(int start)
{
    priority_queue<pair<ll , int> , vector<pair<ll , int>> , greater<>>pq;
    pq.emplace(0 , start);
    dist[start].insert(0);

    while (!pq.empty())
    {
        auto [curDis , curNode] = pq.top();
        pq.pop();

        if(dist[curNode].find(curDis) == dist[curNode].end())
        {
            continue;
        }

        for(auto [v  , w] : adj[curNode])
        {
            if(dist[v].size() < k)
            {
                dist[v].insert(curDis + w);
                pq.emplace(curDis + w , v);
            }
            else if(curDis + w < *dist[v].rbegin())
            {
                dist[v].erase(dist[v].find(*dist[v].rbegin()));
                dist[v].insert(curDis + w);
                pq.emplace(curDis + w , v);
            }
        }
    }
}

void solve() {
    cin >> n >> m >> k;
    for (ll i = 0; i < m; ++i) {
        int a , b , w;
        cin >> a >> b >> w;
        a-- , b--;
        adj[a].emplace_back(b , w);
    }
    dijkstra(0);
    for (ll i: dist[n - 1]) {
        cout << i << ' ';
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
    ll t = 1;
//    cin >> t;
    while(t--)
    {
        solve();
    }

    return 0;
}