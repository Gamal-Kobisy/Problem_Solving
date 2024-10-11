// LINK : https://codeforces.com/contest/1139/problem/C
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
const ll MOD = 1e9 + 7;

ll add(ll a  , ll b)
{
    return ((a % MOD) + (b % MOD)) % MOD;
}

ll sub(ll a , ll b)
{
    return ((a % MOD) - (b % MOD) + MOD) % MOD;
}

ll mul(ll a , ll b)
{
    return ((a % MOD) * (b % MOD)) % MOD;
}

const ll N = 1e5 + 1;
ll n , k;
vector<vector<pair<ll , ll>>>adj(N);
vector<bool>vis(N);
vector<ll>seq;
ll pow(ll base, ll exponent) {
    ll result = 1;
    while (exponent > 0) {
        if (exponent % 2 == 1) { // If the exponent is odd
            result = mul(result , base);
        }
        base = mul(base , base); // Square the base
        exponent /= 2; // Divide the exponent by 2
    }
    return result % MOD;
}

ll dfs(ll v)
{
    vis[v] = true;
    ll cnt = 0;
    for(auto u : adj[v])
    {
        if(!vis[u.first] && !u.second)
        {
            cnt++;
            cnt += dfs(u.first);
        }
    }
    return cnt;
}

void solve() {
    cin >> n >> k;

    for (ll i = 0; i < n - 1; ++i) {
        ll a , b , w;
        cin >> a >> b >> w;
        adj[a].emplace_back(b , w);
        adj[b].emplace_back(a , w);
    }
    for (ll i = 1; i <= n; ++i) {
        if(!vis[i])
        {
            ll s = dfs(i);
            if(s)
            {
                seq.emplace_back(s + 1);
            }
        }
    }
    ll ans = pow(n , k) - n;
    for(ll i : seq)
    {
        ans = sub(ans , (pow(i , k) - i));
    }
    cout << ans % MOD << nl;
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