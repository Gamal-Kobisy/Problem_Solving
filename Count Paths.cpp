// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/problemset/problem/1923/E
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
const int N = 2e5 + 5, M = 1e3, LOG = 20, inf = 0x3f3f3f3f;
ll infLL = 0x3f3f3f3f3f3f3f3f;

int n;
vector<vector<int>>adj(N);
vector<int>color(N) , connected_with(N) , represent(N);
ll ans;

void dfs(int v , int par = -1)
{
    bool found = false;
    int old_represent = represent[color[v]];
    if(represent[color[v]])
    {
        found = true ;
        if(old_represent == par)
            ans++;
        else
            connected_with[old_represent]++;
    }
    represent[color[v]] = v;
    for(int u : adj[v])
    {
        if(u == par)
            continue;
        dfs(u , v);
    }
    if(found)
        represent[color[v]] = old_represent;
}

void solve() {
    ans = 0;
    cin >> n;
    for (ll i = 1; i <= n; ++i) {
        adj[i].clear();
        connected_with[i] = 0;
        represent[i] = 0;
        color[i] = 0;
    }

    for (ll i = 1; i <= n; ++i) {
        cin >> color[i];
    }
    for (ll i = 0; i < n - 1; ++i) {
        int a , b;
        cin >> a >> b;
        adj[a].emplace_back(b);
        adj[b].emplace_back(a);
    }
    dfs(1);
    for (ll i = 1; i <= n; ++i) {
        for (ll j = 1; j <= connected_with[i]; ++j) {
            ans += j;
        }
    }
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
    ll t = 1;
     cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}