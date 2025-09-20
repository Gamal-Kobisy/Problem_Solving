// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/problemset/problem/1676/G
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
int n , m , ans;
string colors;
vector<int>adj[N];
vector<bool>vis(N);

pair<int , int> dfs(int v, int par)
{
    vis[v] = true;
    pair<int , int> ret = {0 , 0};
    if(colors[v - 1] == 'B')
        ret.first++;
    else
        ret.second++;
    for(int u : adj[v])
    {
        if(u == par)
            continue;
        pair<int , int> sub_tree = dfs(u , v);
        ret.first += sub_tree.first;
        ret.second += sub_tree.second;
    }
    if(ret.first == ret.second)
        ans++;
    return ret;
}

void solve() {
    cin >> n;
    for(int i = 0 ; i <= n ; i++)
    {
        adj[i].clear();
        vis[i] = false;
    }
    ans = 0;
    for(int i = 2 ; i <= n; i++)
    {
        int parent;
        cin >> parent;
        adj[i].emplace_back(parent);
        adj[parent].emplace_back(i);
    }
    cin >> colors;
    dfs(1 , -1);
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