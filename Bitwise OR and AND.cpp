// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/edu/course/2/lesson/5/2/practice/contest/279653/problem/C
#include <bits/stdc++.h>
#define ll long long
#define nl '\n'
#define sp ' '
#define all(a) a.begin(),a.end()
#define allr(a) a.rbegin(),a.rend()
#define no cout<<"NO\n"
#define yes cout<<"YES\n"
#define ENG_GAMAL ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;
// ————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
const int N = 2e5 + 5, M = 1e3, LOG = 20, inf = 0x3f3f3f3f;
ll infLL = 0x3f3f3f3f3f3f3f3f;
struct SegmentTree{
#define L node*2+1
#define R node*2+2
#define mid (l + r >> 1)
private:
    ll sz; vector<ll>seg , lazy;
    ll merge(ll a , ll b)
    {
        return (a & b);
    }
    void propegate(int l , int r , int node){
        if(lazy[node] == 0)
            return;
        if(l != r)
        {
            lazy[L] |= lazy[node];
            lazy[R] |=lazy[node];
        }
        seg[node] |= lazy[node];
        lazy[node] = 0;
    }
    void update(int l , int r , int node , int lq , int rq , ll val){
        propegate(l , r , node);
        if(r < lq || l > rq)
            return;
        if(l >= lq && r <= rq) {
            lazy[node] |= val;
            propegate(l, r, node);
            return;
        }
        update(l , mid , L , lq , rq , val);
        update(mid + 1 , r , R , lq , rq , val);
        seg[node] = merge(seg[L] , seg[R]);
    }
    ll query(int l , int r , int node , int lq , int rq){
        propegate(l , r , node);
        if(r < lq || l > rq)
            return (2ll << 30) - 1;
        if(l >= lq && r <= rq)
            return seg[node];
        return merge(query(l , mid , L , lq , rq) , query(mid + 1 , r , R , lq , rq));
    }

public:
    SegmentTree(int n)
    {
        sz = 1;
        while(sz < n) sz *= 2;
        seg = vector<ll>(sz * 2);
        lazy = vector<ll>(sz * 2);
    }
    void update(int l , int r , ll val){
        update(0 , sz - 1 , 0 , l , r , val);
    }
    ll query(int l , int r)
    {
        return query(0 , sz - 1 , 0 , l , r);
    }
};

void solve() {
    int n , m;
    cin >> n >> m;
    SegmentTree tree(n);
    while(m--)
    {
        int op ;
        cin >> op;
        if(op == 1)
        {
            ll l , r , val;
            cin >> l >> r >> val;
            tree.update(l , r - 1 , val);
        }
        else
        {
            int l , r;
            cin >> l >> r;
            cout << tree.query(l , r - 1) << nl;
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
    ll t = 1;
//     cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}