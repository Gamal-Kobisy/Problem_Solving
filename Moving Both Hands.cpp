// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/problemset/problem/1725/M
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
// adj[u] = <v , w , dir>
// dir == 0 then u -> v
// dir == 1 then v -> u
vector<tuple<int , int , bool>>adj[N];
ll dist[N][2];
void TC() {
    int n , m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u , v , w;
        cin >> u >> v >> w;
        adj[u].pb({v , w , 0});
        adj[v].pb({u , w , 1});
    }
    mem(dist , infLL);
    priority_queue<tuple<ll , int , bool> , vector<tuple<ll , int , bool>> , greater_equal<>>pq;
    pq.push({0 , 1 , 0});
    pq.push({0 , 1 , 1});
    dist[1][0] = dist[1][1] = 0;
    while(not pq.empty()){
        auto [curDist , curNode , dir] = pq.top();
        pq.pop();
        if(curDist != dist[curNode][dir]) continue;
        for(auto [u , w , d] : adj[curNode]){
            if(d == dir) {
                if(curDist + w < dist[u][dir]){
                    dist[u][dir] = curDist + w;
                    pq.push({dist[u][dir] , u , dir});
                }
            }else if(dir == 0){
                if(curDist + w < dist[u][1]){
                    dist[u][1] = curDist + w;
                    pq.push({dist[u][1] , u , 1});
                }
            }
        }
    }
    for (int i = 2; i <= n; ++i) {
        ll ans = min(dist[i][0] , dist[i][1]);
        if(ans == infLL) ans = -1;
        cout << ans << sp;
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