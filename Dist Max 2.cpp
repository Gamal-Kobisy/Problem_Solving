// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://atcoder.jp/contests/abc215/tasks/abc215_f?lang=en
//#pragma GCC optimize("O3")
//#pragma GCC optimize ("unroll-loops")
//#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
//#pragma GCC target("avx2")
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

struct segTree{
#define LF 2*x+1
#define RT 2*x+2
#define mid (lx+rx)/2

    int sz;
    vector<int>seg;



    segTree(int n){
        sz = n;
        seg = vector<int>(4 * sz + 1);
    }

    void update(int i , int val , int x = 0 , int lx = 0 , int rx = -1){
        if(rx == -1) rx = sz - 1;

        if(lx == rx){
            seg[x] = val;
            return;
        }

        if(i <= mid){
            update(i , val , LF , lx , mid);
        }else{
            update(i , val , RT , mid + 1 , rx);
        }
        seg[x] = max(seg[LF] , seg[RT]);
    }

    int query(int l , int r , int x = 0 , int lx = 0 , int rx = -1){
        if(rx == -1) rx = sz - 1;
        if(rx < l or lx > r) return -inf;
        if(lx >= l and rx <= r) return seg[x];
        return max(query(l , r , LF , lx , mid) ,
                     query(l , r , RT , mid + 1 , rx));
    }

};


void TC() {
    int n;
    cin >> n;
    vector<pii>a(n);
    map<int , vector<pii>>segs;
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
    }

    auto check = [&](int k) {
        int mn = inf, mx = -inf;
        int L = -1;
        for (int i = 0; i < n; i++) {
            while (L <= i and a[i].fi - a[L + 1].fi >= k) {
                mn = min(mn, a[L + 1].se);
                mx = max(mx, a[L + 1].se);
                L++;
            }

            if (~L) {
                if (abs(a[i].se - mn) >= k || abs(a[i].se - mx) >= k) {
                    return true;
                }
            }
        }
        return false;
    };
    sort(all(a));
    int lo = 0, hi = 1e9, ans = 0;
    while (lo <= hi) {
        int md = (lo + hi) / 2;
        if (check(md)) {
            ans = md;
            lo = md + 1;
        } else {
            hi = md - 1;
        }
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
// ————————————————————————————————————————————
    ll tc = 1;
//     cin >> tc;
    while (tc--)
    {
        TC();
    }

    return 0;
}