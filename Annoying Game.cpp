// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/contest/2158/problem/C
#pragma GCC optimize("O3")
#pragma GCC optimize ("unroll-loops")
#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
#pragma GCC target("avx2")
using namespace std;
#define ll long long
#define ld long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define PI acos(-1)
#define Ones(n) __builtin_popcountll(n)
#define mem(arrr, xx) memset(arrr,xx,sizeof arrr)
#define fi first
#define se second
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

struct segTree{
#define LF 2*x+1
#define RT 2*x+2
#define mid (lx+rx)/2

    struct Node{
        ll ans , sum , pre , suf;
        Node(): pre(0), suf(0), ans(0), sum(0){}
        Node(ll a): ans(a), pre(a), suf(a), sum(a){};
    };
    int sz;
    vector<Node>seg;


    Node merge(Node a , Node b){
        Node ret;
        ret.sum = a.sum + b.sum;
        ret.ans = max({a.ans , b.ans , a.suf + b.pre});
        ret.pre = max(a.pre , a.sum + b.pre);
        ret.suf = max(b.suf , b.sum + a.suf);
        return ret;
    }

    segTree(int n){
        sz = n;
        seg = vector<Node>(4 * sz + 1);
    }

    void update(int i , int val , int x = 0 , int lx = 0 , int rx = -1){
        if(rx == -1) rx = sz - 1;

        if(lx == rx){
            seg[x] = Node(val);
            return;
        }

        if(i <= mid){
            update(i , val , LF , lx , mid);
        }else{
            update(i , val , RT , mid + 1 , rx);
        }
        seg[x] = merge(seg[LF] , seg[RT]);
    }

    Node query(int l , int r , int x = 0 , int lx = 0 , int rx = -1){
        if(rx == -1) rx = sz - 1;
        if(rx < l or lx > r) return Node(0);
        if(lx >= l and rx <= r) return seg[x];
        return merge(query(l , r , LF , lx , mid) ,
                     query(l , r , RT , mid + 1 , rx));
    }


};

void TC() {
    int n , k;
    cin >> n >> k;
    vector<int>a(n) , b(n);
    segTree seg(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        seg.update(i , a[i]);
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    if(k % 2 == 0) return void(cout << seg.query(0 , n - 1).ans << nl);
    ll ans = -infLL;
    for (int i = 0; i < n; ++i) {
        seg.update(i , a[i] + b[i]);
        ans = max(ans , seg.query(0 , n - 1).ans);
        seg.update(i , a[i]);
    }
    cout << ans << nl;
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