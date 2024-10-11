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
int a , b , c , d;
int dx[] = {-1, 0, 1, 0, -1, 1, 1, -1};
int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};
char di[] = {'U', 'R', 'D', 'L'};
int knightx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int knighty[] = {1, 2, 2, 1, -1, -2, -2, -1};

bool valid(int x , int y)
{
    return (x >= 0 && x < 8 && y >= 0 && y < 8);
}

ll dijkstra(int x1 , int y1 , int x2 , int y2)
{
    vector<vector<ll>>dist(8 , vector<ll>(8 , infLL));
    priority_queue<pair<ll , pair<int , int>> , vector<pair<ll , pair<int , int>>> , greater<>>pq;
    pq.push({0 ,{x1, y1}});
    dist[x1][y1] = 0;

    while (!pq.empty())
    {
        auto [curDist , point] = pq.top();
        auto [x , y] = point;
        pq.pop();

        if(dist[x][y] != curDist)
            continue;

        for (ll i = 0; i < 8; ++i) {
            int nx = x + knightx[i] , ny = y + knighty[i];
            if(valid(nx , ny) && dist[nx][ny] > curDist + (x * nx + y * ny))
            {
                dist[nx][ny] = curDist + (x * nx + y * ny);
                pq.push({dist[nx][ny] , {nx , ny}});
            }
        }
    }
    return dist[x2][y2];
}

void solve() {
    while (cin >> a >> b >> c >> d)
    {
        cout << dijkstra(a , b , c , d) << nl;
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