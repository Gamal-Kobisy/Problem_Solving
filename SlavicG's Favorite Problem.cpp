// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/problemset/problem/1760/G
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
int n , a , b;
vector<pii>adj[N];
map<int , bool>found;
bool direct;
void dfs1(int v , int par , int Xor){
    if(v == b){
        if(Xor == 0) direct = true;
        return;
    };
    found[Xor] = true;
    for(auto [u , w] : adj[v]){
        if(u == par) continue;
        dfs1(u , v , Xor ^ w);
    }
}

bool dfs2(int v , int par , int Xor){
    if(v != b and found[Xor]) return true;
    bool ret = false;
    for(auto [u , w] : adj[v]){
        if(u == par) continue;
        ret |= dfs2(u , v , Xor ^ w);
    }
    return ret;
}
void TC() {
    cin >> n >> a >> b;
    for (int i = 0; i <= n; ++i) {
        adj[i].clear();
    }
    found.clear();
    direct = false;
    for (int i = 0; i < n - 1; ++i) {
        int v , u , w;
        cin >> v >> u >> w;
        adj[v].emplace_back(u , w);
        adj[u].emplace_back(v , w);
    }
    dfs1(a , -1 , 0);
    if(direct) yes;
    else if(dfs2(b , -1 , 0)) yes;
    else no;
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