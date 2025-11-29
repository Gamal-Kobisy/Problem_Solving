// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/contest/914/problem/D
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

ll gcd(ll a, ll b) {
    while (b != 0) {
        ll temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

ll gcd_vector(const vector<ll>& vec) {
    ll result = vec[0];
    for (size_t i = 1; i < vec.size(); ++i) {
        result = gcd(result, vec[i]);
        if (result == 1) {
            return 1;
        }
    }
    return result;
}

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

    void update(int i , int val , int x = 0 , int lx = 0 , int rx = -1){
        if(rx == -1) rx = sz - 1;

        if(lx == rx){
            seg[x] = val;
            return;
        }

        if(i <= mid){
            update(i , val , LF , lx , mid);
        }else{
            update(i , val , RT , mid + 1 , rx);
        }
        seg[x] = gcd(seg[LF] , seg[RT]);
    }

    ll query(int l , int r , int x = 0 , int lx = 0 , int rx = -1){
        if(rx == -1) rx = sz - 1;
        if(l > r or rx < l or lx > r) return 0;
        if(lx >= l and rx <= r) return seg[x];
        return gcd(query(l , r , LF , lx , mid) ,
                   query(l , r , RT , mid +1 , rx));
    }

    bool can(int l , int r , int g){
        if(l == r)
            return true;
        ll m = (l + r) / 2;
        ll rmR = query(l , m);
        ll rmL = query(m + 1 , r);
        bool goR = rmR % g == 0;
        bool goL = rmL % g == 0;
        if(goR and not goL){
            return can(m + 1 , r , g);
        }else if(goL and not goR){
            return can(l , m , g);
        }else{
            return false;
        }
    }

    int firstError(int l , int r , int g , int x = 0 , int lx = 0 , int rx = -1){
        if(rx == -1) rx = sz - 1;

        if(r < lx || rx < l) return -1;
        if(seg[x] % g == 0) return -1;
        if(lx == rx) return lx;

        int leftAns = firstError(l , r , g , LF , lx , mid);
        if(leftAns != -1) return leftAns;

        return firstError(l , r , g , RT , mid + 1 , rx);
    }

};

void TC() {
    int n;
    cin >> n;
    segTree seg(n);
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        seg.update(i , a);
    }
    int q;
    cin >> q;
    while(q--){
       int t , l , r , x , i , val;
       cin >> t;
       if(t & 1){
           cin >> l >> r >> x;
           --l, --r;
           ll g = seg.query(l,r);
           if (g % x == 0){
               yes;
               continue;
           }
           int pos = seg.firstError(l , r , x);
           if(pos == -1){
               no;
               continue;
           }
           ll newG = gcd(seg.query(l , pos - 1) , seg.query(pos + 1 , r));
           if(newG % x == 0) yes;
           else no;
       }else{
           cin >> i >> val;
           seg.update(--i , val);
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