// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://atcoder.jp/contests/abc284/tasks/abc284_e?lang=en
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
vector<int>adj[N];
vector<bool>ancs(N);
bool stop = false;
int dfs(int v){
    if(stop)
        return 0;
    ancs[v] = true;
    int ret = 1;
    for(int u : adj[v]){
        if(!ancs[u]){
            ret += dfs(u);
            if(ret >= 1e6){
                ret = 1e6;
                stop = true;
                break;
            }
        }
    }
    ancs[v] = false;
    return ret;
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a , b;
        cin >> a >> b;
        adj[a].emplace_back(b);
        adj[b].emplace_back(a);
    }
    cout << dfs(1) << nl;

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