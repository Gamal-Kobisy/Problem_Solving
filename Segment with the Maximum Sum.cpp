// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/edu/course/2/lesson/4/2/practice/contest/273278/problem/A
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
#define L 2*node+1
#define R 2*node+2
#define mid (l+r>>1)
private:
    struct Node{
        ll ans, pre , suf , sum;
        Node(): pre(0), suf(0), ans(0), sum(0){}
        Node(ll a , ll b , ll c , ll d): ans(a), pre(b), suf(c), sum(d){};
    };
    int sz;vector<Node>seg;
    Node merge(Node a, Node b)
    {
        Node ret;
        ret.sum = a.sum+b.sum;
        ret.ans = max({a.ans , b.ans , a.suf + b.pre});
        ret.pre = max(a.pre , a.sum + b.pre);
        ret.suf = max(b.suf , b.sum + a.suf);
        return ret;
    }
    void build(int l,int r,int node,vector<ll>&arr)
    {
        if(l==r)
        {
            if(l<arr.size())
            {
                seg[node] = Node(arr[l] , arr[l] , arr[l] , arr[l]);
            }
            return;
        }
        build(l,mid,L,arr);
        build(mid+1,r,R,arr);
        seg[node]=merge(seg[L],seg[R]);
    }
    void update(int l,int r,int node,int idx,ll val)
    {
        if(l==r)
        {
            seg[node].sum = seg[node].ans = seg[node].pre = seg[node].suf = val;
            return;
        }
        if(idx<=mid)
        {
            update(l,mid,L,idx,val);
        }
        else
        {
            update(mid+1,r,R,idx,val);
        }
        seg[node]=merge(seg[L],seg[R]);
    }
    Node query(int l, int r, int node, int lq, int rq)
    {
        if(r<lq||l>rq)
        {
            return Node(0 , 0 , 0 , 0);
        }
        if(l>=lq&&r<=rq)
        {
            return seg[node];
        }
        Node lft=query(l, mid, L, lq, rq);
        Node rgt=query(mid + 1, r, R, lq, rq);
        return merge(lft,rgt);
    }
public:
    SegmentTree (vector<ll>arr)
    {
        sz=1;int n=arr.size();
        while(sz<n) sz*=2;
        seg = vector<Node>(sz * 2 , Node(0 , 0 , 0 , 0));
        build(0,sz-1,0,arr);
    }
    void update(int idx,int val)
    {
        update(0,sz-1,0,idx,val);
    }
    ll query(int l,int r)
    {
       return query(0,sz-1,0,l,r).ans;
    }
};
void solve() {
    int n , m;
    cin >> n >> m;
    vector<ll>a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    SegmentTree SegT(a);
    cout << max(0ll , SegT.query(0 , n - 1)) << nl;
    while(m--)
    {
        ll a , b;
        cin >> a >> b;
        SegT.update(a , b);
        cout << max(0ll , SegT.query(0 , n - 1)) << nl;
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