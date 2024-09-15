// LINK : https://codeforces.com/problemset/problem/242/C
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
int dx[] = {-1, 0, 1, 0, -1, 1, 1, -1};
int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};
int knightx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int knighty[] = {1, 2, 2, 1, -1, -2, -2, -1};
const ll N = 1e9 + 1;
ll n , x , y , X , Y;
map<pair<ll , ll> , bool>grid;
map<pair<ll ,ll> , ll>dist;
bool valid(ll nx , ll ny)
{
    return (nx <= 1e9 && nx > 0 && ny <= 1e9 && ny > 0 && grid[{nx, ny}] && dist[{nx, ny}] == 0);
}

void bfs(ll x , ll y)
{
    queue<pair<ll ,ll>>q;
    q.push({x , y});
    dist[{x , y}] = 0;
    ll level = 0;
    while (!q.empty())
    {
        ll sz = q.size();
        while (sz--)
        {
            pair<ll ,ll> cur = q.front();
            q.pop();
            for (ll i = 0; i < 8; ++i) {
                ll nx = cur.first + dx[i] , ny = cur.second + dy[i];
                if(valid(nx , ny))
                {
                    q.push({nx , ny});
                    dist[{nx, ny}] = level + 1;
                }
            }
        }
        level++;
    }
}
void solve() {
    cin >> x >> y >> X >> Y >> n;
    for (ll i = 0; i < n; ++i) {
        ll r , a , b;
        cin >> r >> a >> b;
        for (ll j = a; j <= b; ++j) {
            grid[{r, j}] = true;
        }
    }

    bfs(x , y);

    if(dist[{X , Y}])
    {
        cout << dist[{X , Y}] << nl;
    }
    else
    {
        cout << -1 << nl;
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