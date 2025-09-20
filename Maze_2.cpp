// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/problemset/problem/377/A
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
const int N = 500 + 5, M = 1e3, LOG = 20, inf = 0x3f3f3f3f;
ll infLL = 0x3f3f3f3f3f3f3f3f;

string di[] = {"D", "L", "R", "U", "DR", "DL", "UR", "UL"};
int dx[] = {1, 0, 0, -1, 1, -1, 1, -1};
int dy[] = {0, -1, 1, 0, 1, -1, -1, 1};
int knightx[] = {2, 2, -2, -2, 1, 1, -1, -1};
int knighty[] = {1, -1, 1, -1, 2, -2, 2, -2};

int n , m , k;
vector<string>grid(N);
vector<vector<bool>>vis(N , vector<bool>(N));

bool valid(int x , int y)
{
    return x >= 0 and x < n and y >= 0 and y < m and grid[x][y] == '.' and not vis[x][y];
}

void dfs(int x , int y)
{
    vis[x][y] = true;
    for(int i = 0 ; i < 4 ; i++)
    {
        int nx = x + dx[i] , ny = y + dy[i];
        if(valid(nx , ny))
            dfs(nx , ny);
    }
    if(k > 0)
        grid[x][y] = 'X' , k--;

}

void solve() {
    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
    }
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < m ; j++)
        {
            if(valid(i , j))
            {
                dfs(i , j);
            }
        }
    }
    for(int i = 0 ; i < n ; i++)
    {
        cout << grid[i] << nl;
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
//     cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}