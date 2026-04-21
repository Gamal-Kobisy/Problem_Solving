// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/group/reRlOrZJrU/contest/676893/problem/K
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
const int N = 2e5 + 5, M = 1e3, LOG = 22, inf = 0x3f3f3f3f;
ll infLL = 0x3f3f3f3f3f3f3f3f;

struct SEG {
    ll sum = 0;
    ll pref = -infLL;
    ll suff = -infLL;
    ll ans = -infLL;

    SEG() {}

    SEG(ll x){
        sum = x;
        pref = x;
        suff = x;
        ans = x;
    }
};

struct segTree {

#define LF 2*x+1
#define RT 2*x+2
#define md (lx+rx)/2

    int n;
    int sz = 1;
    vector<SEG> seg;

    segTree(int n){
        this->n = n;

        while(sz < n)
            sz *= 2;

        seg.assign(2 * sz , SEG());
    }

    SEG merge(SEG lf , SEG rt){
        SEG ret;
        ret.sum = lf.sum + rt.sum;
        ret.pref = max(lf.pref, lf.sum + rt.pref);
        ret.suff = max(rt.suff, rt.sum + lf.suff);
        ret.ans = max({lf.ans, rt.ans, lf.suff + rt.pref});
        return ret;
    }

    void build(vector<int> &v , int x , int lx , int rx){

        if(lx == rx){
            if(lx < n)
                seg[x] = SEG(v[lx]);
            return;
        }

        build(v , LF , lx , md);
        build(v , RT , md + 1 , rx);

        seg[x] = merge(seg[LF] , seg[RT]);
    }

    void build(vector<int> &v){
        build(v , 0 , 0 , sz - 1);
    }

    void update(int i , ll val , int x , int lx , int rx){

        if(lx == rx){
            seg[x] = SEG(val);
            return;
        }

        if(i <= md)
            update(i , val , LF , lx , md);
        else
            update(i , val , RT , md + 1 , rx);

        seg[x] = merge(seg[LF] , seg[RT]);
    }

    void update(int i , ll val){
        update(i , val , 0 , 0 , sz - 1);
    }

    SEG query(int l , int r , int x , int lx , int rx){

        if(l <= lx && rx <= r)
            return seg[x];

        if(rx < l || lx > r)
            return SEG();

        return merge(
                query(l , r , LF , lx , md),
                query(l , r , RT , md + 1 , rx)
        );
    }

    SEG query(int l , int r){
        return query(l , r , 0 , 0 , sz - 1);
    }

#undef LF
#undef RT
#undef md
};

void TC() {
    int n;
    cin >> n;
    vector<pii>a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].fr;
        a[i].sc = i;
    }
    sort(all(a));
    int q;
    cin >> q;
    vector<int>L(q), R(q), ans(q);
    vector<array<int , 3>>queries(q);
    vector<vector<int>>buckets(n);
    for (int i = 0; i < q; ++i) {
        int l , r , w;
        cin >> l >> r >> w;
        queries[i] = {--l , --r , w};
        L[i] = 0 , R[i] = n - 1;
    }
    int steps = LOG;
    while(steps--){
        for (int i = 0; i < q; ++i) {
            if(L[i] <= R[i]) buckets[(L[i] + R[i])/2].pb(i);
        }
        segTree seg(n);
        for (int i = 0; i < n; ++i) {
            seg.update(i , -inf);
        }
        for (int mid = n - 1; mid >= 0; --mid) {
            auto [val , idx] = a[mid];
            seg.update(idx , 1);
            for(auto query : buckets[mid]){
                auto [l , r , w] = queries[query];
                if(seg.query(l , r).ans >= w) {
                    ans[query] = val;
                    L[query] = mid + 1;
                }else{
                    R[query] = mid - 1;
                }
            }
            buckets[mid].clear();
        }
    }
    for(int i : ans) cout << i << nl;
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