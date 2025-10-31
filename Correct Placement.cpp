// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/problemset/problem/1472/E
#include <bits/stdc++.h>
#define ll long long
#define int ll
#define nl '\n'
#define sp ' '
#define all(a) a.begin(),a.end()
#define allr(a) a.rbegin(),a.rend()
#define no cout<<"NO\n"
#define yes cout<<"YES\n"
#define imp cout<<"IMPOSSIBLE\n"
#define ENG_GAMAL ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;
// ————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
const int N = 2e5 + 5, M = 1e3, LOG = 20, inf = 0x3f3f3f3f;
ll infLL = 0x3f3f3f3f3f3f3f3f;

template<typename T, typename Merge>
struct SPT {
    vector<vector<T>> st;   // st[i][k] = value for segment starting at i with length 2^k
    vector<int> lg;        // lg[x] = floor(log2(x))
    Merge merge;
    T neutral;
    int n, K;
    bool canOverlap;
    SPT(const vector<T>& a, Merge m, T neutral_, bool canOverlap_ = true)
            : merge(m), neutral(neutral_), canOverlap(canOverlap_)
    {
        n = (int)a.size();
        if (n == 0) { K = 0; return; }
        K = 32 - __builtin_clz(n) - 1; // floor(log2(n))
        st.assign(n, vector<T>(K + 1));
        // base
        for (int i = 0; i < n; ++i) st[i][0] = a[i];

        // build
        for (int pw = 1; pw <= K; ++pw) {
            int len = 1 << pw;
            int half = 1 << (pw - 1);
            for (int i = 0; i + len <= n; ++i) {
                st[i][pw] = merge(st[i][pw - 1], st[i + half][pw - 1]);
            }
        }

        // precompute logs for O(1) queries
        lg.assign(n + 1, 0);
        for (int i = 2; i <= n; ++i) lg[i] = lg[i >> 1] + 1;
    }

    // Query [l, r] inclusive, 0-based indices
    T query(int l, int r) const {
        if (l > r) swap(l, r);
        if (l < 0) l = 0;
        if (r >= n) r = n - 1;
        int len = r - l + 1;
        if (len <= 0) return neutral;

        if (canOverlap) {
            int k = lg[len];
            // merge two overlapping blocks
            return merge(st[l][k], st[r - (1 << k) + 1][k]);
        } else {
            // general associative merge: combine blocks by binary decomposition
            T res = neutral;
            int idx = 0;
            int pos = l;
            while (len) {
                if (len & 1) {
                    res = merge(res, st[pos][idx]);
                    pos += (1 << idx);
                }
                len >>= 1;
                ++idx;
            }
            return res;
        }
    }
};

void solve() {
    int n;
    cin >> n;
    vector<pair<int , int>>v(n);
    vector<pair<pair<int , int> , int>>normal(n) , reversed(n);
    for (int i = 0; i < n; ++i) {
        int a , b;
        cin >> a >> b;
        v[i] = {a , b};
        normal[i] = {{a, b} , i};
        reversed[i] = {{b, a} , i};
    }
    sort(all(normal));
    sort(all(reversed));
    for (int i = 0; i < n; ++i) {
        pair<int , int> p = v[i];
        auto mini_normal = upper_bound(all(normal) , make_pair(p , i));
        auto mini_reversed= upper_bound(all(reversed) , make_pair(p , i));
        int norm_idx = mini_normal - normal.begin() + 1;
        int rev_idx = mini_reversed - reversed.begin() + 1;
        if(norm_idx <= n)
            cout << mini_normal->second + 1 << sp;
        else if(rev_idx <= n)
            cout << mini_reversed->second + 1 << sp;
        else
            cout << -1 << sp;
    }
    cout << nl;

}
void file()
{
#ifndef ONLINE_JUDGE
    freopen("Input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
    freopen("Error.txt", "w", stderr);
#endif
}

signed main() {
    file();
    ENG_GAMAL
// test-independent code ——————————————————————
// ————————————————————————————————————————————
    ll t = 1;
     cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}