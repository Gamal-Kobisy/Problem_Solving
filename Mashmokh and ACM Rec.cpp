// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/problemset/problem/414/B
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
const int N = 2e3 + 5, M = 2e3 + 5, LOG = 20, inf = 0x3f3f3f3f;
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

int n , k , dp[N][M];

int calc(int idx , int last) {
    if (idx == k)
        return 1;
    int& ret = dp[idx][last];
    if (~ret)
        return ret;
    ret = 0;
    if (last) {
        for (int i = 1; mul(i , last) <= n; ++i) {
            ret = add(ret , calc(idx + 1, mul(i , last)));
        }
    }
    else {
        for (int i = 1; i <= n; ++i) {
            ret = add(ret , calc(idx + 1, i));
        }
    }

    return ret;
}

void solve() {
    cin >> n >> k;
    memset(dp , -1 , sizeof(dp));
    cout << calc(0 , 0) << nl;
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
    // ————————————————————————————————————————————
    ll t = 1;
    //     cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
