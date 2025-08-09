// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://cses.fi/problemset/task/1647
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
ll n , q , s[N] , T[N][22];

ll merge(ll a , ll b)
{
    return min(a , b);
}

void build()
{
    for (int i = 0; i < n; ++i) {
        T[i][0] = s[i];
    }

    for (int pw = 1; (1 << pw) <= n; ++pw) {
        for (int i = 0; i + (1 << pw) <= n; ++i) {
            T[i][pw] = merge(T[i][pw - 1] , T[i + (1 << (pw - 1))][pw - 1]);
        }
    }
}

ll query(ll l  ,ll r)
{
    ll sz = r - l + 1;
    ll ret = LLONG_MAX;
    for (int i = 21; i >= 0; --i) {
        if((sz >> i) & 1)
        {
            ret = merge(ret  , T[l][i]);
            l += (1 << i);
        }
    }
    return ret;
}

ll query2(ll l , ll r)
{
    ll sz = r -l + 1;
    ll pw = log2(sz);
    return merge(T[l][pw] , T[r - (1 << pw) + 1][pw]);
}

void solve() {
    cin >> n >> q;
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }
    build();
    while(q--)
    {
        ll l , r;
        cin >> l >> r;
        cout << query2(--l , --r) << nl;
    }
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
//     cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}