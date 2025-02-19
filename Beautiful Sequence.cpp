// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/contest/2069/problem/C
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

const ll MOD = 998244353;

int add(ll a, ll b) {
    return (0ll + a + b) % MOD;
}

int sub(ll a, ll b) {
    return ((0ll + a - b) % MOD + MOD) % MOD;
}

int mul(ll a, ll b) {
    return (1ll * a * b) % MOD;
}

int power(ll b, ll p) {
    int ans = 1;
    while (p) {
        if (p & 1)
            ans = mul(ans, b);
        b = mul(b, b);
        p /= 2;
    }
    return ans;
}

int divide(ll a, ll b) {
    return mul(a, power(b, MOD - 2)) % MOD;
}

void solve() {
    ll n;
    cin >> n;
    vector<ll>a(n) , suf(n + 1);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<ll> cnt(n, 0);
    ll ones = 0, subs = 0;
    for (ll j = 0; j < n; ++j) {
        if (a[j] == 1)
            ++ones;
        else if (a[j] == 3)
            cnt[j] = ones;
        subs += cnt[j];
    }
    for (ll i = n - 1; i >= 0 ; --i) {
        suf[i] += suf[i + 1] + (a[i] == 2);
    }
    ll ans = 0 , d = 0;
    for (ll i = 0; i < n; ++i) {
        if(a[i] == 1)
            d = add(d , power(2ll , suf[i]));
        else if(a[i] == 3)
            ans = add(ans , divide(d , power(2ll , suf[i])));
    }
    cout << sub(ans , subs) << nl;
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
    ll t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}