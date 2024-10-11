// LINK : https://cses.fi/problemset/task/1202/
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
vector<pair<int , int>>adj[N];
vector<ll>dist(N , infLL);
int freq[N] , mx[N] , mn[N];

void dijkstra(int start)
{
    priority_queue<pair<ll , int> , vector<pair<ll , int>> , greater<>>pq;
    pq.emplace(0 , start);
    dist[start] = mx[start] = mn[start] = 0;
    freq[start] = 1;

    while (!pq.empty())
    {
        auto [curDis , curNode] = pq.top();
        pq.pop();
        if(dist[curNode] != curDis)
        {
            continue;
        }
        for(auto [v , w] : adj[curNode])
        {
            if(dist[v] > curDis + w)
            {
                dist[v] = curDis + w;
                freq[v] = freq[curNode];
                mn[v] = mn[curNode] + 1;
                mx[v] = mx[curNode] + 1;
                pq.emplace(dist[v] , v);
            }
            else if(dist[v] == curDis + w)
            {
                mn[v] = min(mn[v] , mn[curNode] + 1);
                mx[v] = max(mx[v] , mx[curNode] + 1);
                freq[v] = (freq[v] + freq[curNode]) % MOD;
            }
        }
    }
}
void solve() {
    cin >> n >> m;
    for (ll i = 0; i < m; ++i) {
        int a , b , w;
        cin >> a >> b >> w;
        a-- , b--;
        adj[a].emplace_back(b , w);
    }
    dijkstra(0);
    cout << dist[n - 1] << ' ' << freq[n - 1] << ' ' << mn[n - 1] << ' ' << mx[n - 1] << nl;
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