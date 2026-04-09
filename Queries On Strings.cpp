// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/group/Rilx5irOux/contest/638270/problem/G
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
    bool ok;
    char front , back;
    ll mask = 0;
    SEG() {
        front = back = '$';
        ok = true;
    }
    SEG(char x){
        front = back = x;
        mask |= (1ll << (x - 'a'));
        ok = true;
    }
};

struct LAZY {
    char c = '$';
    LAZY() {}
    LAZY(char x){
        c = x;
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
        if(lf.front == '$') return rt;
        if(rt.front == '$') return lf;

        SEG ret;
        ret.front = lf.front;
        ret.back = rt.back;

        ret.mask = lf.mask | rt.mask;

        if(not lf.ok or not rt.ok) ret.ok = false;
        else if(lf.back == rt.front) ret.ok = false;
        else if(Ones(ret.mask) != 2) ret.ok = false;
        else ret.ok = true;

        return ret;
    }

    void propagate(int x, int lx, int rx) {
        if (lazy[x].c == '$') return;

        seg[x].ok = (lx == rx);
        seg[x].front = lazy[x].c;
        seg[x].back = lazy[x].c;
        seg[x].mask = 0;
        seg[x].mask |= (1ll << (lazy[x].c - 'a'));
        if (lx != rx) {
            lazy[LF].c = lazy[x].c;
            lazy[RT].c = lazy[x].c;
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

    void update(int l, int r, ll val, int x, int lx, int rx){
        propagate(x, lx, rx);

        if(rx < l || lx > r)
            return;

        if(l <= lx && rx <= r){
            lazy[x].c = val;

            propagate(x, lx, rx);
            return;
        }
        update(l , r , val , LF , lx , md);
        update(l , r , val , RT , md + 1 , rx);

        seg[x] = merge(seg[LF] , seg[RT]);
    }

    void update(int l , int r , ll val){
        update(l , r , val , 0 , 0 , sz - 1);
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
    string s;
    cin >> s;
    vector<int>a(n);
    for (int i = 0; i < n; ++i) {
        a[i] = s[i];
    }
    segTree seg(n);
    seg.build(a);
    while(q--){
        string ty;
        int l , r;
        char c;
        cin >> ty;
        if(ty.front() == 'Q'){
            cin >> l >> r;
            seg.query(--l , --r).ok ? yes : no;
        }else{
            cin >> l >> r >> c;
            seg.update(--l , --r , c);
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
     cin >> tc;
    while (tc--)
    {
        TC();
    }

    return 0;
}