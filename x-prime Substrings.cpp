// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/contest/1400/problem/F
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
    vector<int> pi;
    vector<vector<int> > trie;
    vector<int> patterns;

    AhoCorasick(int n, int m = 10) {
        sigma = m;
        pi = vector<int>(n + 10, -1);
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
        pi = vector<int>(n + 10, -1);
        patterns = vector<int> (n + 10);
        trie = vector<vector<int> >(n + 10, vector<int>(m, -1));

        for (int i = 0; i < p.size(); i++)
            insert(p[i], i);
        build();
    }

    void insert(string &s, int idx) {
        int cur = 0;
        for (auto &it: s) {
            if (trie[cur][it - '0'] == -1)
                trie[cur][it - '0'] = ++states;
            cur = trie[cur][it - '0'];
        }
        patterns[cur] = 1;
    }

    int nextState(int trieNode, int nxt) {
        int cur = trieNode;
        while (trie[cur][nxt] == -1)
            cur = pi[cur];
        return trie[cur][nxt];
    }

    void build() {
        queue<int> q;
        for (int i = 0; i < sigma; i++) {
            if (trie[0][i] != -1)
                pi[trie[0][i]] = 0, q.push(trie[0][i]);
            else
                trie[0][i] = 0;
        }

        while (q.size()) {
            int cur = q.front();
            q.pop();
            for (int i = 0; i < sigma; i++) {
                if (trie[cur][i] == -1)
                    continue;
                int f = nextState(pi[cur], i);
                pi[trie[cur][i]] = f;
                q.push(trie[cur][i]);
            }
        }
    }
};
void TC() {
    string s , x;
    cin >> s >> x;
    int val = stoi(x);
    ll totSz = 0;
    vector<string>pats;
    function<void(string , int)> gen = [&](string cur , int sum)
    {
        if (sum == val)
        {
            bool ok = true;
            for (int l = 0 ; l < cur.size() ; l++)
            {
                for (int r = l; r < cur.size(); ++r)
                {
                    int sub_sum = 0;
                    for (int i = l ; i <= r ; i++) sub_sum += cur[i] - '0';
                    if (sub_sum != val and val % sub_sum == 0) ok = false;
                }
            }
            if (ok) pats.pb(cur) , totSz += cur.size();
            return;
        }
        if (sum > val) return;
        for (char c  = '1' ; c <= '9' ; c++)
        {
            gen(cur + c , sum + c - '0');
        }
    };
    gen("" , 0);
    AhoCorasick aho(pats , totSz , 10);
    int m = aho.states + 1;
    vector<vector<int>>memo(s.size() + 1 , vector<int>(m , inf));
    memo[0][0] = 0;
    for (int i = 0; i < s.size(); i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (memo[i][j] == inf) continue;
            // del
            memo[i + 1][j] = min(
                memo[i + 1][j],
                memo[i][j] + 1
            );
            //
            int nxt = aho.nextState(j, s[i] - '0');
            if (!aho.patterns[nxt]) {
                memo[i + 1][nxt] =
                    min(
                        memo[i + 1][nxt],
                        memo[i][j]);
            }
        }
    }
    int ans = inf;
    for (int st = 0; st <= aho.states; st++)
        ans = min(ans, memo[s.size()][st]);

    cout << ans << nl;
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
