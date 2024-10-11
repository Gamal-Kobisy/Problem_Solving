// LINK : https://cses.fi/problemset/result/10791985/
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

struct flight
{
    int next;
    ll d;
    bool used;

    bool operator>(flight f)
    {
        return d > f.d;
    }
};
vector<pair<int , int>>adj[N];
vector<vector<ll>>dist(2 , vector<ll>(N , infLL));

void dijkstra(int start)
{
    priority_queue<flight , vector<flight> , greater<>>pq;
    pq.push({start, 0, 0});
    dist[0][start] = 0;

    while (!pq.empty())
    {
        auto [cur , d , used] = pq.top();
        pq.pop();

        if(d != dist[used][cur])
        {
            continue;
        }

        for(auto [v , w] : adj[cur])
        {
            if(dist[used][v] > d + w)
            {
                dist[used][v] = d + w;
                pq.push({v , dist[used][v] , used});
            }
            if(!used)
            {
                if(dist[1][v] > d + w / 2)
                {
                    dist[1][v] = d + w / 2;
                    pq.push({v , dist[1][v] , 1});
                }
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
    cout << dist[1][n - 1] << nl;
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