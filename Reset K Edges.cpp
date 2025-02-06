// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/problemset/problem/1739/D
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
const int N = 2e5 + 5, M = 1e3, LOG = 20 , inf = 0x3f3f3f3f;
ll infLL = 0x3f3f3f3f3f3f3f3f;

int n , k;

vector<vector<int>>adj(N);
vector<int>OutDeg(N) , depth(N) , parent(N);

void dfs(int v , int d = 0)
{
    depth[v] = d;
    for(int u : adj[v])
    {
        dfs(u , d + 1);
    }
}

void solve() {
    cin >> n >> k;
    for (ll i = 0; i <= n; ++i) {
        adj[i].clear();
        depth[i] = OutDeg[i] = parent[i] = 0;
    }
    for (ll i = 2; i <= n; ++i) {
        int p;
        cin >> p;
        parent[i] = p;
        adj[p].emplace_back(i);
        OutDeg[p]++;
    }
    dfs(1);
    priority_queue<pair<int , int>>leafs;
    for (ll i = 1; i <= n; ++i) {
        if(OutDeg[i] == 0)
            leafs.push({depth[i] , i});
    }
    for (ll i = 0; i < k; ++i) {
        auto [d , node] = leafs.top();
        leafs.pop();
        depth[node] = 1;
        leafs.push({1 , node});
        OutDeg[parent[node]]--;
        if(!OutDeg[parent[node]])
            leafs.push({depth[parent[node]] , parent[node]});
        parent[node] = 1;
    }
    cout << leafs.top().first << nl;
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