// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/problemset/problem/1912/K
#pragma GCC optimize("O3")
#pragma GCC optimize ("unroll-loops")
#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
#pragma GCC target("avx2")
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

int n , a[N] , memo[N][4][4];

int solve(int idx , int sz , int mask){
    if(idx == n) return (sz == 3);
    int &ret = memo[idx][sz][mask];
    if(~ret) return ret;

    int skip = solve(idx + 1 , sz , mask);

    int pick = 0;
    int cur = a[idx] % 2;

    if (sz < 2) {
        int newMask = ((mask & 1) << 1) | cur;
        pick = solve(idx + 1, sz + 1, newMask);
    } else {
        int p1 = mask & 1;
        int p2 = (mask >> 1) & 1;
        if ((p1 + p2 + cur) % 2 == 0) {
            int newMask = (p1 << 1) | cur;
            pick = solve(idx + 1, 3, newMask);
        }
    }

    ret = add(skip , pick);
    return ret;
}

void TC() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    mem(memo , -1);
    cout << solve(0 , 0 , 0) << nl;
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
    ll tc = 1;
    // cin >> tc;
    while (tc--)
    {
        TC();
    }

    return 0;
}