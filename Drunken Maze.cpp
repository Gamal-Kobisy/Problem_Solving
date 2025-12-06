// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/problemset/problem/2041/D
#pragma GCC optimize("O3")
#pragma GCC optimize ("unroll-loops")
#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
#pragma GCC target("avx2")
using namespace std;
#define ll long long
#define ld long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define PI acos(-1)
#define Ones(n) __builtin_popcountll(n)
#define MSB(n) (63 - __builtin_clzll(n))
#define LSB(n) (__builtin_ctzll(n))
#define mem(arrr, xx) memset(arrr,xx,sizeof arrr)
#define fi first
#define se second
#define pb push_back
#define all(a) a.begin(),a.end()
#define allr(a) a.rbegin(),a.rend()
#define no cout<<"NO\n"
#define yes cout<<"YES\n"
#define imp cout<<"IMPOSSIBLE\n"
#define nl '\n'
#define sp ' '
#define ENG_GAMAL ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;
// ————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
const int N = 1e4 + 5, M = 1e3, LOG = 20, inf = 0x3f3f3f3f;
ll infLL = 0x3f3f3f3f3f3f3f3f;
int n , m;
string di[] = {"D", "L", "R", "U", "DR", "DL", "UR", "UL"};
int dx[] = {1, 0, 0, -1, 1, -1, 1, -1};
int dy[] = {0, -1, 1, 0, 1, -1, -1, 1};
int knightx[] = {2, 2, -2, -2, 1, 1, -1, -1};
int knighty[] = {1, -1, 1, -1, 2, -2, 2, -2};
vector<string>grid(N);
struct Node {
    int x, y;
    int dir;
    int cnt;
    int dist;
};


int bfs(int sx, int sy, int tx, int ty) {
    vector<vector<vector<array<int,4>>>> dist(
            n, vector<vector<array<int,4>>>(m, vector<array<int,4>>(5))
    );
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            for (int d = 0; d < 5; ++d)
                dist[i][j][d].fill(inf);

    queue<Node> q;
    const int DIR_NONE = 4;
    dist[sx][sy][DIR_NONE][0] = 0;
    q.push({sx, sy, DIR_NONE, 0, 0});

    auto valid = [&](int a , int b){
        return a >=0 && a < n && b >= 0 && b < m && grid[a][b] != '#';
    };

    while (!q.empty()) {
        Node cur = q.front(); q.pop();

        if (cur.x == tx && cur.y == ty) return cur.dist;

        for (int d = 0; d < 4; ++d) {
            int nx = cur.x + dx[d];
            int ny = cur.y + dy[d];

            if (!valid(nx, ny)) continue;

            int new_dir = d;
            int new_cnt = (cur.dir == new_dir) ? cur.cnt + 1 : 1;
            if (new_cnt > 3) continue;

            if (dist[nx][ny][new_dir][new_cnt] > cur.dist + 1) {
                dist[nx][ny][new_dir][new_cnt] = cur.dist + 1;
                q.push({nx, ny, new_dir, new_cnt, cur.dist + 1});
            }
        }
    }

    return -1;
}

void TC() {
    cin >> n >> m;
    pii s , t;
    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
        for (int j = 0; j < m; ++j) {
            if(grid[i][j] == 'S') s = {i , j};
            if(grid[i][j] == 'T') t = {i , j};
        }
    }
    ll ans = bfs(s.fi , s.se , t.fi , t.se);
    if(ans == inf) ans = -1;
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
    ll tc = 1;
//     cin >> tc;
    while (tc--)
    {
        TC();
    }

    return 0;
}