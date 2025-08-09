// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/edu/course/2/lesson/5/1/practice/contest/279634/problem/C
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
    int sz;vector<pair<int , int>>seg;
    pair<int , int>merge(pair<int , int>a , pair<int , int>b)
    {
        if(a.first > b.first)
            return a;
        else
            return b;
    }
    void update(int l , int r , int node , int lq , int rq , int time , int val){
        if(r < lq || l > rq)
            return;
        if(l >= lq && r <= rq)
        {
            seg[node] = {time , val};
            return;
        }
        update(l , mid , L , lq , rq , time , val);
        update(mid + 1 , r , R , lq , rq , time , val);
    }
    pair<int , int> query(int l , int r , int node , int idx){
        if(l == r)
            return seg[node];
        if(idx <= mid)
        {
            return merge(seg[node] , query(l , mid , L , idx));
        }
        return merge(seg[node] , query(mid  + 1 , r , R , idx));
    }
public:
    SegmentTree(int n)
    {
        sz = 1;
        while(sz < n) sz *= 2;
        seg = vector<pair<int , int>>(sz * 2 , {- 1 , 0});
    }
    void update(int l , int r , int time , int val)
    {
        update(0 , sz - 1 , 0 , l , r , time , val);
    }
    ll query(int idx)
    {
        return query(0 , sz - 1 , 0 , idx).second;
    }
#undef L
#undef R
#undef mid
};

void solve() {
    ll n , m;
    cin >> n >> m;
    SegmentTree tree(n);
    for (int i = 0; i < m; ++i) {
        ll op;
        cin >> op;
        if(op == 1)
        {
            int l , r , val;
            cin >> l >> r >> val;
            tree.update(l , r - 1 , i , val);
        }
        else
        {
            int idx;
            cin >> idx;
            cout << tree.query(idx) << nl;
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