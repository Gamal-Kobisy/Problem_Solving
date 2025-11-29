// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/problemset/problem/1472/E
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

void TC() {
    int n;
    cin >> n;
    vector<array<int  , 3>>a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i][0] >> a[i][1];
        if(a[i][0] > a[i][1]) swap(a[i][0] , a[i][1]);
        a[i][2] = i;
    }
    sort(all(a));
    auto merge = [](const array<int,3>& x, const array<int,3>& y) -> array<int,3> {
        if (x[2] == -1) return y;
        if (y[2] == -1) return x;
        if (x[1] != y[1]) return (x[1] < y[1] ? x : y);
        if (x[0] != y[0]) return (x[0] < y[0] ? x : y);
        return (x[2] < y[2] ? x : y);
    };

    array<int,3> neutral = {INT_MAX, INT_MAX, -1};

    SPT<array<int,3>, decltype(merge)> spt(a, merge, neutral, true);

    auto good = [&](int i , int j){
        return a[i][0] < a[j][0] and a[i][1] < a[j][1];
    };
    vector<int> ans(n, -1);
    for (int i = 0; i < n; ++i) {
        int pos = lower_bound(a.begin(), a.end(), a[i][0],
                              [](const array<int,3>& arr, int val){ return arr[0] < val; })
                  - a.begin();

        if (pos == 0) {
            ans[a[i][2]] = -1;
        } else {
            array<int,3> best = spt.query(0, pos - 1);
            if (best[2] == -1) {
                ans[a[i][2]] = -1;
            } else if (best[1] < a[i][1]) {
                ans[a[i][2]] = best[2] + 1;
            } else {
                ans[a[i][2]] = -1;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << ans[i] << sp;
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