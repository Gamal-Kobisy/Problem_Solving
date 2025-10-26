// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://atcoder.jp/contests/abc396/tasks/abc396_d?lang=en
#include <bits/stdc++.h>
#define ll long long
#define int ll
#define nl '\n'
#define sp ' '
#define all(a) a.begin(),a.end()
#define allr(a) a.rbegin(),a.rend()
#define no cout<<"NO\n"
#define yes cout<<"YES\n"
#define imp cout<<"IMPOSSIBLE\n"
#define ENG_GAMAL ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;
// ————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
const int N = 2e5 + 5, M = 1e3, LOG = 20, inf = 0x3f3f3f3f;
ll infLL = 0x3f3f3f3f3f3f3f3f;
int n , m;
vector<pair<int , int>>adj[15];
vector<bool>ancs(15);
int ans = infLL;
void dfs(int v , int curXor){
    if (v == n) {
        ans = min(ans , curXor);
        return;
    }
    ancs[v] = true;
    for(auto [u , w] : adj[v]){
        if(not ancs[u]){
            dfs(u , curXor ^ w);
        }
    }
    ancs[v] = false;
    return;
}

void solve() {
    cin >> n >> m;
    for(int i = 0 , a , b, w; i < m ; i++){
        cin >> a >> b >> w;
        adj[a].emplace_back(b , w);
        adj[b].emplace_back(a , w);
    }
    dfs(1 , 0);
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

signed main() {
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