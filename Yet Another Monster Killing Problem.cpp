// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/problemset/problem/1257/D
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
    int n , m;
    cin >> n;
    vector<int>a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    cin >> m;
    vector<pair<int , int>>b(m);
    for (int i = 0; i < m; ++i) {
        cin >> b[i].second >> b[i].first;
    }
    sort(all(b));
    vector<int>hunters_pow(m);
    for (int i = 0; i < m; ++i) {
        hunters_pow[i] = b[i].second;
    }

    auto merge = [](int a , int b){return max(a , b);};
    SPT<int , decltype(merge)>spt_monsters(a , merge , (int)-infLL , true);
    SPT<int , decltype(merge)>spt_hunters(hunters_pow , merge , (int)-infLL , true);

    int ans = 0;
    for (int i = 0; i < n ; ) {
        int cand = -1;
        int lo = 1 , hi = n - i;
        while(lo <= hi){
            int mid = (hi + lo) >> 1;
            int l = lower_bound(all(b) , make_pair(mid , (int)-infLL)) - b.begin();
            int max_hunt = -infLL;
            if (l < m) {
                max_hunt = spt_hunters.query(l , m - 1);
            } else {
                max_hunt = -infLL;
            }

            int max_mon = spt_monsters.query(i , i + mid - 1);
            if(max_hunt >= max_mon){
                cand = mid;
                lo = mid + 1;
            }else{
                hi = mid - 1;
            }
        }
        if(cand == -1) {
            cout << -1 << nl;
            return;
        }
        ans++;
        i += cand;
    }
    cout << ans << nl;
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
    ll t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}
