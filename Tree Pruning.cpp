// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/problemset/problem/2018/C
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
const int N = 5e5 + 5, M = 1e3, LOG = 20, inf = 0x3f3f3f3f;
ll infLL = 0x3f3f3f3f3f3f3f3f;
int n;
vector<int>adj[N] , depth(N) , max_depth(N);
vector<bool>vis(N);

int dfs(int v , int d){
   vis[v] = true;
   depth[v] = d;
   int mx_d = d;
   for(int u : adj[v]){
       if(vis[u]) continue;
       mx_d = max(mx_d , dfs(u , d + 1));
   }
   max_depth[v] = mx_d;
   return mx_d;
}

void TC() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        adj[i].clear();
        vis[i] = false;
        depth[i] = max_depth[i] = 0;
    }
    for (int i = 0; i < n - 1; ++i) {
        int a , b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    dfs(1 , 1);
    vector<int> count(n + 2, 0);
    for (int i = 1; i <= n; ++i) {
        count[depth[i]]++;
        count[max_depth[i] + 1]--;
    }

    int keep = 0 , cur = 0;

    for (int d = 1; d <= n; ++d) {
        cur += count[d];
        keep = max(keep, cur);
    }

    cout << n - keep << nl;
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