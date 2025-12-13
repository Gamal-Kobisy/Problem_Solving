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
#define MSB(n) (63 - __builtin_clzll(n))
#define LSB(n) (__builtin_ctzll(n))
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
const int N = 1e7 + 5, M = 1e3, LOG = 20, inf = 0x3f3f3f3f;
ll infLL = 0x3f3f3f3f3f3f3f3f;

vector<int> primes;
vector<bool> is_prime;

void Sieve(int n = N) {
    is_prime.assign(n + 1, true);
    is_prime[0] = is_prime[1] = false;

    for (int i = 2; i <= n; i++) {
        if (is_prime[i]) {
            primes.emplace_back(i);
            for (ll j = 1LL * i * i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }
}

bool IsPrime(int n){
    if(n > 1e7) return false;
    else return is_prime[n];
}

struct SegTree {
#define LF (x*2+1)
#define RT (x*2+2)
#define md ((lx+rx) >> 1)

    struct Node{
        int num , ans;
        Node(){
            ans = 0;
        }
        Node(int n){
            num = n;
            ans = IsPrime(n);
        }
    };


    vector<Node> seg;
    vector<int> lazy;
    int sz;

    SegTree(int n) {
        sz = n;
        seg.assign(4 * n, 0);
        lazy.assign(4 * n, 0);
    }

    Node merge(const Node& lf , const Node& rt){
        Node res;
        res.ans = lf.ans + rt.ans;
        return res;
    }


    void propegate(int x, int lx, int rx) {
        if (!lazy[x])return;
        if (lx != rx) {
            lazy[LF] = lazy[x];
            lazy[RT] = lazy[x];
        }
        int len = rx - lx + 1;
        seg[x].ans = len * IsPrime(lazy[x]);
        seg[x].num = lazy[x];
        lazy[x] = 0;
    }

    void update(int l, int r, int val, int x = 0, int lx = 0, int rx = -1) {
        if (rx == -1) rx = sz - 1;
        propegate(x, lx, rx);
        if (r < lx or rx < l)return;
        if (l <= lx and rx <= r) {
            lazy[x] = val;
            propegate(x, lx, rx);
            return;
        }
        update(l, r, val, LF, lx, md);
        update(l, r, val, RT, md + 1, rx);
        seg[x] = merge(seg[LF] , seg[RT]);
    }

    void update2(int i , int val , int x = 0 , int lx = 0 , int rx = -1){
        if(rx == -1) rx = sz - 1;
        propegate(x , lx , rx);
        if(lx == rx){
            seg[x].num += val;
            seg[x].ans = IsPrime(seg[x].num);
            propegate(x, lx, rx);
            return;
        }
        if(i <= md) update2(i, val, LF, lx, md);
        else update2(i, val, RT, md + 1, rx);
        seg[x] = merge(seg[LF] , seg[RT]);
    }


    Node query(int l, int r, int x = 0, int lx = 0, int rx = -1) {
        if (rx == -1)rx = sz - 1;
        propegate(x, lx, rx);
        if (r < lx or rx < l) return Node(0);
        if (l <= lx and rx <= r) return seg[x];
        return merge(query(l, r, LF, lx, md) , query(l, r, RT, md + 1, rx));
    }


#undef md
#undef LF
#undef RT
};

void TC() {
    int n , q;
    cin >> n >> q;
    SegTree seg(n);
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        seg.update2(i, a);
    }
    while(q--){
        char t;
        cin >> t;
        int val , a , l , r;
        if(t == 'A'){
           cin >> val >> l;
            seg.update2(--l,val);
        }else if(t == 'R'){
            cin >> a >> l >> r;
            seg.update(--l , --r , a);
        }else{
            cin >> l >> r;
            cout << seg.query(--l , --r).ans << nl;
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
    Sieve();
// ————————————————————————————————————————————
    ll tc = 1;
//     cin >> tc;
    while (tc--)
    {
        TC();
    }

    return 0;
}