// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/problemset/problem/2022/C
//#pragma GCC optimize("O3")
//#pragma GCC optimize ("unroll-loops")
//#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
//#pragma GCC target("avx2")
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
const int N = 2e5 + 5, M = 1e3, LOG = 20, inf = 0x3f3f3f3f;
ll infLL = 0x3f3f3f3f3f3f3f3f;
vector<vector<int>>memo;
vector<vector<char>>grid;
int n;

bool good(pii a , pii b , pii c){
    return ((grid[a.fi][a.se] == 'A')
            + (grid[b.fi][b.se] == 'A')
            + (grid[c.fi][c.se] == 'A')) >= 2;
}

int solve(int idx , int type){
    if(idx == n)
        return (type == 0 ? 0 : -inf);
    if(idx > n)
        return -inf;
    int &ret = memo[idx][type];
    if(~ret) return ret;
    if(type == 0){
        int op1 = solve(idx + 3, 0)
                  + good({0, idx}, {0, idx + 1}, {0, idx + 2})
                  + good({1, idx}, {1, idx + 1}, {1, idx + 2});
        int op2 = solve(idx + 1, 1)
                  + good({0, idx}, {0, idx + 1}, {1, idx});
        int op3 = solve(idx + 1, 2)
                  + good({0, idx}, {1, idx}, {1, idx + 1});
        ret = max({op1 , op2 , op3});
    }else if(type == 1){
        int op1 = solve(idx + 3, 1)
                  + good({0, idx + 1}, {0, idx + 2}, {0, idx + 3})
                  + good({1, idx}, {1, idx + 1}, {1, idx + 2});
        int op2 = solve(idx + 2, 0)
                  + good({1, idx}, {0, idx + 1}, {1, idx + 1});
        ret = max({op1, op2});
    }else{
        int op1 = solve(idx + 3, 2)
                  + good({0, idx}, {0, idx + 1}, {0, idx + 2})
                  + good({1, idx + 1}, {1, idx + 2}, {1, idx + 3});
        int op2 = solve(idx + 2, 0)
                  + good({0, idx}, {0, idx + 1}, {1, idx + 1});
        ret = max({op1, op2});
    }
    return ret;
}

void TC() {
    cin >> n;
    grid = vector<vector<char>>(2 , vector<char>(n));
    memo = vector<vector<int>>(n , vector<int>(3 , -1));
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> grid[i][j];
        }
    }
    cout << solve(0 , 0) << nl;
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