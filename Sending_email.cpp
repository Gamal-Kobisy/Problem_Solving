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
const int N = 2e5 + 5, M = 1e3, LOG = 20, inf = 0x3f3f3f3f;
int MOD = 1e9 + 7;
ll infLL = 0x3f3f3f3f3f3f3f3f;

void solve(int Case) {
    int n , m , start , end;
    cin >> n >> m >> start >> end;
    vector<vector<pair<int , int>>>adj(n);
    vector<ll>dist(n , infLL);

    for (ll i = 0; i < m; ++i) {
        int a , b , w;
        cin >> a >> b >> w;
        adj[a].push_back({b , w});
        adj[b].push_back({a , w});
    }

    priority_queue<pair<ll , int> , vector<pair<ll , int>> ,greater<pair<ll , int>>>pq;
    pq.push({0 , start});
    dist[start] = 0;

    while (!pq.empty())
    {
        auto [curDis , curNode] = pq.top();
        pq.pop();

        if(dist[curNode] != curDis)
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
    cout << "Case #" << Case << ": ";
    if(dist[end] == infLL)
    {
        cout << "unreachable" << nl;
        return;
    }
    cout << dist[end] << nl;
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
    ll t = 1 , Case = 1;
    cin >> t;
    while(t--)
    {
        solve(Case++);
    }

    return 0;
}