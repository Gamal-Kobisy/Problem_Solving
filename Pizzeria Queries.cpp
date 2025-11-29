// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK :
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
        int dif , sum;
        Node(): dif(inf), sum(inf){}
        Node(int d , int s): dif(d), sum(s){};
    };
    int sz;
    vector<Node>seg;


    Node merge(Node a , Node b){
        Node ret;
        ret.dif = min(a.dif , b.dif);
        ret.sum = min(a.sum , b.sum);
        return ret;
    }

    segTree(int n){
        sz = n;
        seg = vector<Node>(4 * sz + 1);
    }

    void update(int i , int val , int x = 0 , int lx = 0 , int rx = -1){
        if(rx == -1) rx = sz - 1;

        if(lx == rx){
            seg[x] = Node(val - i , val + i);
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
        if(rx < l or lx > r) return Node();
        if(lx >= l and rx <= r) return seg[x];
        return merge(query(l , r , LF , lx , mid) ,
                     query(l , r , RT , mid + 1 , rx));
    }

};

void TC() {
    int n , q;
    cin >> n >> q;
    segTree seg(n);
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        seg.update(i , a);
    }
    while (q--){
        int t , k , i , val;
        cin >> t;
        if(t == 1){
            cin >> i >> val;
            seg.update(--i , val);
        }else{
            cin >> k;
            int left = seg.query(0 , k - 1).dif;
            int right = seg.query(k - 1 , n - 1).sum;
            int ans = min(left + k - 1 , right - k + 1);
            cout << ans << nl;
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
//     cin >> tc;
    while (tc--)
    {
        TC();
    }

    return 0;
}