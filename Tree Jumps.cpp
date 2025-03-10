// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK :
#include <bits/stdc++.h>
#define ll long long
#define nl '\n'
#define sp ' '
#define all(a) a.begin(),a.end()
#define allr(a) a.rbegin(),a.rend()
#define no cout<<"NO\n"
#define yes cout<<"YES\n"
#define ENG_GAMAL ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;
// ————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
const int N = 3e5 + 5, M = 1e3, LOG = 20, inf = 0x3f3f3f3f;
ll infLL = 0x3f3f3f3f3f3f3f3f;

vector<vector<int>>adj(N) , nodes_in_depth(N);
vector<int>depth(N) , cnt(N);

void calc_depth(int v = 1)
{
    for(int u : adj[v])
    {
        depth[u] = depth[v] + 1;
        nodes_in_depth[depth[u]].emplace_back(u);
        calc_depth(u);
    }
}

void solve() {
    ll n;
    cin >> n;
    for (ll i = 0; i <= n; ++i) {
        adj[i].clear();
        nodes_in_depth[i].clear();
        depth[i] = cnt[i] = 0;
    }
    for (ll i = 1; i < n; ++i) {
        int p;
        cin >> p;
        adj[p].emplace_back(i + 1);
    }
    depth[1] = 0;
    nodes_in_depth[0].emplace_back(1);
    calc_depth();
    ll ans = nodes_in_depth[0].size() + nodes_in_depth[1].size();
    for (ll i = 1; !nodes_in_depth[i + 1].empty() ; ++i) {
        for(int v : nodes_in_depth[i])
        {
            if(nodes_in_depth[i + 1].size() - adj[v].size())
            ans *= nodes_in_depth[i + 1].size() - adj[v].size();
        }
    }
    cout << ans  << nl;
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
     cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}