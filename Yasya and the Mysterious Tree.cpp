// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/problemset/problem/1980/G
//#pragma GCC optimize("O3")
//#pragma GCC optimize ("unroll-loops")
//#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
//#pragma GCC target("avx2")
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
    int rev;
    int newNode(){
        trie.emplace_back();
        return trie.size() - 1;
    }

    void init(){
        rev = 0;
        trie.clear();
        newNode();
    }

    Trie(){
        init();
    }

    int sz(int u){
        return trie[u].sz;
    }

    void update(int val, int op) {
        int u = 0;
        trie[u].sz += op;

        for (int i = LOG; i >= 0; --i) {
            int bit = (val >> i) & 1;
            if (!trie[u].adj[bit]) {
                trie[u].adj[bit] = newNode();
            }
            u = trie[u].adj[bit];
            trie[u].sz += op;
        }
    }


    int maxXor(int x) {
        int u = 0;
        int ret = 0;
        int target = rev ^ x;
        for (int i = LOG; i >= 0; --i) {
            int bit = (target >> i) & 1;
            int desired = !bit;
            if (trie[u].adj[desired] && trie[trie[u].adj[desired]].sz > 0) {
                ret |= (1 << i);
                u = trie[u].adj[desired];
            } else {
                u = trie[u].adj[!desired];
            }
        }
        return ret;
    }

};

vector<pii>adj[N];
vector<int>val(N) , depth(N);
Trie trieOdd , trieEven;
void dfs(int u , int par , int d , int curXor){
    val[u] = curXor;
    depth[u] = d;
    if(d & 1) trieOdd.update(curXor , 1);
    else trieEven.update(curXor , 1);
    for(auto [v , w] : adj[u]){
        if(v == par) continue;
        dfs(v , u , d + 1 , curXor ^ w);
    }
}

void TC() {
    int n ,q;
    cin >> n >> q;
    for (int i = 0; i <= n; ++i) {
        adj[i].clear();
        val[i] = 0;
        depth[i] = 0;
    }
    trieOdd.init();
    trieEven.init();
    for (int i = 0; i < n - 1; ++i) {
        int u , v , w;
        cin >> u >> v >> w;
        adj[u].pb({v , w});
        adj[v].pb({u , w});
    }
    dfs(1 , -1 , 0 , 0);
    while(q--){
        char ty;
        int y , u , x;
        cin >> ty;
        if(ty == '^'){
            cin >> y;
            trieOdd.rev ^= y;
        }else{
            cin >> u >> x;
            int ans = 0;
            if(depth[u] & 1){
                int currentVal = val[u] ^ trieOdd.rev;
                int target = currentVal ^ x;
                trieOdd.update(val[u], -1);
                if(trieOdd.trie[0].sz > 0) ans = max(ans, trieOdd.maxXor(target));
                if(trieEven.trie[0].sz > 0) ans = max(ans, trieEven.maxXor(target));
                cout << ans << sp;
                trieOdd.update(val[u], 1);
            }
            else{
                int currentVal = val[u];
                int target = currentVal ^ x;
                trieEven.update(val[u], -1);
                if(trieOdd.trie[0].sz > 0) ans = max(ans, trieOdd.maxXor(target));
                if(trieEven.trie[0].sz > 0) ans = max(ans, trieEven.maxXor(target));
                cout << ans << sp;
                trieEven.update(val[u], 1);
            }
        }
    }
    cout << nl;
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