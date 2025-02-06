// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/problemset/problem/1675/F
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

int n , k , x , y;
vector<vector<int>>adj(N);
vector<bool>Nastya(N) , house(N);
void dfs(int v , int parent = -1)
{
    for(int u : adj[v])
    {
        if(u == parent)
            continue;
        dfs(u , v);
        if(house[u])
            house[v] = true;
        if(Nastya[u])
            Nastya[v] = true;
    }
}




void solve() {
    cin >> n >> k >> x >> y;
    for (ll i = 1; i <= n; ++i) {
        adj[i].clear();
        Nastya[i] = false;
        house[i] = false;
    }

    for (ll i = 0; i < k; ++i) {
        int c;
        cin >> c;
        house[c] = true;
    }
    Nastya[y] = true;
    for (ll i = 0; i < n - 1; ++i) {
        int a , b;
        cin >> a >> b;
        adj[a].emplace_back(b);
        adj[b].emplace_back(a);
    }
    dfs(x);
    ll ans = 0;
    for (ll i = 1; i <= n; ++i) {
        if(i == x)
            continue;
        if(Nastya[i])
            ans++;
        else if(house[i])
            ans += 2;
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
     cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}