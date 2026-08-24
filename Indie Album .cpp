// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/contest/1207/problem/G
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

struct AhoCorasick {
    int states = 0;
    int sigma;
    vector<int> fail;
    vector<vector<int> > trie;
    vector<int> patterns;

    AhoCorasick(int n, int m = 10) {
        sigma = m;
        fail = vector<int>(n + 10, -1);
        patterns = vector<int> (n + 10);
        trie = vector<vector<int> >(n + 10, vector<int>(m, -1));
    }

    AhoCorasick(vector<string> &p, int n, int m = 26) {
        /*
         * MAKE SURE THAT THE STRINGS IN P ARE UNIQUE
         * N is the summation of sizes of p
         * M is the number of used alphabet
        */
        sigma = m;
        fail = vector<int>(n + 10, -1);
        patterns = vector<int> (n + 10);
        trie = vector<vector<int> >(n + 10, vector<int>(m, -1));

        for (int i = 0; i < p.size(); i++)
            insert(p[i], i);
        build();
    }

    int insert(string &s, int idx) {
        int cur = 0;
        for (auto &it: s) {
            if (trie[cur][it - 'a'] == -1)
                trie[cur][it - 'a'] = ++states;
            cur = trie[cur][it - 'a'];
        }
        patterns[cur] = 1;
        return cur;
    }

    int nextState(int trieNode, int nxt) {
        int cur = trieNode;
        while (trie[cur][nxt] == -1)
            cur = fail[cur];
        return trie[cur][nxt];
    }

    void build() {
        queue<int> q;
        for (int i = 0; i < sigma; i++) {
            if (trie[0][i] != -1)
                fail[trie[0][i]] = 0, q.push(trie[0][i]);
            else
                trie[0][i] = 0;
        }

        while (q.size()) {
            int cur = q.front();
            q.pop();
            for (int i = 0; i < sigma; i++) {
                if (trie[cur][i] == -1)
                    continue;
                int f = nextState(fail[cur], i);
                fail[trie[cur][i]] = f;
                q.push(trie[cur][i]);
            }
        }
    }
};

struct Fenwick {
    int n;
    vector<ll> tree;
    Fenwick(int _n){
        n = _n;
        tree.assign(n + 1 , 0);
    }
    void update(int idx, int val) {
        while (idx <= n) {
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
    int n;
    cin >> n;
    vector<vector<pair<int, char>>> adj(n + 1);
    for (int i = 1; i <= n; i++)
    {
        int ty , idx;
        char c;
        cin >> ty;
        if (ty == 1)
        {
            cin >> c;
            adj[0].pb({i , c});
        }else
        {
            cin >> idx >> c;
            adj[idx].pb({i , c});
        }
    }
    AhoCorasick aho(4e5 , 26);
    int q;
    cin >> q;
    vector<vector<pii>>queries(n + 1);
    for (int i = 0 ; i < q ; i++)
    {
        int idx;
        string t;
        cin >> idx >> t;
        int tar = aho.insert(t, idx);
        queries[idx].pb({i , tar});
    }
    aho.build();
    vector<vector<int>>fail_tree(aho.states + 1);
    for (int i = 1 ; i <= aho.states; i++)
    {
        fail_tree[aho.fail[i]].pb(i);
    }
    vector<int>in(aho.states + 1) , out(aho.states + 1);
    int timer = 0;
    auto dfs = [&](auto& self, int u)-> void
    {
        in[u] = ++timer;
        for (int v : fail_tree[u])
        {
            self(self, v);
        }
        out[u] = timer;
    };
    dfs(dfs , 0);
    vector<int>ans(q);
    Fenwick bit(timer);
    auto dfs2 = [&](auto& self, int u , int state)-> void
    {
        for (auto [idx , target] : queries[u])
        {
            ans[idx] += bit.query_range(in[target] ,out[target]);
        }
        for (auto [v , c] : adj[u])
        {
            int nxt_state = aho.nextState(state, c - 'a');

            bit.update(in[nxt_state], 1);
            self(self, v, nxt_state);
            bit.update(in[nxt_state], -1);
        }
    };
    dfs2(dfs2 , 0 , 0);
    for (int i = 0; i < q; ++i)
    {
        cout << ans[i] << endl;
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
    ll tc = 1;
    while (tc--)
    {
        TC();
    }

    return 0;
}