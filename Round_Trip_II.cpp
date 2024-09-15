// LINK : https://cses.fi/problemset/result/10493164/
#include <bits/stdc++.h>
#define ll long long
#define nl '\n'
#define all(a) a.begin(),a.end()
#define allr(a) a.rbegin(),a.rend()
#define no cout<<"NO\n"
#define yes cout<<"YES\n"
#define ENG_GAMAL ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

/*
 ███████╗███╗   ██╗ ██████╗       ██████╗  █████╗ ███╗   ███╗ █████╗ ██╗
 ██╔════╝████╗  ██║██╔════╝      ██╔════╝ ██╔══██╗████╗ ████║██╔══██╗██║
 █████╗  ██╔██╗ ██║██║  ███╗     ██║  ███╗███████║██╔████╔██║███████║██║
 ██╔══╝  ██║╚██╗██║██║   ██║     ██║   ██║██╔══██║██║╚██╔╝██║██╔══██║██║
 ███████╗██║ ╚████║╚██████╔╝     ╚██████╔╝██║  ██║██║ ╚═╝ ██║██║  ██║███████╗
 ╚══════╝╚═╝  ╚═══╝ ╚═════╝       ╚═════╝ ╚═╝  ╚═╝╚═╝     ╚═╝╚═╝  ╚═╝╚══════╝
*/
// ————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
const ll N = 1e5 + 1 ;
ll n , m;
vector<ll> adj[N];
vector<bool> vis(N , false) , ancs(N , false);
vector<ll>ans;
bool found = false;
vector<ll> last;
void dfs(ll v )
{
    if(found)
    {
        return;
    }
    vis[v] = true;
    ancs[v] = true;
    last.push_back(v);
    for(ll u : adj[v])
    {
        if(ancs[u])
        {
            if(!found )
            {
                auto idx = find(all(last) , u) - last.begin();
                if(idx == last.size())
                {
                    continue;
                }
                for (ll i = idx; i < last.size(); ++i) {
                    ans.push_back(last[i]);
                }
                found = true;
            }
        }
        if(!vis[u])
        {
            dfs(u);
            last.pop_back();
        }
    }
    ancs[v] = false;
}

void solve() {
    cin >> n >> m;
    for (ll i = 0; i < m; ++i) {
        ll a , b;
        cin >> a >> b;
        adj[a].push_back(b);
    }
    for (ll i = 1; i <= n; ++i) {
        if(!found)
        {
            dfs(i);
            last.clear();
        }
        if(found)
        {
            break;
        }
    }
    if(!found)
    {
        cout << "IMPOSSIBLE" << nl;
    }
    else
    {
        cout << ans.size() + 1 << nl;
        for(ll i : ans)
        {
            cout << i << ' ';
        }
        cout << ans.front() << nl;
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
//    cin >> t;
    while(t--)
    {
        solve();
    }

    return 0;
}