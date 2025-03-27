// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/group/W6lmL683tS/contest/592798/problem/F
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

vector<vector<ll>>adj(N);
vector<ll>inDeg(N);

ll dfs(int v , int par)
{
    ll ret = 0;
    if(inDeg[v] == 1)
        ret = 3;
    else
        ret = 2;
    for(int u : adj[v])
    {
        if(u == par)
            continue;
        ret += dfs(u , v);
    }
    return ret;
}

void solve() {
    ll n;
    cin >> n;
    for (ll i = 0; i <= n; ++i) {
        adj[i].clear();
        inDeg[i] = 0;
    }
    for (ll i = 0; i < n - 1; ++i) {
        ll a , b;
        cin >> a >> b;
        inDeg[a]++;
        inDeg[b]++;
        adj[a].emplace_back(b);
        adj[b].emplace_back(a);
    }
    ll ans = 0;
    for (ll i = 1; i <= n; ++i) {
        if(inDeg[i] == 1)
        {
            ans = dfs(i , 0);
            break;
        }
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