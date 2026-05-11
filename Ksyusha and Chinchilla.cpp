// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/problemset/problem/1833/G
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define PI acos(-1)
#define Ones(n) __builtin_popcountll(n)
#define MSB(n) (63 - __builtin_clzll(n))
#define LSB(n) (__builtin_ctzll(n))
#define mem(arrr, xx) memset(arrr,xx,sizeof arrr)
#define fr first
#define sc second
#define all(a) a.begin(),a.end()
#define allr(a) a.rbegin(),a.rend()
#define no cout<<"NO\n"
#define yes cout<<"YES\n"
//#define imp cout<<"IMPOSSIBLE\n"
#define nl '\n'
#define sp ' '
#define ENG_GAMAL ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;
// ————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
const int N = 2e5 + 5, M = 1e3, LOG = 20, inf = 0x3f3f3f3f;
ll infLL = 0x3f3f3f3f3f3f3f3f;
vector<int>adj[N], deg(N);
vector<pii>ans;
bool imp = false;
int dfs(int u, int par){
    int tree = 1;
    for(int v : adj[u]){
        if(v == par) continue;
        int sub = dfs(v , u);
        if(sub == 3) ans.emplace_back(u , v);
        else tree += sub;
    }
    if(tree > 3) imp = true;
    return tree;
}

void TC() {
    int n;
    cin >> n;
    imp = false;
    for (int i = 0; i < n; ++i) {
        adj[i + 1].clear();
        deg[i + 1] = 0;
    }
    map<pii , int>id;
    int mx = -inf;
    for (int i = 0; i < n - 1; ++i) {
        int u , v;
        cin >> u >> v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
        id[{u , v}] = id[{v , u}] = i + 1;
        deg[u]++, deg[v]++;
        mx = max({mx, deg[u], deg[v]});
    }
    if(n % 3) return void(cout << -1 << nl);
    for(int i = 1 ; i <= n; i++){
        if(deg[i] == 1){
            dfs(i , -1);
            break;
        }
    }
    if(imp){
        cout << -1 << nl;
    }else{
        cout << ans.size() << nl;
        for(auto [u , v] : ans) cout << id[{u , v}] << sp;
        cout << nl;
    }
    ans.clear();
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
    ll tc = 1;
    cin >> tc;
    while (tc--)
    {
        TC();
    }

    return 0;
}