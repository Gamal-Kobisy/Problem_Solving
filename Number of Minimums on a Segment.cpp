// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/edu/course/2/lesson/4/1/practice/contest/273169/problem/C
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
    int sz;vector<pair<int , int>>seg;

    pair<int , int>merge(pair<int , int>a , pair<int , int>b)
    {
        pair<int , int>ret;
        if(a.first == b.first)
            ret = {a.first , a.second + b.second};
        else if(a.first < b.first)
            ret = a;
        else
            ret = b;
        return ret;
    }
    void build(int l,int r,int node,vector<ll>&arr)
    {
        if(l==r)
        {
            if(l<arr.size())
            {
                seg[node]={arr[l] , 1};
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
            seg[node].first = val;
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
    pair<int , int> query(int l,int r,int node,int lq,int rq)
    {
        if(r<lq||l>rq)
        {
            return {inf , 1};
        }
        if(l>=lq&&r<=rq)
        {
            return seg[node];
        }
        pair<int , int> lft=query(l,mid,L,lq,rq);
        pair<int , int> rgt=query(mid+1,r,R,lq,rq);
        return merge(lft,rgt);
    }
public:
    SegmentTree(vector<ll>&arr)
    {
        sz=1;int n=arr.size();
        while(sz<n) sz*=2;
        seg=vector<pair<int , int>>(sz*2 , {1 , inf});
        build(0,sz-1,0,arr);
    }
    void update(int idx,ll val)
    {
        update(0,sz-1,0,idx,val);
    }
    pair<int , int> query(int l,int r)
    {
        return query(0,sz-1,0,l,r);
    }
#undef L
#undef R
};
void solve() {
    int n , m;
    cin >> n >> m;
    vector<ll>a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    SegmentTree SegT(a);

    while(m--)
    {
        ll a , b , c;
        cin >> a >> b >> c;
        if(a == 1)
            SegT.update(b, c);
        else
        {
            pair<int , int> ans = SegT.query(b , c - 1);
            cout << ans.first << sp << ans.second << nl;
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