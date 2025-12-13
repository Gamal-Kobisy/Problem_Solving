// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://www.spoj.com/problems/MULTQ3/cstart=30
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
        ll ans;
        array<int , 3>freq;
        Node(int num){
            freq.fill(0);
            freq[num % 3]++;
            ans = freq[0];
        }
    };

    vector<Node> seg;
    vector<int> lazy;
    int sz;

    void build(int x, int lx, int rx) {
        if (lx == rx) {
            seg[x].freq = {1, 0, 0};
            seg[x].ans = 1;
            return;
        }
        int m = (lx + rx) >> 1;
        build(LF, lx, m);
        build(RT, m + 1, rx);
        seg[x] = merge(seg[LF], seg[RT]);
    }


    SegTree(int n) {
        sz = n;
        seg.assign(4 * n, Node(0));
        lazy.assign(4 * n, 0);
        build(0, 0, sz - 1);
    }

    Node merge(Node lf , Node rt){
        Node res = Node(0);
        res.ans = lf.ans + rt.ans;
        for (int i = 0; i < 3; ++i) {
            res.freq[i] = lf.freq[i] + rt.freq[i];
        }
        return res;
    }

    void propegate(int x, int lx, int rx) {
        if (!lazy[x])
            return;
        if (lx != rx) {
            lazy[LF] += lazy[x];
            lazy[RT] += lazy[x];
        }
        lazy[x] %= 3;
        for (int i = 0; i < lazy[x]; ++i) {
            Node New(0);
            New.freq[0] = seg[x].freq[2];
            New.freq[1] = seg[x].freq[0];
            New.freq[2] = seg[x].freq[1];
            seg[x] = New;
        }
        seg[x].ans = seg[x].freq[0];
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
            return Node(1);
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
    int n ,q;
    cin >> n >> q;
    SegTree seg(n);
    while(q--){
        int t , l , r;
        cin >> t >> l >> r;
        if(t&1) cout << seg.query(l , r).ans << nl;
        else seg.update(l , r , 1);
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