// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK :
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#pragma GCC target("avx,avx2,fma")
#define ll long long
#define int ll
#define nl '\n'
#define sp ' '
#define all(a) a.begin(),a.end()
#define allr(a) a.rbegin(),a.rend()
#define no cout<<"NO\n"
#define yes cout<<"YES\n"
#define imp cout<<"IMPOSSIBLE\n"
#define ENG_GAMAL ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;
// ————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
const int N = 3000 + 5, M = 1e3, LOG = 20, inf = 0x3f3f3f3f;
ll infLL = 0x3f3f3f3f3f3f3f3f;
int n , vis[N][N];
string grid[N] ;

unordered_map<long long, string> memo;
long long key(int i, int j){
    return ( (long long)i << 32 ) ^ (unsigned long long) j;
}

string solve(int i , int j){
    if(i == n && j == n) return string("");
    if(i > n || j > n) return string( (2*n)+5, 'z');

    long long k = key(i,j);
    auto it = memo.find(k);
    if(it != memo.end()) return it->second;

    char down = (i + 1 <= n ? grid[i + 1][j] : char(127));
    char right = (j + 1 <= n ? grid[i][j + 1] : char(127));

    string ret;
    if(j == n){
        ret = down + solve(i + 1, j);
    } else if(i == n){
        ret = right + solve(i, j + 1);
    } else {
        if(right < down){
            ret = right + solve(i, j + 1);
        } else if(down < right){
            ret = down + solve(i + 1, j);
        } else {
            string a = right + solve(i, j + 1);
            string b = down + solve(i + 1, j);
            if(a <= b) ret = std::move(a);
            else ret = std::move(b);
        }
    }

    memo.emplace(k, ret);
    return memo[k];
}

void TC() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> grid[i];
        grid[i] = " " + grid[i];
    }

    string ans = grid[1][1] + solve(1,1);
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

signed main() {
    file();
    ENG_GAMAL
    ll tc = 1;
    // cin >> tc;
    while (tc--)
    {
        TC();
    }
    return 0;
}
