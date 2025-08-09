// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/edu/course/2/lesson/4/2/practice/contest/273278/problem/D
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
private:
#define L 2*node+1
#define R 2*node+2
#define mid (l+r>>1)
    int sz;vector<ll>seg;
    void build(int l,int r,int node,vector<ll>&arr)
    {
        if(l==r)
        {
            if(l<arr.size())
            {
                seg[node]=arr[l];
            }
            return;
        }
        build(l,mid,L,arr);
        build(mid+1,r,R,arr);
        seg[node]=max(seg[L],seg[R]);
    }
    void update(int l,int r,int node,int idx,ll val)
    {
        if(l==r)
        {
            seg[node]=val;
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
        seg[node]=max(seg[L],seg[R]);
    }
    ll query(int l , int r , int node , int k , int lq)
    {
        if(k > seg[node] || r < lq)
            return -1;
        if(l == r)
            return l;

        ll lft = query(l , mid , L , k , lq);
        if(lft == -1)
            return query(mid + 1 , r , R , k , lq);
        else
            return lft;
    }
public:
    SegmentTree(vector<ll>&arr)
    {
        sz=1;int n=arr.size();
        while(sz<n) sz*=2;
        seg=vector<ll>(sz*2 , -infLL);
        build(0,sz-1,0,arr);
    }
    void update(int idx,ll val)
    {
        update(0,sz-1,0,idx,val);
    }
    ll query(int k , int l)
    {
        return query(0,sz-1,0,k , l);
    }
#undef L
#undef R
};
void solve() {
    int n , m;
    cin >> n >> m;
    vector<ll>v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    SegmentTree SegT(v);

    while(m--)
    {
        ll a , b , c;
        cin >> a >> b >> c;
        if (a == 1) {
            SegT.update(b, c);
        } else
            cout << SegT.query(b , c) << nl;
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