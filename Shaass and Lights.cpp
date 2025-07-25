// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK :
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

void solve() {
    ll n , m;
    cin >> n >> m;
    vector<ll>a(m);
    for (int i = 0; i < m; ++i) {
        cin >> a[i];
    }
    sort(all(a));
    ll ans = fact[n - m];
    ans = mul(ans , modinv[a[0] - 1]);
    ans = mul(ans , modinv[n - a.back()]);
    for (int i = 0; i < m - 1; ++i) {
        if(a[i + 1] - a[i] - 1 == 0)
            continue;
        ans = mul(ans  , modinv[a[i + 1] - a[i] - 1]);
        ans = mul(ans , power(2 , a[i + 1] - a[i] - 2));
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
pre();
// ————————————————————————————————————————————
    ll t = 1;
//     cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}