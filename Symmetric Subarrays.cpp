// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/gym/105262/problem/G
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
const int N = 1e6 + 5, M = 1e3, LOG = 20, inf = 0x3f3f3f3f;
ll infLL = 0x3f3f3f3f3f3f3f3f;

int B1, B2, MOD1, MOD2;
int pw1[N], pw2[N];

struct Hash {
private:
    vector<pair<int, int>> prefix, suffix;
    int n;

    void hash_prefix(const vector<int> &str) {
        int h1 = 0, h2 = 0;
        prefix.clear();
        prefix.reserve(str.size());
        for (int i: str) {
            h1 = (1LL * h1 * B1) % MOD1;
            h1 = (1LL * h1 + i) % MOD1;
            h2 = (1LL * h2 * B2) % MOD2;
            h2 = (1LL * h2 + i) % MOD2;
            prefix.emplace_back(h1, h2);
        }
    }

    void hash_suffix(const vector<int> &str) {
        int h1 = 0, h2 = 0;
        suffix.assign(n, {});
        for (int i = n - 1; i >= 0; i--) {
            h1 = (1LL * h1 * B1) % MOD1;
            h1 = (1LL * h1 + str[i]) % MOD1;
            h2 = (1LL * h2 * B2) % MOD2;
            h2 = (1LL * h2 + str[i]) % MOD2;
            suffix[i] = {h1, h2};
        }
    }

public:
    Hash() {}

    Hash(const vector<int> &s) { build(s); }

    void build(const vector<int> &s) {
        assert(B1);
        n = s.size();
        hash_prefix(s);
        hash_suffix(s); /// we need this ?
    }

    pair<int, int> getSuffix(int l, int r) {
        auto ret = suffix[l];
        int len = r - l + 1;
        r++;
        if (r < n) {
            ret.fr -= 1LL * suffix[r].fr * pw1[len] % MOD1;
            if (ret.fr < 0)ret.fr += MOD1;

            ret.sc -= 1LL * suffix[r].sc * pw2[len] % MOD2;
            if (ret.sc < 0)ret.sc += MOD2;

        }
        return ret;
    }

    pair<int, int> getPrefix(int l, int r) {
        auto ret = prefix[r];
        int sz = r - l + 1;
        l--;
        if (l >= 0) {
            ret.fr -= 1LL * prefix[l].fr * pw1[sz] % MOD1;
            if (ret.fr < 0)ret.fr += MOD1;
            ret.sc -= 1LL * prefix[l].sc * pw2[sz] % MOD2;
            if (ret.sc < 0)ret.sc += MOD2;
        }
        return ret;
    }
};

void build() {
    if (B1)return;
    random_device rd;
    mt19937 mt(rd());
    auto rnd = [&](int l, int r) { return uniform_int_distribution<int>(l, r)(mt); };
    auto check = [](int x) {
        for (int i = 2; i <= x / i; ++i) if (!(x % i)) return false;
        return true;
    };
    B1 = rnd(100, 500);
    B2 = rnd(100, 500);
    MOD1 = rnd(2e8, 2e9);
    MOD2 = rnd(2e8, 2e9);
    while (!check(MOD1))MOD1--;
    while (MOD1 == MOD2 or !check(MOD2))MOD2--;
    pw1[0] = pw2[0] = 1;
    for (int i = 1; i < N; ++i) {
        pw1[i] = 1LL * pw1[i - 1] * B1 % MOD1;
        pw2[i] = 1LL * pw2[i - 1] * B2 % MOD2;
    }
}

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
    int n;
    cin >> n;
    vector<int>a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<ll>preOfPre(n + 2),  pre(n + 1);
    for (int i = 1; i <= n; ++i) {
        pre[i] = add(pre[i - 1] , a[i - 1]);
    }
    for (int i = 0; i <= n; ++i) {
        preOfPre[i + 1] = add(preOfPre[i] , pre[i]);
    }
    Hash h(a);
    ll ans = 0;

    function<ll(int , int)> calc = [&](int l , int r){
        int k = (r - l + 2) / 2;
        ll L = sub(preOfPre[l + k - 1] , preOfPre[l - 1]);
        ll R = sub(preOfPre[r + 1] , preOfPre[r - k + 1]);
        return sub(R , L);
    };

    for (int i = 0; i < n; ++i) {
        int lo = 0, hi = min(i, n - i - 1), res = 0;
        while (lo <= hi) {
            int md = (lo + hi) / 2;
            if (h.getPrefix(i - md , i + md) == h.getSuffix(i - md , i + md)) {
                res = md;
                lo = md + 1;
            } else {
                hi = md - 1;
            }
        }
        ans = add(ans , calc(i - res + 1 , i + res + 1));
    }
    for (int i = 0; i < n - 1; ++i) {
        int lo = 1, hi = min(i + 1, n - i - 1), res = 0;
        while(lo <= hi){
            int md = (lo + hi) / 2;
            if(h.getPrefix(i - md + 1, i + md) == h.getSuffix(i - md + 1 , i + md)){
                res = md;
                lo = md + 1;
            }else{
                hi = md - 1;
            }
        }
        ans = add(ans , calc(i - res + 2 , i + res + 1));
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
    build();
// ————————————————————————————————————————————
    ll tc = 1;
     cin >> tc;
    while (tc--)
    {
        TC();
    }

    return 0;
}