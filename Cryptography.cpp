// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/edu/course/2/lesson/4/4/practice/contest/274684/problem/B
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

ll MOD = 1e9 + 7;

ll add(ll a, ll b)
{
    return ((a % MOD) + (b % MOD)) % MOD;
}

ll sub(ll a, ll b)
{
    return ((a % MOD) - (b % MOD) + MOD) % MOD;
}

ll mul(ll a, ll b)
{
    return ((a % MOD) * (b % MOD)) % MOD;
}

struct SEG {
    array<int , 4>mat{1 , 0 , 0 , 1};

    SEG() {}

    SEG(array<int , 4>m){
        mat = m;
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
        ret.mat[0] = add(mul(lf.mat[0] , rt.mat[0]) , mul(lf.mat[1] , rt.mat[2]));
        ret.mat[1] = add(mul(lf.mat[0] , rt.mat[1]) , mul(lf.mat[1] , rt.mat[3]));
        ret.mat[2] = add(mul(lf.mat[2] , rt.mat[0]) , mul(lf.mat[3] , rt.mat[2]));
        ret.mat[3] = add(mul(lf.mat[2] , rt.mat[1]) , mul(lf.mat[3] , rt.mat[3]));
        return ret;
    }

    void build(vector<SEG> &v , int x , int lx , int rx){

        if(lx == rx){
            if(lx < n)
                seg[x] = v[lx];
            return;
        }

        build(v , LF , lx , md);
        build(v , RT , md + 1 , rx);

        seg[x] = merge(seg[LF] , seg[RT]);
    }

    void build(vector<SEG> &v){
        build(v , 0 , 0 , n - 1);
    }

    void update(int i , SEG val , int x , int lx , int rx){

        if(lx == rx){
            seg[x] = val;
            return;
        }

        if(i <= md)
            update(i , val , LF , lx , md);
        else
            update(i , val , RT , md + 1 , rx);

        seg[x] = merge(seg[LF] , seg[RT]);
    }

    void update(int i , SEG val){
        update(i , val , 0 , 0 , n - 1);
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
        return query(l , r , 0 , 0 , n - 1);
    }

#undef LF
#undef RT
#undef md
};

void TC() {
    int r , n , m;
    cin >> r >> n >> m;
    MOD = r;
    vector<SEG>a(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 4; ++j) {
            cin >> a[i].mat[j];
        }
    }
    segTree seg(n);
    seg.build(a);
    while(m--){
        int l ,r;
        cin >> l >> r;
        --l , --r;
        SEG ans = seg.query(l , r);
        for (int i = 0; i < 4; ++i) {
            cout << ans.mat[i] << ((i&1) ? nl : sp);
        }
        cout << nl;
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