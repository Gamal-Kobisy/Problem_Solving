// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/problemset/problem/271/D
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

vector<bool>bad(26);
string s , t;
int k;

struct Node{
    unordered_map<char , int>adj;
    int sz = 0 , isEnd = 0;
    int &operator[](char x){
        return adj[x];
    }
};

struct Trie {
    vector<Node>trie;

    int newNode(){
        trie.emplace_back();
        return trie.size() - 1;
    }

    void init(){
        trie.clear();
        newNode();
    }

    int sz(int u){
        return trie[u].sz;
    }

    Trie(){
        init();
    }

    void insert(string &s, int l) {
        int u = 0;
        int badCnt = 0;
        for (int i = l; i < s.size(); ++i) {
            char ch = s[i];
            badCnt += bad[ch - 'a'];
            if(badCnt > k)
                return;
            if (!trie[u][ch]) {
                trie[u][ch] = newNode();
            }
            u = trie[u][ch];
        }
    }

    int Count(){
        return trie.size() - 1;
    }

};


void TC() {
    cin >> s >> t >> k;
    for (int i = 0; i < 26; ++i) {
        if(t[i] == '0') bad[i] = true;
    }
    Trie trie;
    for (int l = 0; l < s.size(); ++l) {
        trie.insert(s , l);
    }
    ll ans = trie.Count();
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