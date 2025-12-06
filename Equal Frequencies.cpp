// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/problemset/problem/1781/C
//#pragma GCC optimize("O3")
//#pragma GCC optimize ("unroll-loops")
//#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
//#pragma GCC target("avx2")
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

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
struct un_ordered
{
    bool operator()(const long long &a, const long long &b) const
    {
        return true;
    }
};
template <class T, class C = less_equal<T>>
using ordered_set = tree<T, null_type, C, rb_tree_tag, tree_order_statistics_node_update>;

void TC() {
        int n;
        string s;
        cin >> n >> s;

        vector<vector<int>> pos(26);
        for (int i = 0; i < n; ++i) pos[s[i]-'a'].pb(i);

        vector<int> order(26);
        iota(order.begin(), order.end(), 0);
        sort(order.begin(), order.end(), [&](int a, int b) {
            return pos[a].size() > pos[b].size();
        });

    int best = -1;
    int bestCnt = 1;
    for (int cnt = 1; cnt <= 26; ++cnt) {
        if (n % cnt != 0) continue;
        int per = n / cnt;

        int keep = 0;
        for (int i = 0; i < cnt; ++i)
            keep += min(per, (int)pos[order[i]].size());

        if (keep > best) {
            best = keep;
            bestCnt = cnt;
        }
    }

    string res = string(n , ' ');
    int per = n / bestCnt;
    vector<char> extra;
    for (int idx = 0; idx < bestCnt; ++idx) {
        int c = order[idx];
        for (int j = 0; j < per; ++j) {
            if (j < pos[c].size())
                res[pos[c][j]] = 'a' + c;
            else
                extra.push_back('a' + c);
        }
    }
    for (int i = 0; i < n; ++i) {
        if (res[i] == ' ') {
            res[i] = extra.back();
            extra.pop_back();
        }
    }

    cout << (n - best) << nl << res << nl;
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