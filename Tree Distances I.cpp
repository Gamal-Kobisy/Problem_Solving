// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://vjudge.net/contest/746355#problem/C
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
int n , ans;
vector<int>adj[N];
int depth[N][2];

int dfs(int v , int par , int d, int idx)
{
    depth[v][idx] = d;
    int max_depth_node = v;
    for(int u : adj[v])
    {
        if(u == par)
            continue;
        int cand = dfs(u , v , d + 1 , idx);
        if(depth[cand][idx] > depth[max_depth_node][idx])
            max_depth_node = cand;
    }
    return max_depth_node;
}

void solve() {
    ans = 0;
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int a , b;
        cin >> a >> b;
        adj[a].emplace_back(b);
        adj[b].emplace_back(a);
    }
    int a = dfs(1 , -1 , 0 , 0);
    int b = dfs(a , -1 , 0 , 0);
    dfs(b , -1 , 0 , 1);
    for (int i = 1; i <= n; ++i) {
        cout << max(depth[i][0] , depth[i][1]) << sp;
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
//     cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}