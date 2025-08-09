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
vector<vector<ll>>adj;
vector<ll>dist;
void bfs(ll s)
{
    queue<ll>q;
    q.push(s);
    dist[s] = 0;
    while (!q.empty())
    {
        ll cur = q.front();
        q.pop();

        for(ll u : adj[cur])
        {
            if(dist[u] > dist[cur] + 1)
            {
                q.push(u);
                dist[u] = dist[cur] + 1;
            }
        }
    }
}

void solve() {
    ll n , s , e;
    cin >> n >> s >> e;
    adj  = vector<vector<ll>>(n + 1);
    dist = vector<ll>(n + 1 , 1e9);
    vector<string>v(n);
    vector<vector<short>>freq(n , vector<short>(10));
    for (ll i = 0; i < n; ++i) {
        cin >> v[i];
        for (ll j = 0; j < v[i].size(); ++j) {
            freq[i][v[i][j] - '0']++;
        }
    }
    for (ll i = 1; i <= n; ++i) {
        for (ll j = i + 1; j <= n; ++j) {
            ll cnt = 0;
            for (ll k = 0; k < 10; ++k) {
                cnt += min(freq[i - 1][k] , freq[j - 1][k]);
            }
            if(cnt >= 17)
            {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
    bfs(s);
    if(dist[e] == 1e9)
    {
        cout << -1 << nl;
    }
    else
    {
        cout << dist[e] << nl;
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
    cin >> t;
    while(t--)
    {
        solve();
    }

    return 0;
}