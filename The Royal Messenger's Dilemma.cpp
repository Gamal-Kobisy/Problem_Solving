// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/group/W6lmL683tS/contest/592798/problem/H
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
vector<bool>secure(N);
map<pair<ll , ll> , ll>idx;
vector<ll>ans;
deque<ll>edges;
void dfs(int v , int par = 0 , int need_secure = 0)
{
    for(int u : adj[v])
    {
        if(u == par)
            continue;
        ll i = idx[{v, u}];
        if(secure[i])
        {
            dfs(u , v , need_secure + 1);
        }
        else if(need_secure == 0)
        {
            edges.emplace_back(i);
            ans.emplace_back(edges.front());
            edges.pop_front();
            dfs(u , v , 1);
            if(!edges.empty())
                edges.pop_back();
        }
        else
        {
            edges.emplace_back(i);
            dfs(u , v , need_secure - 1);
            if(!edges.empty())
                edges.pop_back();
        }
    }
}

void solve() {
    ll n;
    cin >> n;
    for (ll i = 1; i <= n - 1; ++i) {
        ll a , b , s;
        cin >> a >> b >> s;
        adj[a].emplace_back(b);
        adj[b].emplace_back(a);
        secure[i] = s;
        idx[{a , b}] = idx[{b , a}] = i;
    }
    dfs(1);
    cout << ans.size() << nl;
    for (ll i = 0; i < ans.size(); ++i) {
        cout << ans[i] << sp;
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
    // cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}