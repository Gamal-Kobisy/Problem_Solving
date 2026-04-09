// "??? ????? ???? ??? ???? ??? ???"
// "??? ?? ???? ???? ????? ??? ??? ???? ??? ??? ?? ?????? ??? ????? ?? ??? ????"

// LINK :
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define ld long double
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
// ????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????
const int N = 2e5 + 5, M = 1e3, LOG = 20, inf = 0x3f3f3f3f;
ll infLL = 0x3f3f3f3f3f3f3f3f;



struct segTree {

#define LF 2*x+1
#define RT 2*x+2
#define md (lx+rx)/2

    int n;
    int sz = 1;
    vector<vector<pll>> seg;

    segTree(int n){
        this->n = n;

        while(sz < n)
            sz *= 2;

        seg.assign(2 * sz , vector<pll>(0));
    }

    vector<pll> merge(vector<pll> lf , vector<pll> rt){
        vector<pll> ret;
        int i = 0 , j = 0;
        while(i < lf.size() or j < rt.size()){
            if(j >= rt.size() or (i < lf.size() and  lf[i].fr < rt[j].fr)){
                ret.push_back(lf[i]);
                i++;
            }else{
                ret.push_back(rt[j]);
                j++;
            }
        }
        ret.front().sc = ret.front().fr;
        for (int k = 1; k < ret.size(); ++k) {
            ret[k].sc = ret[k - 1].sc + ret[k].fr;
        }
        return ret;
    }

    void build(vector<int> &v , int x , int lx , int rx){

        if(lx == rx){
            if(lx < n)
                seg[x] = vector<pll>(1 , make_pair(v[lx] , v[lx]));
            else
                seg[x] = vector<pll>(1 , make_pair(0 , 0));

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
            seg[x] = vector<pll>(1 , make_pair(val , val));
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

    vector<pll> query(int l , int r , int k , int x , int lx , int rx){

        if(l <= lx && rx <= r)
            return seg[x];

        if(rx < l || lx > r)
            return {};

        return merge(
                query(l , r , k , LF , lx , md),
                query(l , r , k , RT , md + 1 , rx)
        );
    }

    ll query(int l , int r , int k){
        vector<pll>ans = query(l , r , k , 0 , 0 , sz - 1);
        auto it = upper_bound(all(ans) , make_pair(k , infLL));
        if(it == ans.begin()) return 0;
        else it = prev(it);
        return it->sc;
    }

#undef LF
#undef RT
#undef md
};

void TC() {
    int n;
    cin >> n;
    vector<int>a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    segTree seg(n);
    seg.build(a);
    int q;
    cin >> q;
    while(q--){
        int l , r , k;
        cin >> l >> r >> k;
        ll ans = seg.query(--l , --r , k);
        cout << ans << nl;
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
// test-independent code ??????????????????????
// ????????????????????????????????????????????
    ll tc = 1;
//     cin >> tc;
    while (tc--)
    {
        TC();
    }

    return 0;
}