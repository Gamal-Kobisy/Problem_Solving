// LINK : https://codeforces.com/problemset/problem/1675/D
#include <bits/stdc++.h>
#define ll long long
#define nl '\n'
#define all(a) a.begin(),a.end()
#define allr(a) a.rbegin(),a.rend()
#define no cout<<"NO\n"
#define yes cout<<"YES\n"
#define ENG_GAMAL ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

/*
 ███████╗███╗   ██╗ ██████╗       ██████╗  █████╗ ███╗   ███╗ █████╗ ██╗
 ██╔════╝████╗  ██║██╔════╝      ██╔════╝ ██╔══██╗████╗ ████║██╔══██╗██║
 █████╗  ██╔██╗ ██║██║  ███╗     ██║  ███╗███████║██╔████╔██║███████║██║
 ██╔══╝  ██║╚██╗██║██║   ██║     ██║   ██║██╔══██║██║╚██╔╝██║██╔══██║██║
 ███████╗██║ ╚████║╚██████╔╝     ╚██████╔╝██║  ██║██║ ╚═╝ ██║██║  ██║███████╗
 ╚══════╝╚═╝  ╚═══╝ ╚═════╝       ╚═════╝ ╚═╝  ╚═╝╚═╝     ╚═╝╚═╝  ╚═╝╚══════╝
*/
// ————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
ll n;
vector<vector<ll>>adj , ans;
vector<bool>vis , leaf;
vector<ll>path;
void dfs(ll v)
{
    vis[v] = true;
    path.push_back(v);
    for(ll u : adj[v])
    {
        if(!vis[u])
        {
            dfs(u);
        }
    }
}

void solve() {
    cin >> n;
    adj = vector<vector<ll>>(n + 1);
    vis = vector<bool>(n + 1 , false);
    leaf = vector<bool>(n + 1 , true);
    for (ll i = 1; i <= n; ++i) {
        ll a;
        cin >> a;
        if(a == i)
        {
            continue;
        }
        leaf[a] = false;
        adj[i].push_back(a);
    }
    for (ll i = 1; i <= n; ++i) {
        if(!vis[i] && leaf[i])
        {
            dfs(i);
            reverse(all(path));
            ans.push_back(path);
            path.clear();
        }
    }
    cout << ans.size() << nl;
    for (ll i = 0; i < ans.size(); ++i) {
        cout << ans[i].size() << nl;
        for (ll j = 0; j < ans[i].size(); ++j) {
            cout << ans[i][j] << ' ';
        }
        cout << nl;
    }
    cout << nl;
    ans.clear();
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
    while(t--)
    {
        solve();
    }

    return 0;
}