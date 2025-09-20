// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK :
#include <bits/stdc++.h>
#define ll long long
#define nl '\n'
#define sp ' '
#define all(a) a.begin(),a.end()
#define allr(a) a.rbegin(),a.rend()
#define no cout<<"No\n"
#define yes cout<<"Yes\n"
#define ENG_GAMAL ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;
// ————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
const int N = 50 + 5, M = 1e3, LOG = 20, inf = 0x3f3f3f3f;
ll infLL = 0x3f3f3f3f3f3f3f3f;
string di[] = {"D", "L", "R", "U", "DR", "DL", "UR", "UL"};
int dx[] = {1, 0, 0, -1, 1, -1, 1, -1};
int dy[] = {0, -1, 1, 0, 1, -1, -1, 1};
int knightx[] = {2, 2, -2, -2, 1, 1, -1, -1};
int knighty[] = {1, -1, 1, -1, 2, -2, 2, -2};

int n , m;
bool cycle;
vector<string>grid(N);
vector<vector<bool>>vis(N , vector<bool>(N));

bool valid(int x , int y)
{
    return x >= 0 and x < n and y >= 0 and y < m;
}

void dfs(int x, int y , string dir)
{
    vis[x][y] = true;
    for (int i = 0; i < 4; ++i) {
        if(dir == "L" and di[i] == "R")
            continue;
        if(dir == "R" and di[i] == "L")
            continue;
        if(dir == "U" and di[i] == "D")
            continue;
        if(dir == "D" and di[i] == "U")
            continue;
        int nx = x + dx[i] , ny = y + dy[i];
        if(valid(nx , ny) and grid[nx][ny] == grid[x][y])
        {
            if(vis[nx][ny])
            {
                cycle = true;
                return;
            }
            else
            {
                dfs(nx , ny , di[i]);
            }
        }
    }
}

void solve() {
    cycle = false;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if(not vis[i][j])
            {
                dfs(i , j , "A");
                if(cycle)
                    return void(yes);
            }
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
    ll t = 1;
//     cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}