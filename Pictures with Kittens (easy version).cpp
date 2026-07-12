// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/problemset/problem/1077/F1
#include <bits/stdc++.h>
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
#define fr first
#define sc second
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

struct SEG {
    ll mx = -infLL;

    SEG() {}
    SEG(ll x){
        mx = x;
    }
};

struct LAZY {
    ll val = -infLL;

    LAZY() {}
    LAZY(ll val){
        this->val = val;
    }
};

struct segTree {

#define LF 2*x+1
#define RT 2*x+2
#define md (lx+rx)/2

    int n;
    int sz = 1;
    vector<SEG> seg;
    vector<LAZY> lazy;

    segTree(int n){
        this->n = n;

        while(sz < n)
            sz *= 2;

        seg.assign(2 * sz , SEG());
        lazy.assign(2 * sz , LAZY());
    }

    SEG merge(SEG lf , SEG rt){
        SEG ret;
        ret.mx = max(lf.mx , rt.mx);
        return ret;
    }

    void propagate(int x, int lx, int rx) {
        if (lazy[x].val == -infLL) return;

        seg[x].mx = max(seg[x].mx , lazy[x].val);

        if (lx != rx) {
            lazy[LF].val = max(lazy[LF].val , lazy[x].val);
            lazy[RT].val = max(lazy[RT].val , lazy[x].val);
        }
        lazy[x] = LAZY();
    }

    void build(vector<int> &v , int x , int lx , int rx){

        if(lx == rx){
            if(lx < n)
                seg[x] = SEG(v[lx]);
            return;
        }

        build(v , LF , lx , md);
        build(v , RT , md + 1 , rx);

        seg[x] = merge(seg[LF] , seg[RT]);
    }

    void build(vector<int> &v){
        build(v , 0 , 0 , sz - 1);
    }

    void update(int l, int r, ll val, int x, int lx, int rx){
        propagate(x, lx, rx);

        if(rx < l || lx > r)
            return;

        if(l <= lx && rx <= r){
            lazy[x].val = max(lazy[x].val , val);

            propagate(x, lx, rx);
            return;
        }
        update(l , r , val , LF , lx , md);
        update(l , r , val , RT , md + 1 , rx);

        seg[x] = merge(seg[LF] , seg[RT]);
    }

    void update(int l , int r , ll val){
        update(l , r , val , 0 , 0 , sz - 1);
    }

    SEG query(int l , int r , int x , int lx , int rx){
        propagate(x, lx, rx);

        if(rx < l || lx > r)
            return SEG();

        if(l <= lx && rx <= r)
            return seg[x];

        return merge(
                query(l , r , LF , lx , md),
                query(l , r , RT , md + 1 , rx)
        );
    }

    SEG query(int l , int r){
        return query(l , r , 0 , 0 , sz - 1);
    }

#undef LF
#undef RT
#undef md
};

void TC() {
    int n, k, x;
    cin >> n >> k >> x;
    ll a[n + 1];
    for (int i = 0; i < n; ++i) {
        cin >> a[i + 1];
    }
    a[0] = 0;
    vector<vector<ll>>memo(x + 1 , vector<ll>(n + 1 , -infLL));
    for(int idx = 0 ; idx <= min(n , k) ; idx++){
        memo[1][idx] = a[idx];
    }
    for (int picked = 2; picked <= x; ++picked) {
        deque<int> dq;
        for (int idx = 1; idx <= n; ++idx) {
            int newIdx = idx - 1;
            if (memo[picked-1][newIdx] != -infLL) {
                while (!dq.empty() && memo[picked-1][dq.back()] <= memo[picked-1][newIdx])
                    dq.pop_back();
                dq.push_back(newIdx);
            }
            while (!dq.empty() and dq.front() < idx - k)
                dq.pop_front();
            if (!dq.empty())
                memo[picked][idx] = memo[picked-1][dq.front()] + a[idx];
        }
    }

    ll ans = -infLL;
    for (int i = n - k + 1; i <= n; ++i)
        ans = max(ans, memo[x][i]);

    cout << (ans == -infLL ? -1LL : ans) << nl;


//    vector<segTree> memo(x + 1, segTree(n + 1));
//    memo[0].update(0, 0, 0);
//    for (int picked = 0; picked < x; ++picked) {
//        for (int idx = 1; idx <= n; ++idx) {
//        int lo = max(0, idx - k), hi = idx - 1;
//            ll prev = memo[picked].query(lo, hi).mx;
//            if (prev == -infLL) continue;
//            memo[picked + 1].update(idx, idx, prev + a[idx]);
//        }
//    }
//
//    ll ans = memo[x].query(n - k + 1, n).mx;
//    cout << (ans == -infLL ? -1 : ans) << nl;
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