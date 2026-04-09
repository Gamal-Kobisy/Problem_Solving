// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/group/Rilx5irOux/contest/638270/problem/H
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
struct MergeSortTree {
private:
#define md ((lx+rx)>>1)
#define LF (x*2+1)
#define RT (x*2+2)
    vector<vector<pll>> seg;
    int sz;

    void build(vector<ll> &arr, int x, int lx, int rx) {
        if (rx == lx) {
            seg[x] = {{arr[lx], arr[lx]}};
            return;
        }
        build(arr, LF, lx, md);
        build(arr, RT, md + 1, rx);
        seg[x].resize(seg[LF].size() + seg[RT].size());
        merge(all(seg[LF]), all(seg[RT]), seg[x].begin());
        for(int i = 1; i < seg[x].size(); i++) {
            seg[x][i].sc = seg[x][i-1].sc + seg[x][i].fr;
        }
    }

    ll query(int l, int r, int v, int x, int lx, int rx) {
        if (r < lx or rx < l)return 0;
        if (l <= lx and rx <= r) {
            auto it = upper_bound(all(seg[x]), make_pair((ll)v, infLL));
            if (it == seg[x].begin()) return 0;
            return prev(it)->sc;
        }
        return query(l, r, v, LF, lx, md) +
               query(l, r, v, RT, md + 1, rx);
    }

public:
    void build(vector<ll> &arr) {
        sz = arr.size();
        seg.assign(sz * 4, {});
        build(arr, 0, 0, sz - 1);
    }

    ll query(int l, int r, int v) {
        return query(l, r, v, 0, 0, sz - 1);
    }

#undef md
#undef LF
#undef RT
};

void TC() {
    int n;
    cin >> n;
    vector<ll>a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    MergeSortTree seg;
    seg.build(a);
    int q;
    cin >> q;
    while(q--){
        int l , r , k;
        cin >> l >> r >> k;
        ll ans = seg.query(--l , --r , k);
        cout << ans << nl;
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