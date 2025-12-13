// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/problemset/problem/145/E
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

struct SegTree {
#define LF (x*2+1)
#define RT (x*2+2)
#define md ((lx+rx) >> 1)

    struct Node{
        ll LNDS , LNIS , f4 , f7;
        Node(){
            LNDS = LNIS = f4 = f7 = 0;
        }
        Node(char c){
            LNDS = LNIS = 1;
            f4 = f7 = 0;
            (c == '7') ? f7++ : f4++;
        }
    };

    vector<Node> seg;
    vector<int> lazy;
    string s;
    int sz;

    void build(int x, int lx, int rx) {
        if (lx == rx) {
            seg[x] = Node(s[lx]);
            return;
        }
        build(LF, lx, md);
        build(RT, md + 1, rx);
        seg[x] = merge(seg[LF] , seg[RT]);
    }

    SegTree(int n , string s) {
        sz = n;
        this->s = s;
        seg.assign(4 * n, Node('7'));
        lazy.assign(4 * n, 0);
        build(0 , 0 , n - 1);
    }

    Node merge(Node lf , Node rt){
        Node res;
        res.LNDS = max({
                               lf.LNDS + rt.f7,
                               lf.f4 + rt.LNDS,
                               lf.f4 + rt.f7
                       });
        res.LNIS = max({
                               lf.LNIS + rt.f4,
                               lf.f7 + rt.LNIS,
                               lf.f7 + rt.f4
                       });
        res.f4 = lf.f4 + rt.f4;
        res.f7 = lf.f7 + rt.f7;
        return res;
    }

    void propegate(int x, int lx, int rx) {
        if (lazy[x] % 2 == 0){
            lazy[x] = 0;
            return;
        }
        if (lx != rx) {
            lazy[LF] += lazy[x];
            lazy[RT] += lazy[x];
        }
        Node New;
        New.LNDS = seg[x].LNIS;
        New.LNIS = seg[x].LNDS;
        New.f4 = seg[x].f7;
        New.f7 = seg[x].f4;
        seg[x] = New;
        lazy[x] = 0;
    }

    void update(int l, int r, int val, int x = 0, int lx = 0, int rx = -1) {
        if (rx == -1) rx = sz - 1;
        propegate(x, lx, rx);
        if (r < lx or rx < l)return;
        if (l <= lx and rx <= r) {
            lazy[x] += val;
            propegate(x, lx, rx);
            return;
        }
        update(l, r, val, LF, lx, md);
        update(l, r, val, RT, md + 1, rx);
        seg[x] = merge(seg[LF] , seg[RT]);
    }


    Node query(int l, int r, int x = 0, int lx = 0, int rx = -1) {
        if (rx == -1)rx = sz - 1;
        propegate(x, lx, rx);
        if (r < lx or rx < l)
            return Node();
        if (l <= lx and rx <= r)
            return seg[x];
        return
                merge(query(l, r, LF, lx, md) , query(l, r, RT, md + 1, rx));
    }


#undef md
#undef LF
#undef RT
};

void TC() {
    int n , q;
    string s;
    cin >> n >> q >> s;
    SegTree seg(n , s);
    while(q--){
        string t;
        cin >> t;
        if(t == "count"){
            cout << seg.query(0 , n - 1).LNDS << nl;
        }else{
            int l , r;
            cin >> l >> r;
            seg.update(--l , --r , 1);
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