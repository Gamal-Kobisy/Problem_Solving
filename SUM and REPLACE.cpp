// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/problemset/problem/242/E
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
const int N = 1e6 + 5, M = 1e3, LOG = 20, inf = 0x3f3f3f3f;
ll infLL = 0x3f3f3f3f3f3f3f3f;

int D[N];

struct SegTree {
#define LF (x*2+1)
#define RT (x*2+2)
#define md ((lx+rx) >> 1)

    vector<pll> seg;
    vector<int> a;
    int sz;

    void build(int x , int lx, int rx){
        if(lx == rx){
            seg[x] = {a[lx] , a[lx]};
            return;
        }
        build(LF , lx , md);
        build(RT , md + 1 , rx);
        seg[x] = merge(seg[LF] , seg[RT]);
    }

    SegTree(int n , vector<int>v) {
        sz = n;
        seg.assign(4 * n, {0 , -infLL});
        a = v;
        build(0 , 0  , sz - 1);
    }

    pll merge(pll lf , pll rt){
        pll res;
        res.fi = lf.fi + rt.fi;
        res.se = max(lf.se , rt.se);
        return res;
    }

    void update(int l , int r, int x = 0, int lx = 0, int rx = -1) {
        if (rx == -1) rx = sz - 1;
        if (seg[x].se <= 2) return;
        if (r < lx or rx < l) return;
        if(lx == rx) {
            int New = D[seg[x].fi];
            seg[x] = {New, New};
            return;
        }
        update(l , r , LF , lx , md);
        update(l , r , RT , md + 1 , rx);
        seg[x] = merge(seg[LF] , seg[RT]);
    }


    pll query(int l, int r, int x = 0, int lx = 0, int rx = -1) {
        if (rx == -1)rx = sz - 1;
        if (r < lx or rx < l) return
            {0 , -infLL};
        if (l <= lx and rx <= r)
            return seg[x];
        return
            merge(query(l, r, LF, lx, md) , query(l, r, RT, md + 1, rx));
    }

#undef md
#undef LF
#undef RT
};

void TC() {
    int n , q;
    cin >> n >> q;
    vector<int>a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    SegTree seg(n , a);

    while(q--){
        int t , l , r , val;
        cin >> t;
        if(t & 1){
            cin >> l >> r;
            --l, --r;
            seg.update(l , r);
        }else{
            cin >> l >> r;
            --l, --r;
            cout << seg.query(l , r).fi << nl;
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
    mem(D , 0);
    for (int i = 1; i < N; ++i) {
        for (int j = i; j < N; j += i) {
            D[j]++;
        }
    }
// ————————————————————————————————————————————
    ll tc = 1;
//     cin >> tc;
    while (tc--)
    {
        TC();
    }

    return 0;
}