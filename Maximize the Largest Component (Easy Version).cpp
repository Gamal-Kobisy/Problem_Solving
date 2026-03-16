// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/problemset/problem/1985/H1
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
#define mem(arrr, xx) memset(arrr,xgex,sizeof arrr)
#define fr first
#define sc second
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
const int N = 2e5 + 5, M = 1e3, LOG = 20, inf = 0x3f3f3f3f;
ll infLL = 0x3f3f3f3f3f3f3f3f;

string di[] = {"D", "L", "R", "U", "DR", "DL", "UR", "UL"};
int dx[] = {1, 0, 0, -1, 1, -1, 1, -1};
int dy[] = {0, -1, 1, 0, 1, -1, -1, 1};
int knightx[] = {2, 2, -2, -2, 1, 1, -1, -1};
int knighty[] = {1, -1, 1, -1, 2, -2, 2, -2};

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

void TC() {
    int n , m;
    cin >> n >> m;
    vector<string>grid(n);
    vector<vector<int>>vis(n , vector<int>(m));
    vector<int>rows[n] , cols[m];
    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
    }
    unordered_map<int , int>cntColor;
    int curColor = 1;
    auto valid = [&](int x ,int y){
        return x >= 0 and x < n and y >= 0 and y < m and grid[x][y] == '#';
    };
    function<void(int , int)> dfs = [&](int x , int y){
        cntColor[curColor]++;
        vis[x][y] = curColor;
        rows[x].pb(curColor);
        cols[y].pb(curColor);
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i] , ny = y + dy[i];
            if(valid(nx , ny) and not vis[nx][ny]){
                dfs(nx , ny);
            }
        }
    };
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if(valid(i , j) and not vis[i][j]){
                dfs(i , j);
                curColor++;
            }
        }
    }
    ll ans = cntColor[1];
    for (int i = 0; i < n; ++i) {
        set<int>colors;
        ll cand = 0;
        for (int j = 0; j < m; ++j) {
            if(grid[i][j] == '.') cand++;
            else colors.insert(vis[i][j]);
            // DOWN
            {
                int x = i + dx[0] , y = j + dy[0];
                if(valid(x , y))
                    colors.insert(vis[x][y]);
            }
            // UP
            {
                int x = i + dx[3] , y = j + dy[3];
                if(valid(x , y))
                    colors.insert(vis[x][y]);
            }

        }
        for(int color : colors) cand += cntColor[color];
        ans = max(cand  , ans);
    }
    for (int i = 0; i < m; ++i) {
        set<int>colors;
        ll cand = 0;
        for (int j = 0; j < n; ++j) {
            if(grid[j][i] == '.') cand++;
            else colors.insert(vis[j][i]);
            // LEFT
            {
                int x = j + dx[1] , y = i + dy[1];
                if(valid(x , y)) colors.insert(vis[x][y]);
            }
            // RIGHT
            {
                int x = j + dx[2] , y = i + dy[2];
                if(valid(x , y)) colors.insert(vis[x][y]);
            }
        }
        for(int color : colors) cand += cntColor[color];
        ans = max(cand  , ans);
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
    ll tc = 1;
     cin >> tc;
    while (tc--)
    {
        TC();
    }

    return 0;
}