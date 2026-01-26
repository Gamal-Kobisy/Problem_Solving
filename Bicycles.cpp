// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/problemset/problem/1915/G
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
    int n , m;
    cin >> n >> m;
    vector<pii>adj[n + 1];
    ll dist[n + 1][1001];
    int slowness[n + 1];
    mem(dist , infLL);
    for (int i = 0; i < m; ++i) {
        int a , b , w;
        cin >> a >> b >> w;
        adj[a].pb({b , w});
        adj[b].pb({a , w});
    }
    for (int i = 1; i <= n; ++i) {
        cin >> slowness[i];
    }
    priority_queue<tuple<ll , int , int> , vector<tuple<ll , int , int>> , greater<>>pq;
    pq.push({0 , 1 , slowness[1]});
    dist[1][slowness[1]] = 0;
    while(not pq.empty()){
        auto [curDist , curNode , slow] = pq.top();
        pq.pop();
        if(curDist != dist[curNode][slow])
            continue;
        for (auto [v , w] : adj[curNode]) {
            int newSlow = min(slow , slowness[v]);
            ll newDist = curDist + 1LL * w * slow;

            if (newDist >= dist[v][newSlow])
                continue;

            dist[v][newSlow] = newDist;
            pq.push({newDist , v , newSlow});
        }
    }
    ll ans = infLL;
    for (int s = 1; s <= 1000; ++s)
        ans = min(ans , dist[n][s]);

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