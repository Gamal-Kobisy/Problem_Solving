// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://atcoder.jp/contests/dp/tasks/dp_m
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

const ll MOD = 1e9 + 7;

ll add(ll a, ll b)
{
    return ((a % MOD) + (b % MOD)) % MOD;
}

ll sub(ll a, ll b)
{
    return ((a % MOD) - (b % MOD) + MOD) % MOD;
}

ll mul(ll a, ll b)
{
    return ((a % MOD) * (b % MOD)) % MOD;
}

void TC() {
    int n , m;
    cin >> n >> m;
    int limit[n];
    for (int i = 0; i < n; ++i) {
        cin >> limit[i];
    }
//    vector<vector<int>>memo(2 , vector<int>(m + 1 , 0));
//    memo[(n) & 1] = vector<int>(m + 1 , 1);
    int memo[2][m + 1];
    mem(memo , 0);
    for(int i = 0 ; i <= m ; i++) memo[n&1][i] = 1;
    // memo[i][rem] = memo[i + 1][x] x in (rem , rem - limit[i])
    for (int idx = n - 1; idx >= 0; --idx) {
        for (int rem = 0; rem <= m; ++rem) {
            memo[idx&1][rem] = 0;
            int l = rem - limit[idx];
            int sum = memo[(idx+1) & 1][rem];
            if(l - 1 >= 0) sum = sub(sum , memo[(idx + 1) & 1][l - 1]);
            memo[(idx) & 1][rem] = add(memo[(idx) & 1][rem] , sum);
            if(rem) memo[(idx) & 1][rem] = add(memo[(idx) & 1][rem] , memo[(idx) & 1][rem-1]);
        }
    }
    int ans = memo[0][m];
    if(m > 0) ans = sub(ans, memo[0][m - 1]);
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