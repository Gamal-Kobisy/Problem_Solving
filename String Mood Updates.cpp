// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/gym/102644/problem/H
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
const int mod = 1e9 + 7;
typedef vector<ll> row;
typedef vector<row> mat;

mat operator*(const mat &a, const mat &b) {
    int r1 = a.size(), r2 = b.size(), c2 = b[0].size();
    mat ret(r1, row(c2));
    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c2; j++)
            for (int k = 0; k < r2; k++)
                ret[i][j] += a[i][k] * b[k][j], ret[i][j] %= mod;
    return ret;
}

mat operator^(const mat &a, ll k) {
    mat ret(a.size(), row(a.size()));
    for (int i = 0; i < a.size(); i++)ret[i][i] = 1;
    for (mat tmp = a; k; tmp = tmp * tmp, k /= 2)if (k & 1)ret = ret * tmp;
    return ret;
}
struct SEG {
    mat t = {{1 , 0} , {0 , 1}};

    SEG() {}

    SEG(char c){
        if(c == 'H'){
            t = {{1 , 0} , {1 , 0}};
        }else if(c == 'S' or c == 'D'){
            t = {{0 , 1} , {0 , 1}};
        }else if(c == 'A' or c == 'E' or c == 'I' or c == 'O' or c == 'U'){
            t = {{0 , 1} , {1 , 0}};
        }else if(c == '?'){
            t = {{19 , 7} , {6 , 20}};
        }else{
            t = {{1 , 0} , {0 , 1}};
        }
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
        ret.t = lf.t * rt.t;
        return ret;
    }

    void build(string &s , int x , int lx , int rx){

        if(lx == rx){
            if(lx < n)
                seg[x] = SEG(s[lx]);
            return;
        }

        build(s , LF , lx , md);
        build(s , RT , md + 1 , rx);

        seg[x] = merge(seg[LF] , seg[RT]);
    }

    void build(string &s){
        build(s , 0 , 0 , sz - 1);
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
    int n , q;
    cin >> n >> q;
    string s;
    cin >> s;
    segTree seg(n);
    seg.build(s);
    cout << seg.seg[0].t[0][0] << nl;
    while(q--){
        int idx;
        char c;
        cin >> idx >> c;
        seg.update(--idx , c);
        cout << seg.seg[0].t[0][0] << nl;
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