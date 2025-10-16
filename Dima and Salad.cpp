// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/problemset/problem/366/C
#include <bits/stdc++.h>
#define ll long long
#define int ll
#define nl '\n'
#define sp ' '
#define all(a) coordinate.begin(),coordinate.end()
#define allr(a) coordinate.rbegin(),coordinate.rend()
#define no cout<<"NO\n"
#define yes cout<<"YES\n"
#define imp cout<<"IMPOSSIBLE\n"
#define ENG_GAMAL ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;
// ————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
const int N = 2e5 + 5, M = 1e5, LOG = 20, inf = 0x3f3f3f3f;
ll infLL = 0x3f3f3f3f3f3f3f3f;
int n , k , coordinate[105] , b[105] , dp[105][N];
bool vis[105][N];

int solve(int idx, int sum) {
    if (idx == n) {
        if (sum == M) return 0;
        else return -infLL;
    }
    if (vis[idx][sum]) return dp[idx][sum];
    ll op1  = solve(idx + 1, sum);
    ll op2 = solve(idx + 1, sum + coordinate[idx] - b[idx]) + coordinate[idx];
    ll ret = max(op1, op2);
    dp[idx][sum] = ret;
    vis[idx][sum] = true;
    return (int)ret;
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
// test-independent code ——————————————————————
// ————————————————————————————————————————————
    ll t = 1;
//     cin >> t;
    while (t--)
    {
        cin >> n >> k;

        for (int i = 0; i < n; ++i){
            cin >> coordinate[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
            b[i] *= k;
        }
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j < N; ++j) {
                dp[i][j] = -infLL;
                vis[i][j] = false;
            }
        }

        ll ans = solve(0, M);
        if(ans <= 0)
            ans = -1;
        cout << ans << nl;
    }

    return 0;
}
