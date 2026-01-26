// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/problemset/problem/2014/E
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

void TC() {
    int n , m , h;
    cin >> n >> m >> h;
    vector<pii>adj[n + 1];
    ll dist[n + 1][2][2];
    bool hasHorse[n + 1];
    mem(dist , infLL);
    mem(hasHorse , false);
    for (int i = 0; i < h; ++i) {
        int v;
        cin >> v;
        hasHorse[v] = true;
    }
    for (int i = 0; i < m; ++i) {
        int a , b , w;
        cin >> a >> b >> w;
        adj[a].pb({b , w});
        adj[b].pb({a , w});
    }
    priority_queue<tuple<ll , int , int  , int> , vector<tuple<ll , int , int  , int>> , greater<>>pq;
    pq.push({0 , 1 , 0 , 0});
    pq.push({0 , n , 0 , 1});
    dist[1][0][0] = dist[n][0][1] = 0;
    while(not pq.empty()){
        auto [curDist , curNode , findHorse , who] = pq.top();
        pq.pop();
        if(curDist != dist[curNode][findHorse][who])
            continue;
        for(auto [u , w] : adj[curNode]){
            if(hasHorse[curNode] or findHorse){
                if(curDist + w / 2 >= dist[u][1][who]) continue;
                dist[u][1][who] = curDist + w / 2;
                pq.push({dist[u][1][who] , u , 1 , who});
            }else{
                if(curDist + w >= dist[u][0][who]) continue;
                dist[u][0][who] = curDist + w;
                pq.push({dist[u][0][who] , u , 0 , who});
            }
        }
    }
    ll ans = infLL;
    for (int i = 1; i <= n; ++i) {
        ll cost1 = min(
                    dist[i][0][0] ,
                    dist[i][1][0]
                    );
        ll cost2 = min(
                    dist[i][0][1] ,
                    dist[i][1][1]
                    );
        if(cost1 == infLL or cost2 == infLL)
            continue;
        ans = min(ans , max(cost1 , cost2));
    }
    if(ans == infLL) ans = -1;
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
     cin >> tc;
    while (tc--)
    {
        TC();
    }

    return 0;
}