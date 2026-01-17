// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/problemset/problem/1805/D
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
const int N = 1e5 + 5, M = 1e3, LOG = 20, inf = 0x3f3f3f3f;
ll infLL = 0x3f3f3f3f3f3f3f3f;
vector<int>adj[N] , dist(N) , max_reach(N);
vector<char>vis(N);
int n , MaxDistNode = 1 , MaxDist = 0;

void dfs(int v , int d){
    vis[v] = true;
    dist[v] = d;
    max_reach[v] = max(max_reach[v], d);
    if(d > MaxDist){
        MaxDist = d;
        MaxDistNode = v;
    }
    for(int u : adj[v]){
        if(not vis[u]) dfs(u , d + 1);
    }
}

void TC() {
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].emplace_back(b);
        adj[b].emplace_back(a);
    }
    dfs(1, 0);
    MaxDist = -1;
    fill(all(vis), false);
    dfs(MaxDistNode, 0);
    MaxDist = -1;
    fill(all(vis), false);
    dfs(MaxDistNode, 0);

    vector<int> pre(n + 5, 0);
    for (int i = 1; i <= n; ++i) {
        pre[max_reach[i]]++;
    }
    for (int i = 1; i <= n; ++i) {
        pre[i] += pre[i - 1];
    }

    for (int k = 1; k <= n; ++k) {
        int isolated = pre[k - 1];

        if (isolated == n) {
            cout << n << sp;
        } else {
            cout << isolated + 1 << sp;
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