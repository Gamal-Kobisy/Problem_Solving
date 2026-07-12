// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/problemset/problem/1847/D
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

struct Fenwick {
    int n;
    vector<ll> tree;
    Fenwick(int _n){
        n = _n;
        tree.assign(n + 1 , 0);
    }
    void update(int idx, int val) {
        while (idx < n) {
            tree[idx] += val;
            idx += idx & -idx;
        }
    }
    int query(int idx) {
        int ret = 0;
        while (idx > 0) {
            ret += tree[idx];
            idx -= idx & -idx;
        }
        return ret;
    }
    int query_range(int l , int r){
        return query(r) - query(l - 1);
    }
};

void TC() {
    int n, m, q;
    string s;
    cin >> n >> m >> q >> s;

    vector<int> jump(n, -1), pos(n, -1);
    vector<int> ord;

    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        --l, --r;
        int sz = r - l + 1;

        for (int j = l; j <= r; j++) {
            if (~jump[j]) {
                j += jump[j] - 1;
                continue;
            }
            jump[j] = sz - (j - l);
            pos[j] = ord.size();
            ord.push_back(j);
        }
    }

    Fenwick bit(ord.size() + 2);

    int totalOnes = 0;
    for (char c : s)
        totalOnes += (c == '1');

    for (int i = 0; i < (int)ord.size(); i++)
        if (s[ord[i]] == '1')
            bit.update(i + 1, 1);

    while (q--) {
        int idx;
        cin >> idx;
        idx--;

        if (s[idx] == '1') {
            totalOnes--;
            if (pos[idx] != -1)
                bit.update(pos[idx] + 1, -1);
            s[idx] = '0';
        } else {
            totalOnes++;
            if (pos[idx] != -1)
                bit.update(pos[idx] + 1, 1);
            s[idx] = '1';
        }

        int k = min(totalOnes, (int)ord.size());
        int onesInside = bit.query(k);

        cout << k - onesInside << nl;
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