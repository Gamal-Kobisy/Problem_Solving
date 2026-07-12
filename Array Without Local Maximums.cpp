// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/problemset/problem/1067/A
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

const ll MOD = 998244353;

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
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<vector<array<ll, 2>>> memo(n, vector<array<ll, 2>>(201, {0, 0}));
    if (~a[0]) {
        memo[0][a[0]][0] = 1;
    } else {
        for (int i = 1; i <= 200; ++i) memo[0][i][0] = 1;
    }
    for (int idx = 1; idx < n; ++idx) {
        int st = (a[idx] != -1) ? a[idx] : 1;
        int en = (a[idx] != -1) ? a[idx] : 200;
        for (int v = 2; v <= 200; ++v) {
            memo[idx-1][v][0] = add(memo[idx-1][v][0], memo[idx-1][v-1][0]);
            memo[idx-1][v][1] = add(memo[idx-1][v][1], memo[idx-1][v-1][1]);
        }
        for (int val = st; val <= en; ++val) {
            memo[idx][val][0] = add(memo[idx-1][val-1][0], memo[idx-1][val-1][1]);
            memo[idx][val][1] = add(
                    sub(memo[idx-1][val][0], memo[idx-1][val-1][0]),
                    sub(memo[idx-1][200][1], memo[idx-1][val-1][1])
            );
        }
    }

    ll ans = 0;
    for (int val = 1; val <= 200; ++val) {
        ans = add(ans, memo[n - 1][val][1]);
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
//     cin >> tc;
    while (tc--)
    {
        TC();
    }

    return 0;
}