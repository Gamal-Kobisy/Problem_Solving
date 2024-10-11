// LINK : https://codeforces.com/contest/1406/problem/C
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
int n;
vector<vector<int>>adj;
vector<int>sub_tree_sz;
vector<pair<int , int>>centroid;
vector<bool>vis;

int get_sub_tree_size(int v , int par)
{
    int c = 0;
    for(int u : adj[v])
    {
        if(u != par)
        {
            c += get_sub_tree_size(u , v);
            c++;
        }
    }
    sub_tree_sz[v] = c + 1;
    return c;
}

void dfs(int v , int par)
{
    vector<int>temp;
    for(int u : adj[v])
    {
        int sz;
        if(u == par)
        {
            sz = n - sub_tree_sz[v];
        }
        else
        {
            sz = sub_tree_sz[u];
            dfs(u , v);
        }
        temp.emplace_back(sz);
    }
    ll maxi = *max_element(all(temp));
    centroid.emplace_back(maxi , v);
}

void solve() {
    cin >> n;

    adj = vector<vector<int>>(n + 1);
    sub_tree_sz = vector<int>(n + 1);
    vis = vector<bool>(n + 1);
    centroid.clear();
    for (ll i = 0; i < n - 1; ++i) {
        int a , b;
        cin >> a >> b;
        adj[a].emplace_back(b);
        adj[b].emplace_back(a);
    }
    get_sub_tree_size(1 , 0);
    dfs(1 , 0);
    sort(all(centroid));
    vector<pair<int , int>>s = centroid;
    ll cen = centroid.front().first;
    if(centroid[0].first != centroid[1].first)
    {
        cout << adj[cen].front() << ' ' << cen << nl;
        cout << adj[cen].front() << ' ' << cen << nl;
    }
    else
    {
        vector<bool>g(n + 1);
        for(ll u : adj[centroid[0].second])
        {
            g[u] = true;
        }
        g[centroid[0].second] = true;
        for(ll u : adj[centroid[1].second])
        {
            if(!g[u])
            {
                cout << centroid[1].second << ' ' << u << nl;
                cout << centroid[0].second << ' ' << u << nl;
                break;
            }
        }
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
    cin >> t;
    while(t--)
    {
        solve();
    }

    return 0;
}