// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/problemset/problem/963/D
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
};

void TC() {
    string t;
    int n;
    cin >> t >> n;
    vector<pair<string , int>>queries(n);
    map<string , int>idx;
    Aho aho;
    for (int i = 0; i < n; ++i) {
        cin >> queries[i].sc >> queries[i].fr;
        idx[queries[i].fr] = aho.insert(queries[i].fr , i);
    }
    aho.computeFail();
    auto match = aho.match(t , n);
    for(auto [s , f] : queries){
        auto v = match[idx[s]];
        if(v.size() < f){
            cout << -1 << nl;
            continue;
        }
        int mn = inf;
        if(f == 1){
            mn = s.size();
        }else{
            for (int i = 0; i <= v.size() - f; i++) {
                mn = min(mn, v[i + f - 1] - v[i] + (int)s.size());
            }
        }
        cout << mn << nl;
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