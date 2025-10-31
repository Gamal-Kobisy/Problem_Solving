// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/gym/101532/problem/F
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

int memo1[31][31] , memo2[31][31] , sz;
string cur;

int isPal(int l , int r){
    if(l > r) return true;
    int &ret = memo2[l][r];
    if(~ret) return ret;
    if(cur[l] == cur[r])
        ret = isPal(l + 1 , r - 1);
    else
        ret = false;
    return ret;
}

int calc(int l , int r){
    if(l > r) return 0;
    int &ret = memo1[l][r];
    if(~ret) return ret;
    ret = calc(l + 1 , r) + calc(l , r - 1) - calc(l + 1 , r - 1) + isPal(l , r);
    return ret;
}

int palNum(string s){
    cur = s;
    sz = s.size();
    memset(memo1 , -1 , sizeof memo1);
    memset(memo2 , -1 , sizeof memo2);
    int ret = calc(0 , sz - 1);
    return ret;
}

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
    int n , q;
    cin >> n >> q;
    vector<int>pals(n) , temp(n);
    vector<string>b(n);
    map<string , int>idx;
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        idx[b[i]] = i;
        pals[i] = palNum(b[i]);
    }
    iota(all(temp) , 0);
    auto merge = [&pals](int a, int b) -> int {
        if (pals[a] > pals[b]) return a;
        if (pals[a] < pals[b]) return b;
        return min(a, b);
    };
    SPT<int , decltype(merge)> spt(temp , merge , -infLL , true);
    while(q--){
        string l , r;
        cin >> l >> r;
        cout << spt.query(idx[l] , idx[r]) + 1 << nl;
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