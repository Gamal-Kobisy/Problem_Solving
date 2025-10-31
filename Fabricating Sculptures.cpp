// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK :
#include <bits/stdc++.h>
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
const int N = 2e5 + 5, M = 1e3, LOG = 20, inf = 0x3f3f3f3f;
ll infLL = 0x3f3f3f3f3f3f3f3f;

ll fact[N] , modinv[N];

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

ll power(ll b, ll p) {
    ll ans = 1;
    while (p) {
        if (p & 1)
            ans = mul(ans , b);
        b = mul(b , b);
        p /= 2;
    }
    return ans;
}

void pre(){
    fact[0] = 1;
    for (int i = 1; i < N; ++i) {
        fact[i] = mul(fact[i - 1] , i);
    }
    modinv[N - 1] = power(fact[N - 1] , MOD - 2);
    for (int i = N - 2; i >= 0 ; --i) {
        modinv[i] = mul(i + 1  , modinv[i + 1]);
    }
}

ll nCr(int n, int r) {
    return mul(mul(fact[n], modinv[n - r]), modinv[r]);
}

ll nPr(int n, int r) {
    return mul(fact[n], modinv[n - r]);
}

ll calc(int cols, int extra) {
    if (extra < 0) return 0;
    if (cols == 0) return (extra == 0) ? 1 : 0;
    return nCr(cols + extra - 1, extra);
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
    pre();
// ————————————————————————————————————————————
    int n, k;
    cin >> n >> k;
    int rem = k - n;
    int all = calc(n, rem);
    int invalid = 0;
    for (int i = 1; i < n; ++i) {
        int leftCols = i;
        int rightCols = n - i - 1;
        vector<int> A(rem + 1), B(rem + 1);
        for (int t = 0; t <= rem; ++t) {
            A[t] = calc(leftCols, t);
            B[t] = calc(rightCols, t);
        }
        vector<int> pre(rem + 2, 0);
        for (int l = 0; l <= rem; ++l) {
            int c = mul(A[l], B[rem - l]);
            pre[l + 1] = add(pre[l], c);
        }
        int maxBottom = (rem - 2) / 3;
        if (maxBottom < 0) continue;
        for (int bottom = 0; bottom <= maxBottom; ++bottom) {
            int low = bottom + 1;
            int high = rem - 2 * bottom - 1;
            if (high < low) continue;
            int segSum = sub(pre[high + 1], pre[low]);
            invalid = add(invalid, segSum);
        }
    }
    int ans = sub(all, invalid);
    cout << ans << nl;
    return 0;
}