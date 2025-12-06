// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/problemset/problem/1982/D
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
// ————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
const int N = 2e5 + 5, M = 1e3, LOG = 20, inf = 0x3f3f3f3f;
ll infLL = 0x3f3f3f3f3f3f3f3f;

ll gcd(ll a, ll b) {
    while (b != 0) {
        ll temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

ll gcd_vector(const vector<ll>& vec) {
    ll result = vec[0];
    for (size_t i = 1; i < vec.size(); ++i) {
        result = gcd(result, vec[i]);
        if (result == 1) {
            return 1;
        }
    }
    return result;
}

void TC() {
    ll n , m , k;
    cin >> n >> m >> k;
    vector<vector<int>> a(n , vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }
    vector<string> grid(n);
    ll sum1 = 0 , sum2 = 0;
    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == '1') sum1 += a[i][j];
            else sum2 += a[i][j];
        }
    }

    ll dif = sum2 - sum1;

    vector<vector<int>> pre1(n + 1 , vector<int>(m + 1, 0));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            pre1[i][j] = pre1[i-1][j] + pre1[i][j-1] - pre1[i-1][j-1] + (grid[i-1][j-1] == '1');
        }
    }

    vector<ll> values;

    for (int i = 1; i + k - 1 <= n; ++i) {
        for (int j = 1; j + k - 1 <= m; ++j) {
            int i2 = i + k - 1;
            int j2 = j + k - 1;
            int ones = pre1[i2][j2] - pre1[i-1][j2] - pre1[i2][j-1] + pre1[i-1][j-1];
            ll di = k * k - 2 * ones;
            values.pb(di);
        }
    }

    bool allZero = true;
    for (ll v : values) if (v != 0) { allZero = false; break; }

    if (allZero) {
        if (dif == 0) yes;
        else no;
        return;
    }

    ll g = gcd_vector(values);
    if (g == 0) {
        if (dif == 0) yes;
        else no;
        return;
    }
    if (abs(dif) % g == 0) yes;
    else no;
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
     cin >> tc;
    while (tc--)
    {
        TC();
    }

    return 0;
}