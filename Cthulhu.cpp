// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/contest/104/problem/C
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
const int N = 100 + 5, M = 1e3, LOG = 20, inf = 0x3f3f3f3f;
ll infLL = 0x3f3f3f3f3f3f3f3f;
int n , m;
vector<int>adj[N];
vector<bool>vis(N) , ancs(N);
bool cycle , mcycle;

void dfs(int v , int par)
{
    vis[v] = true;
    ancs[v] = true;
    for(auto u : adj[v])
    {
        if(u == par)
            continue;
        if(ancs[u])
        {
            if(!cycle)
                cycle = true;
            else
                mcycle = true;
        }
        if(!vis[u])
            dfs(u , v);
    }
    ancs[v] = false;
}

void solve() {
    cycle = mcycle = false;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a , b;
        cin >> a >> b;
        adj[a].emplace_back(b);
        adj[b].emplace_back(a);
    }
    dfs(1 , -1);
    if(!cycle || mcycle)
        return void(no);
    for (int i = 1; i <= n; ++i) {
        if(!vis[i])
            return void(no);
    }
    cout << "FHTAGN!" << nl;
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