// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://atcoder.jp/contests/abc453/tasks/abc453_d
#include <bits/stdc++.h>
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
#define fr first
#define sc second
#define pb push_back
#define all(a) a.begin(),a.end()
#define allr(a) a.rbegin(),a.rend()
#define no cout<<"No\n"
#define yes cout<<"Yes\n"
#define imp cout<<"IMPOSSIBLE\n"
#define nl '\n'
#define sp ' '
#define ENG_GAMAL ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;
// ————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
const int N = 2e5 + 5, M = 1e3, LOG = 20, inf = 0x3f3f3f3f;
ll infLL = 0x3f3f3f3f3f3f3f3f;
string di[] = {"D", "L", "R", "U", "DR", "DL", "UR", "UL"};
int dx[] = {1, 0, 0, -1, 1, -1, 1, -1};
int dy[] = {0, -1, 1, 0, 1, -1, -1, 1};
int knightx[] = {2, 2, -2, -2, 1, 1, -1, -1};
int knighty[] = {1, -1, 1, -1, 2, -2, 2, -2};
int n , m;
int startX , startY;
int endX , endY;
vector<string>grid(1001);
bool vis[1001][1001][4];
int parent[1001][1001][4];
bool valid(int x , int y){
    return x >= 0 and x < n and y >= 0 and y < m and grid[x][y] != '#';
}
void dfs(int x , int y , int dir){
    if(x == endX and y == endY){
        yes;
        vector<string> path;

        int curX = endX, curY = endY, curDir = dir;
        while (parent[curX][curY][curDir] != -1) {
            path.push_back(di[curDir]);   // اتجاه الوصول للحالة الحالية
            int p = parent[curX][curY][curDir];
            curX -= dx[curDir];           // ارجع بعكس اتجاه الحالة الحالية
            curY -= dy[curDir];
            curDir = p;                   // اتجاه الأب
        }

        reverse(all(path));
        for (auto &s : path) cout << s;
        cout << nl;
        exit(0);
    }
    if(vis[x][y][dir]) return;
    vis[x][y][dir] = true;
    if(grid[x][y] == 'o'){
        int nx = x + dx[dir], ny = y + dy[dir];
        if (valid(nx, ny) && !vis[nx][ny][dir]) {
            parent[nx][ny][dir] = dir;
            dfs(nx, ny, dir);
        }
    }
    else if(grid[x][y] == 'x'){
        for (int i = 0; i < 4; ++i) {
            if (i == dir) continue;
            int nx = x + dx[i], ny = y + dy[i];
            if (valid(nx, ny) && !vis[nx][ny][i]) {
                parent[nx][ny][i] = dir;
                dfs(nx, ny, i);
            }
        }
    }else{
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i], ny = y + dy[i];
            if (valid(nx, ny) && !vis[nx][ny][i]) {
                parent[nx][ny][i] = dir;
                dfs(nx, ny, i);
            }
        }
    }
    return;
}

void TC() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
        for (int j = 0; j < m; ++j) {
            if(grid[i][j] == 'S') startX = i , startY = j;
            if(grid[i][j] == 'G') endX = i , endY = j;

        }
    }
    mem(vis , false);
    mem(parent , -1);
    for (int i = 0; i < 4; ++i) {
        dfs(startX , startY , i);
    }
    for (int i = 0; i < 4; ++i) {
        if(vis[endX][endY][i]){

            return;
        }
    }
    no;
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