// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://vjudge.net/problem/CodeChef-NPLFLF
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

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

struct Node{
    unordered_map<char , int>adj;
    int sz = 0;
    int &operator[](char x){
        return adj[x];
    }
};

struct Trie {
    vector<Node>trie;
    unordered_map<int , multiset<int> , custom_hash>level;
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

    void update(string &s, int op) {
        int u = 0;
        for (int l = 0; l < s.size(); ++l) {
            char ch = s[l];
            if (!trie[u][ch]) {
                trie[u][ch] = newNode();
            }
            u = trie[u][ch];
            if(sz(u)) level[l + 1].erase(level[l + 1].find(sz(u)));
            trie[u].sz += op;
            level[l + 1].insert(sz(u));
        }
    }

    bool ask(int k , int l){
        if(level[l].empty()) return false;
        else return *level[l].rbegin() >= k;
    }

    ll query(string &s) {
        int u = 0;
        ll lcp_sum = 0;
        for (char ch : s) {
            if (!trie[u][ch]) break;
            u = trie[u][ch];
            lcp_sum += sz(u);
        }
        return lcp_sum;
    }
};

void TC() {
    int n;
    cin >> n;
    vector<string>a(n);
    Trie trie;
    int ty , k , l , x;
    string s;
    vector<bool> active(n);
    for (int i = 0; i < n; ++i) {
        cin >> ty;
        if(ty == 1){
            cin >> s;
            a[i] = s;
            active[i] = true;
            reverse(all(s));
            trie.update(s , 1);
        }else if(ty == 2){
            cin >> k >> l;
            trie.ask(k , l) ? yes : no;
        }else{
            cin >> x;
            --x;
            s = a[x];
            if(active[x]){
                active[x] = false;
                s = a[x];
                reverse(all(s));
                trie.update(s , -1);
            }
        }
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