// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/edu/course/2/lesson/5/4/practice/contest/280801/problem/B
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
const int N = 2e5 + 5, M = 1e3, LOG = 20, inf = 0x3f3f3f3f;
ll infLL = 0x3f3f3f3f3f3f3f3f;

struct SEG {
    ll sum = 0;

    SEG() {}
    SEG(ll x){
        sum = x;
    }
};

struct LAZY {
    ll start = 0 , end = 0 , step = 0;

    LAZY() {}

};

struct segTree {

#define LF 2*x+1
#define RT 2*x+2
#define md (lx+rx)/2

    int n;
    int sz = 1;
    vector<SEG> seg;
    vector<LAZY> lazy;

    segTree(int n){
        this->n = n;

        while(sz < n)
            sz *= 2;

        seg.assign(2 * sz , SEG());
        lazy.assign(2 * sz , LAZY());
    }

    SEG merge(SEG lf , SEG rt){
        SEG ret;
        ret.sum = lf.sum + rt.sum;
        return ret;
    }

    ll sum(ll start , ll end , ll step){
        ll len = (end - start) / step + 1;
        return len * (start + end) / 2;
    }

    void propagate(int x, int lx, int rx) {
        if (lazy[x].start == 0) return;

        seg[x].sum += sum(lazy[x].start , lazy[x].end , lazy[x].step);

        if (lx != rx) {
            ll left_len = md - lx + 1;
            ll left_end = lazy[x].start + (left_len - 1) * lazy[x].step;
            ll right_start = left_end + lazy[x].step;

            lazy[LF].start += lazy[x].start;
            lazy[LF].end += left_end;
            lazy[LF].step += lazy[x].step;

            lazy[RT].start += right_start;
            lazy[RT].end += lazy[x].end;
            lazy[RT].step += lazy[x].step;
        }
        lazy[x] = LAZY();
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

    void update(int l, int r, ll a , ll d , int x, int lx, int rx){
        propagate(x, lx, rx);

        if(rx < l || lx > r)
            return;

        if(l <= lx && rx <= r){
            lazy[x].start += a + (lx - l) * d;
            lazy[x].end += a + (rx - l) * d;
            lazy[x].step += d;
            propagate(x, lx, rx);
            return;
        }
        update(l , r , a , d , LF , lx , md);
        update(l , r , a , d , RT , md + 1 , rx);

        seg[x] = merge(seg[LF] , seg[RT]);
    }

    void update(int l , int r , ll a , ll d){
        update(l , r , a , d , 0 , 0 , sz - 1);
    }

    SEG query(int l , int r , int x , int lx , int rx){
        propagate(x, lx, rx);

        if(rx < l || lx > r)
            return SEG();

        if(l <= lx && rx <= r)
            return seg[x];

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
    int n , q;
    cin >> n >> q;
    segTree seg(n);
    while(q--){
        int ty , l , r , a , d , idx;
        cin >> ty;
        if(ty&1){
            cin >> l >> r >> a >> d;
            seg.update(--l , --r , a , d);
        }else{
            cin >> idx;
            --idx;
            cout << seg.query(idx , idx).sum << nl;
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