// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/edu/course/2/lesson/4/3/practice/contest/274545/problem/D
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

    SEG merge(SEG a , SEG b){
        SEG ret;
        ret.sum = a.sum + b.sum;
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
        build(v , 0 , 0 , n - 1);
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
    int n;
    cin >> n;
    vector<int>L(n + 1 , -1), ans(n + 1);
    segTree seg(2 * n);
    vector<int>a(2 * n);
    for (int i = 0; i < 2 * n; ++i) {
        cin >> a[i];
        int x = a[i];
        if(~L[x]){
            seg.update(L[x] , 0);
            ans[x] = seg.query(L[x] , i).sum;
        }else{
            L[x] = i;
            seg.update(i , 1);
        }
    }
    for(int i = 0 ; i < 2 * n ; i++) seg.update(i , 0);
    L = vector<int>(n + 1 , -1);
    reverse(all(a));
    for (int i = 0; i < 2 * n; ++i) {
        int x = a[i];
        if(~L[x]){
            seg.update(L[x] , 0);
            ans[x] += seg.query(L[x] , i).sum;
        }else{
            L[x] = i;
            seg.update(i , 1);
        }
    }
    for (int i = 1; i <= n; ++i) {
        cout << ans[i] << sp;
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