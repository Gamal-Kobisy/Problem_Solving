// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/problemset/problem/2209/E
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

vector<int> z_function(string s) {
    int n = s.size();
    vector<int> z(n);
    int l = 0, r = 0;
    for(int i = 1; i < n; i++) {
        if(i < r) {
            z[i] = min(r - i, z[i - l]);
        }
        while(i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }
        if(i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
    }
    return z;
}

struct SEG {
    ll mx = -infLL;

    SEG() {}
    SEG(ll x){
        mx = x;
    }
};

struct LAZY {
    ll ass = -1;

    LAZY() {}
    LAZY(ll val){
        ass = val;
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
        if (lazy[x].ass == -1) return;

        seg[x].mx = max(lazy[x].ass , seg[x].mx);

        if (lx != rx) {
            lazy[LF].ass = max(lazy[LF].ass, lazy[x].ass);
            lazy[RT].ass = max(lazy[RT].ass, lazy[x].ass);
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
            lazy[x].ass = max(lazy[x].ass, val);
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

ll solve(string s){
    int n = s.size();
    vector<int> z = z_function(s);
    segTree seg(n);
    seg.update(0, n - 1, 1);
    function<int(int)> calc = [&](int idx){
        int ret = seg.query(idx, idx).mx;
        int nxt = idx + 1;
        if(nxt < n && z[nxt] > 0){
            seg.update(nxt, nxt + z[nxt] - 1, ret + 1);
        }
        return ret;
    };
    ll total_ans = 0;
    for(int i = 0; i < n; i++){
        total_ans += calc(i);
    }
    return total_ans;
}

void TC() {
    int n , q;
    string s;
    cin >> n >> q >> s;

    while(q--){
        int l , r;
        cin >> l >> r;
        cout << solve(s.substr(l - 1 , r - l + 1)) << nl;
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
     cin >> tc;
    while (tc--)
    {
        TC();
    }

    return 0;
}