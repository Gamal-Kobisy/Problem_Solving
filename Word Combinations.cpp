// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://cses.fi/problemset/task/1731
#pragma GCC optimize("O3")
#pragma GCC optimize ("unroll-loops")
#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
#pragma GCC target("avx2")
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

const ll MOD = 1e9 + 7;

ll add(ll a, ll b)
{
    return ((a % MOD) + (b % MOD)) % MOD;
}

ll sub(ll a, ll b)
{
    return ((a % MOD) - (b % MOD) + MOD) % MOD;
}

ll mul(ll a, ll b)
{
    return ((a % MOD) * (b % MOD)) % MOD;
}

struct Node{
    int adj[26]{};
    int sz = 0 , isEnd = 0;
    int &operator[](char x){
        return adj[x - 'a'];
    }
};

struct Trie {
    vector<Node>trie;
    ll memo[5001];
    int newNode(){
        trie.emplace_back();
        return trie.size() - 1;
    }

    void init(){
        trie.clear();
        mem(memo , -1);
        newNode();
    }

    int sz(int u){
        return trie[u].sz;
    }

    Trie(){
        init();
    }

    void update(string &s , int op) {
        int u = 0;
        for(char ch : s){
            if(!trie[u][ch]){
                trie[u][ch] = newNode();
            }
            u = trie[u][ch];
            trie[u].sz += op;
        }
        trie[u].isEnd += op;
    }
    ll solve(string &s , int idx) {
        if (idx == s.size()) return 1;
        if (~memo[idx]) return memo[idx];
        ll ans = 0;
        int u = 0;
        for (int i = idx; i < s.size(); i++) {
            int ch = s[i];
            if (!trie[u][ch]) break;
            u = trie[u][ch];
            if (trie[u].isEnd > 0) {
                ans = add(ans , solve(s , i + 1));
            }
        }
        return memo[idx] = ans;
    }
};

void TC() {
    string s , t;
    int n;
    cin >> s >> n;
    Trie trie;
    while(n--){
        cin >> t;
        trie.update(t , 1);
    }
    cout << trie.solve(s , 0) << nl;
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