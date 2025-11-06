// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/group/Rilx5irOux/contest/627262/problem/O
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

struct Fenwick {
    int n;
    vector<ll> tree;
    Fenwick(int _n = 0){
        n = _n;
        tree.assign(n + 1 , 0);
    }
    // pos is 0-based (0..n-1)
    void update(int pos, int val) {
        int idx = pos + 1;
        while (idx <= n) {
            tree[idx] += val;
            idx += idx & -idx;
        }
    }
    // prefix sum up to pos (0-based). If pos < 0 returns 0.
    int query(int pos) {
        if (pos < 0) return 0;
        int idx = pos + 1;
        int ret = 0;
        while (idx > 0) {
            ret += tree[idx];
            idx -= idx & -idx;
        }
        return ret;
    }
    int query_range(int l , int r){
        if (l > r) return 0;
        return query(r) - query(l - 1);
    }
};

void TC() {
    int n , m , q;
    cin >> n >> m >> q;
    vector< set<int> > bits(n);
    vector<int> freq(m + 1);
    string s;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        for (int j = 0; j < m; ++j) {
            if (s[j] == '1') bits[i].insert(j);
        }
        int LSB;
        if (bits[i].empty()) LSB = m;
        else {
            int lastOne = *bits[i].rbegin();
            LSB = (m - 1) - lastOne;
        }
        freq[LSB]++;
    }
    Fenwick f(m + 1);
    for (int i = 0; i <= m; ++i) {
        if (freq[i]) f.update(i , freq[i]);
    }
    while(q--){
        int op;
        cin >> op;
        if(op == 1){
            int i , j;
            cin >> i >> j;
            int oldLSB = bits[i].empty() ? m : (m - 1) - *bits[i].rbegin();
            int curBit = (m - 1) - j;
            if(bits[i].find(curBit) != bits[i].end()){
                bits[i].erase(curBit);
            }else{
                bits[i].insert(curBit);
            }
            int newLSB = bits[i].empty() ? m : (m - 1) - *bits[i].rbegin();
            if(newLSB != oldLSB){
                f.update(oldLSB , -1);
                f.update(newLSB , +1);
            }
        }
        else{
            int x;
            cin >> x;
            cout << f.query_range(x, m) << nl;
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

signed main() {
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
