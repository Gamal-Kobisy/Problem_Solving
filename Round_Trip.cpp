// LINK : https://cses.fi/problemset/task/1669
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
vector<bool> vis(N , false);
vector<ll>ans;
bool found = false;
vector<ll> last;
void dfs(ll v , ll parent )
{
    if(found)
    {
        return;
    }
    vis[v] = true;
    last.push_back(v);
    for(ll u : adj[v])
    {
        if(u == parent)
        {
            continue;
        }
        if(!found&&vis[u]){
            bool f=0;
            int g =0;
            for (ll i = 0; i < last.size(); ++i) {
                if(last[i]==u){
                    g =i;
                    f =1;
                    break;
                }
            }
            if(f) {
                found = 1;
                for(int i = g;i<last.size();i++)
                    ans.push_back(last[i]);
                last.clear();
                break;
            }
        }

        else if(!vis[u])
        {

            dfs(u , v );
            // last.pop_back();
        }
    }

}


void solve() {

    cin >> n >> m;
    for (ll i = 0; i < m; ++i) {
        ll a , b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (ll i = 1; i <= n; ++i) {

        if(!vis[i]&&!found)
            dfs(i , i );
        last.clear();
        if(found)break;
    }
    if(!found)
    {
        cout << "IMPOSSIBLE" << '\n';
    }
    else
    {
        cout << ans.size() + 1 << '\n';
        for(ll i : ans)
        {
            cout << i << ' ';
        }
        cout << ans[0] << '\n';
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