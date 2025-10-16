// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://atcoder.jp/contests/abc277/tasks/abc277_e?lang=en
#include <bits/stdc++.h>
#define ll long long
#define nl '\n'
#define sp ' '
#define all(a) a.begin(),a.end()
#define allr(a) a.rbegin(),a.rend()
#define no cout<<"NO\n"
#define yes cout<<"YES\n"
#define imp cout<<"IMPOSSIBLE\n"
#define ENG_GAMAL ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;
// ————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
const int N = 2e5 + 5;
const ll infLL = 0x3f3f3f3f3f3f3f3f;

int n , m , k;
vector<pair<int , int>> adj[N];
vector<vector<ll>> dist(2, vector<ll>(N, infLL));
vector<bool> s(N);

void solve() {
    cin >> n >> m >> k;

    for (int i = 0 , a , b , w ; i < m ; i++) {
        cin >> a >> b >> w;
        adj[a].emplace_back(b, w);
        adj[b].emplace_back(a, w);
    }

    for (int i = 0 , a ; i < k ; i++) {
        cin >> a;
        s[a] = true;
    }

    deque<pair<int,int>> dq; // {node, parity}
    dist[0][1] = 0;
    dq.emplace_back(1, 0);

    while (!dq.empty()) {
        auto [cur, parity] = dq.front();
        dq.pop_front();
        ll d = dist[parity][cur];

        if (s[cur] && dist[parity ^ 1][cur] > d) {
            dist[parity ^ 1][cur] = d;
            dq.emplace_front(cur, parity ^ 1);
        }
        for (auto [u, w] : adj[cur]) {
            if ((w ^ parity) == 1 && dist[parity][u] > d + 1) {
                dist[parity][u] = d + 1;
                dq.emplace_back(u, parity);
            }
        }
    }

    ll ans = min(dist[0][n], dist[1][n]);
    if (ans == infLL)
        ans = -1;
    cout << ans << nl;
}

void file() {
#ifndef ONLINE_JUDGE
    freopen("Input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
    freopen("Error.txt", "w", stderr);
#endif
}

int main() {
    file();
    ENG_GAMAL
    ll t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}