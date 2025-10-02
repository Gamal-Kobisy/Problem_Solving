// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://www.spoj.com/problems/ESCJAILA/en/

#include <bits/stdc++.h>
#define ll long long
#define nl '\n'
#define sp ' '
#define all(a) a.begin(),a.end()
#define allr(a) a.rbegin(),a.rend()
#define no cout<<"NO\n"
#define yes cout<<"YES\n"
#define ENG_GAMAL ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;
// ————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
const int N = 100 + 5, M = 1e3, LOG = 20, inf = 0x3f3f3f3f;
ll infLL = 0x3f3f3f3f3f3f3f3f;
int n , m;
vector<string>grid(N);
string di[] = {"D", "L", "R", "U", "DR", "DL", "UR", "UL"};
int dx[] = {1, 0, 0, -1, 1, -1, 1, -1};
int dy[] = {0, -1, 1, 0, 1, -1, -1, 1};
int knightx[] = {2, 2, -2, -2, 1, 1, -1, -1};
int knighty[] = {1, -1, 1, -1, 2, -2, 2, -2};

struct Node {
    int d, x, y, open;
    bool operator<(Node const& other) const {
        return d > other.d;
    }
};

vector<int> find_nearest_doors(int x , int y)
{
    queue<pair<int , int>>q;
    vector<vector<int>>dist(n , vector<int>(m , inf));
    q.emplace(x , y);
    dist[x][y] = 0;
}


void solve() {
    vector<string> grid(n);
    for (int i = 0; i < n; ++i) cin >> grid[i];

    int sx = -1, sy = -1;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (grid[i][j] == 'H') { sx = i; sy = j; }

    vector<vector<array<int,2>>> dist(n, vector<array<int,2>>(m, {inf, inf}));

    priority_queue<Node> pq;
    dist[sx][sy][0] = 0;
    pq.push({0, sx, sy, 0});
    while (!pq.empty()) {
        auto cur = pq.top(); pq.pop();
        int d = cur.d, x = cur.x, y = cur.y, open = cur.open;
        if (d != dist[x][y][open]) continue;

        for (int k = 0; k < 4; ++k) {
            int nx = x + dx[k], ny = y + dy[k];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            char cell = grid[nx][ny];
            if (cell == 'W')
                continue;
            if (cell == 'D' and not open)
                continue;

            int nop = open;
            if (cell == 'O') nop = 1;
            else if (cell == 'C') nop = 0;

            if (dist[nx][ny][nop] > d + 1) {
                dist[nx][ny][nop] = d + 1;
                pq.push({d + 1, nx, ny, nop});
            }
        }
    }
    int ans = inf;
    for(int i : {0 , n - 1})
    {
        for(int j = 0 ; j < m ; j++)
        {
            ans = min({ans, dist[i][j][0] , dist[i][j][1]});
        }
    }
    for (int i = 0; i < n; ++i) {
        for(int j : {0 , m - 1})
        {
            ans = min({ans, dist[i][j][0] , dist[i][j][1]});
        }
    }
    if(ans == inf)
        ans = -1;
    else
        ans++;
    cout << ans << nl;
}

void file() {
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
    //     cin >> t;
    while (true) {
        cin >> n >> m;
        if(n == -1 and m == -1)
            break;
        solve();
    }

    return 0;
}
