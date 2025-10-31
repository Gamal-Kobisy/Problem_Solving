// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/problemset/problem/475/D
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
const int N = 1e5 + 5, M = 1e3, LOG = 20, inf = 0x3f3f3f3f;
ll infLL = 0x3f3f3f3f3f3f3f3f;
map<int , int>ans;
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

ll n , q , s[N] , T_MAX[N][22];

ll merge(ll a , ll b)
{
    return gcd(a , b);
}

ll query(ll l  ,ll r)
{
    ll sz = r - l + 1;
    ll ret = 0;
    for (int i = 21; i >= 0; --i) {
        if((sz >> i) & 1)
        {
            ret = merge(ret  , T_MAX[l][i]);
            l += (1 << i);
        }
    }
    return ret;
}

void build()
{
    for (int i = 0; i < n; ++i) {
        T_MAX[i][0] = s[i];
    }

    for (int pw = 1; (1 << pw) <= n; ++pw) {
        for (int i = 0; i + (1 << pw) <= n; ++i) {
            T_MAX[i][pw] = merge(T_MAX[i][pw - 1] , T_MAX[i + (1 << (pw - 1))][pw - 1]);
        }
    }

}

int query2(int l , int r){
    int sz = r - l + 1;
    int pw = log2(sz);
    return merge(T_MAX[l][pw] , T_MAX[r - (1 << pw) + 1][pw]);
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }
    build();
    for (int l = 0; l < n; ++l) {
        int r = l;
        while (r < n) {
            int cur_gcd = query2(l, r);
            int low = r, high = n - 1, best = r;
            while (low <= high) {
                int mid = (low + high) >> 1;
                if (query2(l, mid) == cur_gcd) {
                    best = mid;
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
            ans[cur_gcd] += best - r + 1;
            r = best + 1;
        }
    }
    cin >> q;
    while(q--){
        int x;
        cin >> x;
        cout << ans[x] << nl;
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

signed main() {
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