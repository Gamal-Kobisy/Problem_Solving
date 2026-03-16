// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://cses.fi/problemset/task/1736
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

struct SegTree {
#define LF (x*2+1)
#define RT (x*2+2)
#define md ((lx+rx) >> 1)


    vector<ll> seg , a;
    // lazy saves {start, end, step}
    vector<array<ll , 3>> lazy;
    int sz;

    void build(int x, int lx, int rx) {
        if (lx == rx) {
            seg[x] = a[lx];
            return;
        }
        build(LF, lx, md);
        build(RT, md + 1, rx);
        seg[x] = merge(seg[LF] , seg[RT]);
    }

    SegTree(int n , vector<ll>v) {
        sz = n;
        seg.assign(4 * n, 0);
        lazy.assign(4 * n, {0 , 0 , 0});
        a = v;
        build(0 , 0 , sz - 1);
    }


    ll merge(ll lf , ll rt){
        return lf + rt;
    }

    ll sum(ll st, ll en, ll step) {
        ll len = ((en - st) / step) + 1;
        return len * (st + en) / 2;
    }

    void propegate(int x, int lx, int rx) {
        if (lazy[x][0] == 0 and lazy[x][1] == 0 && lazy[x][2] == 0) return;

        seg[x] += sum(lazy[x][0], lazy[x][1], lazy[x][2]);

        if (lx != rx) {
            ll left_len = md - lx + 1;

            ll st = lazy[x][0];
            ll en = lazy[x][1];
            ll step = lazy[x][2];

            ll left_end = st + step * (left_len - 1);
            ll right_start = st + step * left_len;

            lazy[LF][0] += st;
            lazy[LF][1] += left_end;
            lazy[LF][2] += step;

            lazy[RT][0] += right_start;
            lazy[RT][1] += en;
            lazy[RT][2] += step;
        }
        lazy[x] = {0 , 0 , 0};
    }

    void update(int l, int r, int x = 0, int lx = 0, int rx = -1) {
        if (rx == -1) rx = sz - 1;
        propegate(x, lx, rx);
        if (r < lx or rx < l)return;
        if (l <= lx and rx <= r) {
            lazy[x][0] += (lx - l + 1);
            lazy[x][1] += (rx - l + 1);
            lazy[x][2] += 1;
            propegate(x, lx, rx);
            return;
        }
        update(l, r, LF, lx, md);
        update(l, r, RT, md + 1, rx);
        seg[x] = merge(seg[LF] , seg[RT]);
    }


    ll query(int l, int r, int x = 0, int lx = 0, int rx = -1) {
        if (rx == -1) rx = sz - 1;
        propegate(x, lx, rx);
        if (r < lx or rx < l) return 0;
        if (l <= lx and rx <= r) return seg[x];
        return merge(query(l, r, LF, lx, md) , query(l, r, RT, md + 1, rx));
    }


#undef md
#undef LF
#undef RT
};

void TC() {
    int n , q;
    cin >> n >> q;
    vector<ll>a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    SegTree seg(n , a);
    while(q--){
        int t , l , r;
        cin >> t >> l >> r;
        if(t & 1){
            seg.update(--l , --r);
        }else{
            cout << seg.query(--l , --r) << nl;
        }
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
    ll tc = 1;
//     cin >> tc;
    while (tc--)
    {
        TC();
    }

    return 0;
}