 // "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://cses.fi/problemset/task/2413

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
const int N = 2e6 + 5, M = 1e3, LOG = 20, inf = 0x3f3f3f3f;
ll infLL = 0x3f3f3f3f3f3f3f3f;

 const ll MOD = 1e9 + 7;

 ll add(ll a, ll b) {
     return ((a % MOD) + (b % MOD)) % MOD;
 }

 ll sub(ll a, ll b) {
     return ((a % MOD) - (b % MOD) + MOD) % MOD;
 }

 ll mul(ll a, ll b) {
     return ((a % MOD) * (b % MOD)) % MOD;
 }

 ll power(ll b, ll p) {
     ll ans = 1;
     while (p) {
         if (p & 1)
             ans = mul(ans, b);
         b = mul(b, b);
         p /= 2;
     }
     return ans;
 }

int dp[N][2];
void solve() {
    ll n;
    cin >> n;
    cout << add(dp[n][0] , dp[n][1]) << nl;
}

void file() {
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
    dp[1][0] = dp[1][1] = 1;
    for (int i = 2; i <= 2e6; ++i) {
        dp[i][0] = add(dp[i][0] , add(mul(dp[i - 1][0] , 2) , dp[i - 1][1]));
        dp[i][1] = add(dp[i][1] , add(mul(dp[i - 1][1] , 4) , dp[i - 1][0]));
    }
    // ————————————————————————————————————————————
    ll t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
