// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/edu/course/2/lesson/5/4/practice/contest/280801/problem/A
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
    ll add = 0;
    ll ass_val = 0;
    bool is_ass = false;
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

    void propagate(int x, int lx, int rx) {
        if (lazy[x].is_ass) {
            seg[x].sum = lazy[x].ass_val * (rx - lx + 1);

            if (lx != rx) {
                lazy[LF].is_ass = true;
                lazy[LF].ass_val = lazy[x].ass_val;
                lazy[LF].add = 0;

                lazy[RT].is_ass = true;
                lazy[RT].ass_val = lazy[x].ass_val;
                lazy[RT].add = 0;
            }
            lazy[x].is_ass = false;
        }

        if (lazy[x].add > 0) {
            seg[x].sum += lazy[x].add * (rx - lx + 1);

            if (lx != rx) {
                lazy[LF].add += lazy[x].add;
                lazy[RT].add += lazy[x].add;
            }
            lazy[x].add = 0;
        }
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

    void update(int l, int r, ll val, int op, int x, int lx, int rx){
        propagate(x, lx, rx);

        if(rx < l || lx > r)
            return;

        if(l <= lx && rx <= r){
            if (op == 1) {
                lazy[x].is_ass = true;
                lazy[x].ass_val = val;
                lazy[x].add = 0;
            } else {
                lazy[x].add += val;
            }
            propagate(x, lx, rx);
            return;
        }

        update(l , r , val , op, LF , lx , md);
        update(l , r , val , op, RT , md + 1 , rx);

        seg[x] = merge(seg[LF] , seg[RT]);
    }

    void update(int l , int r , ll val, int op){
        update(l , r , val , op, 0 , 0 , sz - 1);
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
    int n, m;
    cin >> n >> m;
    segTree seg(n);

    while(m--) {
        int type;
        int l, r; ll v;
        cin >> type;
        if (type == 1) {
            cin >> l >> r >> v;
            seg.update(l, r - 1, v, 1);
        }
        else if (type == 2) {
            cin >> l >> r >> v;
            seg.update(l, r - 1, v, 2);
        }
        else if (type == 3) {
            cin >> l >> r;
            cout << seg.query(l, r - 1).sum << nl;
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