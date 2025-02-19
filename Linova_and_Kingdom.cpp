// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/problemset/problem/1337/C
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
ll ans = 0;
int n , k;

vector<vector<int>>adj(N);
vector<int>sub_tree(N) , depth(N);

void dfs(int v , int par = 0)
{
    depth[v] = depth[par] + 1;
    sub_tree[v] = 1;
    for(int u : adj[v])
    {
        if(u == par)
            continue;
        dfs(u , v);
        sub_tree[v] += sub_tree[u];
    }
}


void solve() {
    cin >> n >> k;
    for (ll i = 0; i < n - 1; ++i) {
        int a , b;
        cin >> a >> b;
        adj[a].emplace_back(b);
        adj[b].emplace_back(a);
    }
    depth[0] = 0;
    dfs(1);
    vector<int>calc(n);
    for (ll i = 0; i < n; ++i) {
        calc[i] = sub_tree[i + 1] - depth[i + 1];
    }
    sort(allr(calc));
    for (ll i = 0; i < n - k; ++i) {
        ans += calc[i];
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
    // cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}