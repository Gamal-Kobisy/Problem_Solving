// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://cses.fi/problemset/task/2104
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

struct Node {
    unordered_map<char, int> ch;
    int fail{}, nxt{}, id = -1;
};

struct Aho {

    static const int ALPHA = 256;
    vector<Node> Trie;
    vector<int> order;

    int addNode() {
        Trie.emplace_back();
        return Trie.size() - 1;
    }

    void init() {
        Trie.clear();
        addNode();
    }

    Aho() { init(); }

    /// If the same string appears before, return its index
    int insert(const string &pat, int ID) {
        int u = 0;
        for (char c: pat) {
            int &nd = Trie[u].ch[c];
            if (!nd) nd = addNode();
            u = nd;
        }
        int &id = Trie[u].id;
        return ~id ? id : (id = ID);
    }

    int nxtF(int u, char c) {
        while (!Trie[u].ch.count(c))
            u = Trie[u].fail;
        u = Trie[u].ch[c];
        return u;
    }

    int Nxt(int u) {
        if (!u) return u;
        int &v = Trie[u].nxt;
        return ~Trie[v].id ? v : v = Nxt(v);
    }

    void computeFail() {
        queue<int> q;
        for (int i = 0; i < ALPHA; i++) {
            int &nd = Trie[0].ch[i];
            if (nd)
                q.push(nd);
        }
        while (q.size()) {
            int u = q.front();
            q.pop();
            order.push_back(u);
            int f = Trie[u].fail;
            for (auto [ch, v]: Trie[u].ch) {
                Trie[v].fail = Trie[v].nxt = nxtF(f, ch);
                q.push(v);
            }
        }
    }

    vector<vector<int>> match(string &s, int numPat) {
        vector<vector<int>> ret(numPat);
        int cur = 0, i = 0;
        for (char c: s) {
            cur = nxtF(cur, c);
            for (int p = cur; p; p = Nxt(p)) {
                int &x = Trie[p].id;
                if (~x) ret[x].push_back(i);
            }
            ++i;
        }
        return ret;
    }

    vector<int> firstmatch(string &s, int numPat) {
        vector<int> pos(Trie.size(), -1);
        int cur = 0, idx = 0;
        for (char c: s) {
            cur = nxtF(cur, c);
            if (pos[cur] == -1) pos[cur] = idx;
            idx++;
        }
        for (int i = order.size() - 1; i >= 0; --i) {
            int u = order[i];
            if (pos[u] == -1) continue;
            int f = Trie[u].fail;
            if (pos[f] == -1 || pos[u] < pos[f]) pos[f] = pos[u];
        }
        vector<int> found(numPat, -1);
        for (int u = 0; u < Trie.size(); ++u)
            if (~Trie[u].id) found[Trie[u].id] = pos[u];
        return found;
    }

};

void TC() {
    int n;
    string t;
    cin >> t >> n;
    vector<string> s(n);
    vector<int> rep(n);
    Aho aho;
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
        rep[i] = aho.insert(s[i], i);
    }
    aho.computeFail();
    auto pos = aho.firstmatch(t, n);
    for (int i = 0; i < n; ++i) {
        int e = pos[rep[i]];
        if (e == -1) cout << -1 << nl;
        else cout << (e - s[i].size() + 2) << nl;
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