// LINK : https://cses.fi/problemset/result/10790447/
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
const int N = 1e5;
int n , m;
ll infLL = 0x3f3f3f3f3f3f3f3f;
vector<pair<int , int>>adj[N];
vector<ll>dist(N , infLL);

void dijkstra(int start)
{
    priority_queue<pair<ll , int> , vector<pair<ll , int>> , greater<>>pq;
    pq.emplace(start , 0);
    dist[start] = 0;

    while (!pq.empty())
    {
        auto [curDis , curNode] = pq.top();
        pq.pop();
        if(curDis != dist[curNode])
        {
            continue;
        }
        for(auto [v , w] : adj[curNode])
        {
            if(dist[v] > curDis + w)
            {
                dist[v] = curDis + w;
                pq.emplace(dist[v] , v);
            }
        }
    }
}
void solve() {
    cin >> n >> m;
    for (ll i = 0; i < m; ++i) {
        int a, b , w;
        cin >> a >> b >> w;
        a-- , b--;
        adj[a].emplace_back(b , w);
    }
    dijkstra(0);
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