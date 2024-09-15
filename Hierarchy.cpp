// LINK : https://www.spoj.com/problems/MAKETREE/
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
const ll N = 1e5;
ll n , k;
vector<vector<int>>adj;
vector<bool>vis;
vector<int>ans;
void dfs(int v)
{
    vis[v] = true;
    for (int u: adj[v]) {
        if(!vis[u])
        {
            dfs(u);
        }
    }
    ans.push_back(v);
}
void solve() {
    cin >> n >> k;
    adj = vector<vector<int>>(n + 1);
    vis = vector<bool>(n + 1);
    for (ll i = 0; i < k; ++i) {
        int parent = i + 1;
        int s;
        cin >> s;
        for (ll j = 0; j < s; ++j) {
            int child;
            cin >> child;
            adj[parent].push_back(child);
        }
    }
    for (ll i = 1; i <= n ; ++i) {
        if(!vis[i])
        {
            dfs(i);
        }
    }
    reverse(all(ans));
    vector<int>Boss(n + 1);
    Boss[ans[0]] = 0;
    for (ll i = 1; i < n; ++i) {
        Boss[ans[i]] = ans[i - 1];
    }
    for (ll i = 1; i <= n; ++i) {
        cout << Boss[i] << nl;
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
    ll t = 1;
//    cin >> t;
    while(t--)
    {
        solve();
    }

    return 0;
}