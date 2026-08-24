// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/group/Rilx5irOux/contest/627262/problem/D
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
    int mx = -inf;
    SEG() {}
    SEG(pii val){
        sum = val.fr;
        mx = val.sc;
    }
};

struct LAZY {
    ll add = 0;

    LAZY() {}
    LAZY(ll val){
        add = val;
    }
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
        ret.mx = max(lf.mx,rt.mx);
        return ret;
    }

    void propagate(int x, int lx, int rx) {
        if (lazy[x].add == 0) return;

        seg[x].sum += lazy[x].add * (rx - lx + 1);
        // seg[x].mx = max((ll)seg[x].mx, seg[x].sum);
        if (lx != rx) {
            lazy[LF].add += lazy[x].add;
            lazy[RT].add += lazy[x].add;
        }
        lazy[x] = LAZY();
    }

    void build(vector<pii> &v , int x , int lx , int rx){

        if(lx == rx){
            if(lx < n)
                seg[x] = SEG(v[lx]);
            return;
        }

        build(v , LF , lx , md);
        build(v , RT , md + 1 , rx);

        seg[x] = merge(seg[LF] , seg[RT]);
    }

    void build(vector<pii> &v){
        build(v , 0 , 0 , sz - 1);
    }

    void update(int l, int r, ll val , int limit, int x, int lx, int rx){
        propagate(x, lx, rx);

        if(rx < l || lx > r || seg[x].mx < limit)
            return;

        if(l <= lx && rx <= r){
            lazy[x].add += val;

            propagate(x, lx, rx);
            return;
        }
        update(l , r , val , limit , LF , lx , md);
        update(l , r , val , limit , RT , md + 1 , rx);

        seg[x] = merge(seg[LF] , seg[RT]);
    }

    void update(int l , int r , ll val , int limit){
        update(l , r , val , limit , 0 , 0 , sz - 1);
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
    vector<pii> v(n);
    for (int i = 0; i < n; i++) cin >> v[i].fr;
    for (int i = 0; i < n; i++) cin >> v[i].sc;
    segTree seg(n);
    seg.build(v);
    while (q--)
    {
        int ty , l , r , val , x , idx;
        cin >> ty;
        if (ty == 1)
        {
            cin >> l >> r >> x >> val;
            seg.update(--l , --r - 1 , val , x);
        }else
        {
            cin >> idx;
            idx--;
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
