// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://cses.fi/problemset/task/2420
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
const int N = 2e5 + 5, M = 1e3, LOG = 20, inf = 0x3f3f3f3f;
ll infLL = 0x3f3f3f3f3f3f3f3f;

const ll MOD1 = 1e9 + 123;
const ll MOD2 = 2e9 + 333;
const int BASE1 = 313 , BASE2 = 317;
ll pw1[N], pw2[N];
ll invB1, invB2;
ll power(ll base, ll exp, ll mod) {
    ll res = 1;
    base %= mod;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return res;
}

ll modInverse(ll n, ll mod) {
    return power(n, mod - 2, mod);
}

void initHash() {
    pw1[0] = 1; pw2[0] = 1;
    for (int i = 1; i < N; i++) {
        pw1[i] = (pw1[i - 1] * BASE1) % MOD1;
        pw2[i] = (pw2[i - 1] * BASE2) % MOD2;
    }
    invB1 = modInverse(BASE1, MOD1);
    invB2 = modInverse(BASE2, MOD2);
}

struct HashString {
    int len;
    ll h1, h2;

    HashString() {
        len = h1 = h2 = 0;
    }
    void push_back(char c) {
        h1 = (h1 * BASE1 + c) % MOD1;
        h2 = (h2 * BASE2 + c) % MOD2;
        len++;
    }

    void pop_back(char c) {
        h1 = (h1 - c + MOD1) % MOD1;
        h2 = (h2 - c + MOD2) % MOD2;

        h1 = (h1 * invB1) % MOD1;
        h2 = (h2 * invB2) % MOD2;
        len--;
    }

    void push_front(char c) {
        h1 = (h1 + c * pw1[len]) % MOD1;
        h2 = (h2 + c * pw2[len]) % MOD2;
        len++;
    }

    void pop_front(char c) {
        ll v1 = (c * pw1[len - 1]) % MOD1;
        ll v2 = (c * pw2[len - 1]) % MOD2;

        h1 = (h1 - v1 + MOD1) % MOD1;
        h2 = (h2 - v2 + MOD2) % MOD2;
        len--;
    }

    void merge(HashString other) {
        h1 = (h1 * pw1[other.len]) % MOD1;
        h2 = (h2 * pw2[other.len]) % MOD2;
        h1 = (h1 + other.h1) % MOD1;
        h2 = (h2 + other.h2) % MOD2;
        len += other.len;
    }

    pll getHash() {
        return {h1, h2};
    }

    bool operator==(HashString other) {
        return getHash() == other.getHash();
    }
};

string s;
struct SegTree {
#define LF (x*2+1)
#define RT (x*2+2)
#define md ((lx+rx) >> 1)
    vector<HashString> seg;
    int sz;

    SegTree(int n) {
        sz = n;
        seg.assign(4 * n, {});
    }

    HashString merge(HashString lf, HashString rt) {
        HashString ret = lf;
        ret.merge(rt);
        return ret;
    }


    void update(int i , char val , int x = 0 , int lx = 0 , int rx = -1){
        if(rx == -1) rx = sz - 1;

        if(lx == rx) {
            seg[x] = HashString();
            seg[x].push_back(val);
            return;
        }

        if(i <= md){
            update(i , val , LF , lx , md);
        }else{
            update(i , val , RT , md + 1 , rx);
        }
        seg[x] = merge(seg[LF] , seg[RT]);
    }

    HashString query(int l , int r , int x = 0 , int lx = 0 , int rx = -1){
        if(rx == -1) rx = sz - 1;
        if(rx < l or lx > r) return HashString();
        if(lx >= l and rx <= r) return seg[x];
        return merge(query(l , r , LF , lx , md) ,
                     query(l , r , RT , md +1 , rx));
    }

#undef md
#undef LF
#undef RT
};



void TC() {
    int n , q;
    cin >> n >> q >> s;
    SegTree seg(n) , segRev(n);
    for (int i = 0; i < n; ++i) {
        seg.update(i , s[i]);
        segRev.update(i , s[n - i - 1]);
    }
    int ty , k , l , r;
    char x;
    while(q--){
        cin >> ty;
        if(ty&1){
            cin >> k >> x;
            --k;
            seg.update(k, x);
            segRev.update(n - 1 - k, x);
        }else{
            cin >> l >> r;
            --l, --r;
            HashString h1 = seg.query(l, r);
            HashString h2 = segRev.query(n - 1 - r, n - 1 - l);
            h1 == h2 ? yes : no;
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
    initHash();
// ————————————————————————————————————————————
    ll tc = 1;
//     cin >> tc;
    while (tc--)
    {
        TC();
    }

    return 0;
}