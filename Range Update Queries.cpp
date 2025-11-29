// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://cses.fi/problemset/task/1651/
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

    int sz;
    vector<ll>seg;

    segTree(int n){
        sz = n;
        seg = vector<ll>(4 * sz + 1 , 0);
    }

    void update(int l , int r , int val , int x = 0 , int lx = 0 , int rx = -1){
        if(rx == -1) rx = sz - 1;

        if(l > rx or r < lx) return;
        if(lx >= l and rx <= r) {
            seg[x] += val;
            return;
        }
        update(l , r , val , LF , lx , mid);
        update(l , r , val , RT , mid + 1 , rx);
    }

    ll query(int i , int x = 0 , int lx = 0 , int rx = -1){
        if(rx == -1) rx = sz - 1;
        if(lx == rx) return seg[x];

        if(i <= mid){
            return seg[x] + query(i , LF , lx , mid);
        }else{
            return seg[x] + query(i , RT, mid + 1 , rx);
        }
    }


};

void TC() {
    int n , q;
    cin >> n >> q;
    segTree seg(n);
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        seg.update(i , i , a);
    }

    while(q--){
        int t , i , value , l , r;
        cin >> t;
        if(t == 1){
            cin >> l >> r >> value;
            seg.update(--l , --r , value);
        }else{
            cin >> i;
            cout << seg.query(--i) << nl;
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