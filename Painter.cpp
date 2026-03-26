// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/edu/course/2/lesson/5/4/practice/contest/280801/problem/C
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
const int N = 1e6 + 5, M = 5e5, LOG = 20, inf = 0x3f3f3f3f;
ll infLL = 0x3f3f3f3f3f3f3f3f;
struct SEG {
    int sum = 0;
    int cnt = 0;
    bool l_black = false;
    bool r_black = false;

    SEG() {}
};

struct LAZY {
    int type = 0;

    LAZY() {}
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
        ret.sum = lf.sum + rt.sum;

        ret.cnt = lf.cnt + rt.cnt;
        if (lf.r_black && rt.l_black) {
            ret.cnt--;
        }

        ret.l_black = lf.l_black;
        ret.r_black = rt.r_black;
        return ret;
    }

    void propagate(int x, int lx, int rx) {
        if (lazy[x].type == 0) return;

        if (lazy[x].type == 1) {
            seg[x].sum = (rx - lx + 1);
            seg[x].cnt = 1;
            seg[x].l_black = true;
            seg[x].r_black = true;
        } else if (lazy[x].type == 2) {
            seg[x].sum = 0;
            seg[x].cnt = 0;
            seg[x].l_black = false;
            seg[x].r_black = false;
        }

        if (lx != rx) {
            lazy[LF].type = lazy[x].type;
            lazy[RT].type = lazy[x].type;
        }

        lazy[x] = LAZY();
    }

    void update(int l, int r, int type, int x, int lx, int rx){
        propagate(x, lx, rx);

        if(rx < l || lx > r)
            return;

        if(l <= lx && rx <= r){
            lazy[x].type = type;
            propagate(x, lx, rx);
            return;
        }

        update(l , r , type , LF , lx , md);
        update(l , r , type , RT , md + 1 , rx);

        seg[x] = merge(seg[LF] , seg[RT]);
    }

    void update(int l , int r , int type){
        update(l , r , type , 0 , 0 , sz - 1);
    }

#undef LF
#undef RT
#undef md
};

void TC() {
    int n;
    cin >> n;

    segTree seg(N);
    while(n--){
        char c;
        int x, l;
        cin >> c >> x >> l;

        int type = (c == 'B') ? 1 : 2;

        seg.update(x + M, x + l - 1 + M, type);

        cout << seg.seg[0].cnt << sp << seg.seg[0].sum << nl;
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
    ll tc = 1;
    while (tc--) {
        TC();
    }
    return 0;
}