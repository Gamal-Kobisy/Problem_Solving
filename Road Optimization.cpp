// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/problemset/problem/1625/C
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
const int N = 2e5 + 5, M = 1e3, LOG = 20, inf = 0x3f3f3f3f;
ll infLL = 0x3f3f3f3f3f3f3f3f;
int coordinate[505] , speed_limit[505] , n , k , l , dp[505][505];

int solve(int last_idx, int rem_k) {
    if (last_idx == n) return 0;
    if (dp[last_idx][rem_k] != -1) return dp[last_idx][rem_k];
    int ret = infLL;
    for (int pos = last_idx + 1; pos <= n; ++pos) {
        int removed = pos - last_idx - 1;
        if (removed > rem_k) continue;
        int length = coordinate[pos] - coordinate[last_idx];
        int time = length * speed_limit[last_idx];
        ret = min(ret, solve(pos, rem_k - removed) + time);
    }
    return dp[last_idx][rem_k] = ret;
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
    ll t = 1;
//     cin >> t;
    while (t--)
    {
        cin >> n >> l >> k;
        for (int i = 0; i < n; ++i) {
            cin >> coordinate[i];
        }
        coordinate[n] = l;
        for (int i = 0; i < n; ++i) {
            cin >> speed_limit[i];
        }
        speed_limit[n] = 0;
        for (int i = 0; i <= n; ++i)
            for (int j = 0; j <= k; ++j)
                dp[i][j] = -1;

        cout << solve(0, k) << nl;
    }

    return 0;
}
