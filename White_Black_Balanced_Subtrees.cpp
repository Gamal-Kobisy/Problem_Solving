// LINK : https://codeforces.com/problemset/problem/1676/G
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
int n ;
string s;
vector<vector<int>>adj;
vector<bool>vis;
vector<pair<ll , ll>>BWcnt;

ll dfsB(ll v)
{
    vis[v] = true;
    ll cnt = 0;
    if(s[v - 1] == 'B'){cnt++;}
    for(ll u : adj[v])
    {
        if(!vis[u])
        cnt += dfsB(u);
    }
    BWcnt[v].first = cnt;
    return cnt;
}

ll dfsW(ll v)
{
    vis[v] = true;
    ll cnt = 0;
    if(s[v - 1] == 'W'){cnt++;}
    for(ll u : adj[v])
    {
        if(!vis[u])
            cnt += dfsW(u);
    }
    BWcnt[v].second = cnt;
    return cnt;
}

void solve() {
    cin >> n;
    adj   = vector<vector<int>>(n + 1);
    vis   = vector<bool>(n + 1 , false);
    BWcnt = vector<pair<ll,ll>>(n + 1 , {0 , 0});
    for (ll i = 2; i <= n; ++i) {
        ll a;
        cin >> a;
        adj[i].push_back(a);
        adj[a].push_back(i);
    }
    cin >> s;
    dfsB(1);
    vis   = vector<bool>(n + 1 , false);
    dfsW(1);
    ll ans = 0;
    for (ll i = 1; i <= n; ++i) {
        if(BWcnt[i].first == BWcnt[i].second)
        {
            ans++;
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
    while(t--)
    {
        solve();
    }

    return 0;
}