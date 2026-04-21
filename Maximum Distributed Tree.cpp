// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/contest/1401/problem/D
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
#define pb push_back
#define all(a) a.begin(),a.end()
#define allr(a) a.rbegin(),a.rend()
#define no cout<<"NO\n"
#define yes cout<<"YES\n"
#define imp cout<<"IMPOSSIBLE\n"
#define nl '\n'
#define sp ' '
#define ENG_GAMAL ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;
// ————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
const int N = 2e5 + 5, M = 1e3, LOG = 20, inf = 0x3f3f3f3f;
ll infLL = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9 + 7;

ll add(ll a, ll b)
{
    return ((a % MOD) + (b % MOD)) % MOD;
}

ll sub(ll a, ll b)
{
    return ((a % MOD) - (b % MOD) + MOD) % MOD;
}

ll mul(ll a, ll b)
{
    return ((a % MOD) * (b % MOD)) % MOD;
}
int n , m;
vector<int>adj[N];
vector<ll>w;
ll dfs(int u , int par){
    ll subtree = 1;
    for(int v : adj[u]){
        if(v == par) continue;
        ll child = dfs(v , u);
        w.pb((child) * (n - child));
        subtree += child;
    }
    return subtree;
}

void TC() {
    cin >> n;
    w.clear();
    for (int i = 0; i <= n; ++i) {
        adj[i].clear();
    }
    for (int i = 0; i < n - 1; ++i) {
        int a , b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    dfs(1 , -1);
    cin >> m;
    vector<int>primes;
    for (int i = 0; i < m; ++i) {
       int p;
       cin >> p;
       primes.pb(p);
    }
    sort(allr(w));
    sort(allr(primes));
    ll ans = 0;
    if (m <= n - 1) {
        for (int i = 0; i < n - 1; ++i) {
            ll weight = (i < m) ? primes[i] : 1;
            ans = add(ans, mul(w[i], weight));
        }
    } else {
        int extra = m - (n - 1);
        ll first_weight = 1;
        for (int i = 0; i <= extra; ++i) {
            first_weight = mul(first_weight, primes[i]);
        }
        ans = add(ans, mul(first_weight, w[0]));
        for (int i = 1; i < n - 1; ++i) {
            ans = add(ans, mul(primes[i + extra], w[i]));
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
    ll tc = 1;
     cin >> tc;
    while (tc--)
    {
        TC();
    }

    return 0;
}