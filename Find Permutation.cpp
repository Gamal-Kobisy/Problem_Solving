// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://atcoder.jp/contests/abc291/tasks/abc291_e?lang=en
#include <bits/stdc++.h>
#define ll long long
#define nl '\n'
#define sp ' '
#define all(a) a.begin(),a.end()
#define allr(a) a.rbegin(),a.rend()
#define no cout<<"No\n"
#define yes cout<<"Yes\n"
#define imp cout<<"IMPOSSIBLE\n"
#define ENG_GAMAL ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;
// ————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
const int N = 2e5 + 5, M = 1e3, LOG = 20, inf = 0x3f3f3f3f;
ll infLL = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<set<int>> adj(n+1);
    vector<int> indeg(n+1, 0);

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].insert(y);
    }
    for(int i = 1 ; i <= n ; i++)
    {
        for(auto u : adj[i])
            indeg[u]++;
    }
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (indeg[i] == 0) q.push(i);
    }

    vector<int> order;
    while (!q.empty()) {
        if (q.size() > 1) {
            no;
            return;
        }
        int cur = q.front(); q.pop();
        order.push_back(cur);
        for (int u : adj[cur]) {
            if (--indeg[u] == 0) q.push(u);
        }
    }

    if ((int)order.size() != n) {
        no;
        return;
    }

    yes;
    vector<int> ans(n+1);
    for (int i = 0; i < n; i++) {
        ans[order[i]] = i+1;
    }
    for (int i = 1; i <= n; i++) cout << ans[i] << sp;
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
    ll t = 1;
//     cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}