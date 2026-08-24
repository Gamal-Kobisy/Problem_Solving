// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK :
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

void TC() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for (int i=0; i<m; ++i)
    {
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    vector<vector<ll>> dp(1<<n, vector<ll>(n));
    for (int i=0; i<n; ++i)
    {
        dp[1<<i][i] = 1;
    }
    for (int mask=1; mask<(1 << n); ++mask)
    {
        for (int u=0; u<n; ++u)
        {
            if ((mask & (1<<u)) == 0) continue;
            // currently standing at u
            for (int v: adj[u])
            {
                if ((mask & (1<<v))==0)
                {
                    dp[mask | (1<<v)][v] += dp[mask][u];
                }
            }

        }
    }
    ll ans = 0;
    for (int i=0; i<n; ++i)
    {
        ans += dp[((1<<n) - 1)][i];
    }
    cout << ans << "\n";
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
    // cin >> tc;
    while (tc--)
    {
        TC();
    }

    return 0;
}
//
// const int MOD = 998244353;
//
// int n, m;
// long long l;
// vector<int> freq;
// vector<int> pw;
// vector<vector<int>> memo;
//
// // Helper to match the "primes(l)" function from the image
// vector<long long> primes(long long val) {
//     vector<long long> fact;
//     for (long long i = 2; i * i <= val; i++) {
//         if (val % i == 0) {
//             long long pwr = 1;
//             while (val % i == 0) {
//                 pwr *= i;
//                 val /= i;
//             }
//             fact.push_back(pwr);
//         }
//     }
//     if (val > 1) fact.push_back(val);
//     return fact;
// }
//
// // Rewritten exactly in your requested recursive DP style
// int solve(int i , int mask){
//     if(i == (1 << m)) return (mask == (1 << m) - 1);
//
//     int &ret = memo[i][mask];
//     if(~ret) return ret;
//
//     // Base transition (skip this frequency group)
//     ret = solve(i + 1 , mask);
//
//     // Take transition (if there are elements available in this group)
//     if(freq[i]){
//         ret = (ret + 1LL * pw[freq[i]] * solve(i + 1 , mask | i)) % MOD;
//     }
//
//     return ret;
// }
//
// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//
//     if (!(cin >> n >> l)) return 0;
//
//     if (l == 1) {
//         long long x, res = 1;
//         for (int i = 0; i < n; i++) {
//             cin >> x;
//             if (x != 1) continue;
//             res = (res * 2) % MOD;
//         }
//         cout << (res - 1 + MOD) % MOD << "\n";
//         return 0;
//     }
//
//     auto fact = primes(l);
//     m = fact.size();
//
//     freq.assign(1 << m, 0);
//     pw.assign(n + 1, 1);
//
//     for (int i = 0; i < n; i++) {
//         pw[i + 1] = (pw[i] * 2LL) % MOD;
//         long long x;
//         cin >> x;
//
//         if (l % x) continue;
//
//         int mask = 0;
//         for (int j = 0; j < m; j++) {
//             if (__gcd(fact[j], x) == fact[j]) mask |= (1 << j);
//         }
//         freq[mask]++;
//     }
//
//     for (int i = 1; i <= n; i++) {
//         pw[i]--;
//         if (pw[i] < 0) pw[i] += MOD;
//     }
//
//     memo.assign(1 << m, vector<int>(1 << m, -1));
//
//     cout << solve(0 , 0) << "\n";
//     return 0;
// }
