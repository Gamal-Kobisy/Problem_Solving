// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://vjudge.net/contest/746355#problem/A
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
vector<int>adj[N] , sub_tree_size(N);

int dfs(int v , int par)
{
    int size = 1;
    for(int u : adj[v])
    {
        if(u == par)
            continue;
        size += dfs(u , v);
    }
    sub_tree_size[v] = size;
    return sub_tree_size[v];
}

void solve() {
    cin >> n;
    for (int i = 2; i <= n; ++i) {
        int u;
        cin >> u;
        adj[i].emplace_back(u);
        adj[u].emplace_back(i);
    }
    dfs(1 , -1);
    for (int i = 0; i < n; ++i) {
        cout << sub_tree_size[i + 1] - 1 << sp;
    }
    cout << nl;
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