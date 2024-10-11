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
int n , m , k;

vector<vector<pair<int , pair<ll , ll>>>>adj(N);

bool dijkstra(ll mid)
{
    vector<ll>dist(n , infLL);
    priority_queue<pair<ll , int> , vector<pair<ll , int>> , greater<>>pq;
    pq.push({0 , 0});
    dist[0] = 0;

    while (!pq.empty())
    {
        auto [curDis , curNode] = pq.top();
        pq.pop();
        if(curDis != dist[curNode])
        {
            continue;
        }
        for(auto i : adj[curNode])
        {
            if(dist[i.first] > curDis + i.second.first && i.second.second <= mid)
            {
                dist[i.first] = curDis + i.second.first;
                pq.push({dist[i.first] , i.first});
            }
        }

    }
    return (dist[n - 1] < k);
}

void solve() {
    cin >> n >> m >> k;
    for (ll i = 0; i < n; ++i) {
        adj[i].clear();
    }
    for (ll i = 0; i < m; ++i) {
        int a , b , c , w;
        cin >> a >> b >> c >> w;
        a-- , b--;
        adj[a].push_back({b , {c , w}});
        adj[b].push_back({a , {c , w}});
    }

    ll l = 1 , r = 1e11 , ans = -1;
    while (l <= r)
    {
        ll mid = (r + l) / 2;
        if(dijkstra(mid))
        {
            ans = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
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
    cin >> t;
    while(t--)
    {
        solve();
    }

    return 0;
}