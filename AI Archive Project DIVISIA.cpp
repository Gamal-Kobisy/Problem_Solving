// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/group/Rilx5irOux/contest/628229/problem/I
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
    vector<vector<int> > trie, patterns;

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
        int cur = trieNode;
        while (trie[cur][nxt] == -1)
            cur = pi[cur];
        return trie[cur][nxt];
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


    vector<vector<int> > search(string &s, vector<string> &p, int n) {
        int cur = 0;

        vector<vector<int> > ret(n);
        for (int i = 0; i < s.length(); i++) {
            cur = nextState(cur, s[i] - 'a');
            if (cur == 0 || patterns[cur].empty())
                continue;

            // patterns vector have every pattern that is matched in this node
            // matched: the last index in the pattern is index i
            for (auto &it: patterns[cur])
                ret[it].emplace_back(i + 1 - p[it].size()); // Replaced sz(p[it]) with p[it].size()
        }
        return ret;
    }
};

void TC() {
    int q;
    string s;
    cin >> s >> q;

    vector<string> queries(q);
    vector<string> patts;
    vector<int> rep(q);
    map<string, int> idx;

    int total_length = 0;

    for (int i = 0; i < q; i++) {
        cin >> queries[i];
        if (idx.find(queries[i]) == idx.end()) {
            idx[queries[i]] = patts.size();
            patts.push_back(queries[i]);
            total_length += queries[i].size();
        }
        rep[i] = idx[queries[i]];
    }

    AhoCorasick aho(patts, total_length);
    auto matches = aho.search(s, patts, patts.size());
    vector<int> ans(patts.size());
    for (int i = 0; i < patts.size(); i++) {
        int l = 0 , r = matches[i].size() - 1;
        int cnt = 0;
        while (l < r)
        {
            if (matches[i][r] >= matches[i][l] + patts[i].size())
            {
                cnt++;
                l++;
                r--;
            }else
            {
                break;
            }
        }
        ans[i] = cnt;
    }
    for (int i = 0; i < q; i++) {
        cout << ans[rep[i]] << nl;
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
    cin >> tc;
    while (tc--)
    {
        TC();
    }

    return 0;
}
