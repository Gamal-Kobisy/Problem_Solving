// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/problemset/problem/638/C
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

vector<vector<int>>adj(N) , ans(N);
map<pair<int , int> , int>idx;

void dfs(int v , int par = -1 , int last_used = 0)
{
    int d = 1;
    for(int u : adj[v])
    {
        if(u == par)
            continue;
        d += (d == last_used);
        ans[d].emplace_back(idx[{v , u}]);
        dfs(u , v , d);
        d++;
    }
}

void solve() {
    int n;
    cin >> n;
    for (ll i = 0; i < n - 1; ++i) {
        int a , b;
        cin >> a >> b;
        idx[{a, b}] = idx[{b , a}] = i + 1;
        adj[a].emplace_back(b);
        adj[b].emplace_back(a);
    }
    dfs(1);
    int days = 0;
    for (ll i = 1; i < N; ++i) {
        if(ans[i].empty())
        {
            days = i - 1;
            break;
        }
    }
    cout << days << nl;
    for (ll i = 1; i <= days; ++i) {
        cout << ans[i].size() << sp;
        for (ll j = 0; j < ans[i].size(); ++j) {
            cout << ans[i][j] << sp;
        }
        cout << nl;
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
    // cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}