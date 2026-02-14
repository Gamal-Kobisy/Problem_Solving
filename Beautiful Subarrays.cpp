// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/problemset/problem/665/E
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
const int N = 2e5 + 5, M = 1e3, LOG = 30, inf = 0x3f3f3f3f;
ll infLL = 0x3f3f3f3f3f3f3f3f;

struct Node{
    int adj[2] = {0 , 0};
    int sz = 0;
    int &operator[](int x){
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

    Trie(){
        init();
    }

    int sz(int u){
        return trie[u].sz;
    }

    void update(int x , int op , int bit = LOG, int u = 0){
        if(bit < 0) return;
        int ch = x >> bit & 1;
        if(!trie[u][ch]){
            trie[u][ch] = newNode();
        }
        u = trie[u][ch];
        trie[u].sz += op;
        update(x , op , bit - 1 , u);
    }

    ll calc(int val , int k , int bit = LOG , int u = 0){
        if(bit < 0) return sz(u);
        int z = trie[u][0];
        int o = trie[u][1];
        if(val & (1 << bit)) swap(o , z);
        if(k & (1 << bit)){
            if(o == 0) return 0;
            return calc(val , k , bit - 1 , o);
        }else{
            if(z == 0) return sz(o);
            else return sz(o) + calc(val , k , bit - 1 , z);
        }
    }

};

void TC() {
    int n , k;
    cin >> n >> k;
    vector<int>a(n);
    Trie trie;
    trie.update(0, 1);
    ll ans = 0;
    int curXor = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        curXor ^= a[i];
        ans += trie.calc(curXor, k);
        trie.update(curXor , 1);
    }
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