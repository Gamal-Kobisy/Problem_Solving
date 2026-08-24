// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/group/Rilx5irOux/contest/479246/problem/D
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
    vector<int> pi;
    vector<vector<int> > trie, patterns, dp;

    AhoCorasick(int n, int m = 26) {
        pi = vector<int>(n + 10, -1);
        patterns = vector<vector<int> >(n + 10);
        trie = vector<vector<int> >(n + 10, vector<int>(m, -1));
    }

    AhoCorasick(vector<string> &p, int n, int m = 26) {
        /*
         * MAKE SURE THAT THE STRINGS IN P ARE UNIQUE
         * N is the summation of sizes of p
         * M is the number of used alphabet
        */

        pi = vector<int>(n + 10, -1);
        patterns = vector<vector<int> >(n + 10);
        trie = vector<vector<int> >(n + 10, vector<int>(m, -1));
        dp = vector<vector<int> >(n + 10, vector<int>(m, -1));

        for (int i = 0; i < p.size(); i++)
            insert(p[i], i);
        build();
    }

    void insert(string &s, int idx) {
        int cur = 0;
        for (auto &it: s) {
            if (trie[cur][it - 'a'] == -1)
                trie[cur][it - 'a'] = ++states;
            cur = trie[cur][it - 'a'];
        }
        patterns[cur].push_back(idx);
    }

    int nextState(int trieNode, int nxt) {
            int &ret = dp[trieNode][nxt];
            if (~ret)
                return ret;
            int cur = trieNode;
            if (trie[cur][nxt] == -1)
                return ret = nextState(pi[cur], nxt);

            return ret = trie[cur][nxt];
        }


    void build() {
        queue<int> q;
        for (int i = 0; i < 26; i++) {
            if (trie[0][i] != -1)
                pi[trie[0][i]] = 0, q.push(trie[0][i]);
            else
                trie[0][i] = 0;
        }

        while (q.size()) {
            int cur = q.front();
            q.pop();
            for (int i = 0; i < 26; i++) {
                if (trie[cur][i] == -1)
                    continue;
                int f = nextState(pi[cur], i);
                pi[trie[cur][i]] = f;
                patterns[trie[cur][i]].insert(patterns[trie[cur][i]].end(), patterns[f].begin(), patterns[f].end());
                q.push(trie[cur][i]);
            }
        }
    }


    vector<int> search(string &s, vector<string> &p, int n) {
        int cur = 0;

        vector<int> ret(n, -1);
        for (int i = 0; i < s.length(); i++) {
            cur = nextState(cur, s[i] - 'a');
            if (cur == 0 || patterns[cur].empty())
                continue;

            // patterns vector have every pattern that is matched in this node
            // matched: the last index in the pattern is index i
            for (auto &it: patterns[cur])
                if (!~ret[it]) ret[it] = i + 2 - p[it].size();
        }
        return ret;
    }
};

void TC() {
    int n;
    cin >> n;
    vector<string> pats(n);
    vector<string> unique_pats;
    map<string, int> freq;
    int sum_len = 0;
    for (int i = 0; i < n; ++i) {
        cin >> pats[i];
        if (freq[pats[i]] == 0) {
            unique_pats.push_back(pats[i]);
            sum_len += pats[i].size();
        }
        freq[pats[i]]++;
    }
    AhoCorasick aho(unique_pats, sum_len, 26);
    vector<ll> match_count(aho.states + 1, 0);
    for (int i = 1; i <= aho.states; ++i) {
        for (int idx : aho.patterns[i]) {
            match_count[i] += freq[unique_pats[idx]];
        }
    }

    ll ans = 0;
    ll mx = 0;
    for (string &s : pats) {
        int cur = 0;
        ll cand = 0;
        for (char c : s) {
            cur = aho.nextState(cur, c - 'a');
            cand += match_count[cur];
        }
        ans += cand;
        for (char c = 'a'; c <= 'z'; c++) {
            int nxt = aho.nextState(cur, c - 'a');
            mx = max(mx, match_count[nxt]);
        }
    }

    cout << ans + mx + 1 << endl;
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
