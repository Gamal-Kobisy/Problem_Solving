// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/problemset/problem/1498/F
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
const int N = 1e5 + 5, M = 1e3, LOG = 20, inf = 0x3f3f3f3f;
ll infLL = 0x3f3f3f3f3f3f3f3f;
int n , k , k2;
vector<int>adj[N] , a(N);
vector<bool>ans(N);
int memo[N][41];

void dfs(int u , int par){
    memo[u][0] ^= a[u];
    for (int v : adj[u]) {
        if (v == par) continue;
        dfs(v, u);
        for (int d = 0; d < k2; d++) {
            memo[u][(d + 1) % k2] ^= memo[v][d];
        }
    }
}

void dfs2(int u , int par , vector<int>my_xors){
    vector<int>total(k2);
    for (int d = 0; d < k2; ++d) {
        total[d] = my_xors[d] ^ memo[u][d];
    }
    int XOR = 0;
    for (int i = k; i < k2; ++i) {
        XOR ^= total[i];
    }
    ans[u] = (XOR != 0);
    for(int v : adj[u]){
        if(v == par) continue;
        vector<int> temp = total;
        for (int d = 0; d < k2; d++) {
            temp[(d + 1) % k2] ^= memo[v][d];
        }
        vector<int> send(k2);
        for (int d = 0; d < k2; d++) {

            send[(d + 1) % k2] = temp[d];
        }
        dfs2(v , u , send);
    }
}

void TC() {
    cin >> n >> k;
    k2 = 2 * k;
    mem(memo , 0);
    for (int i = 0; i < n - 1; ++i){
        int u , v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    dfs(1 , -1);
    vector<int>temp(k2);
    dfs2(1 , -1 , temp);
    for (int i = 1; i <= n; ++i) {
        cout << ans[i] << sp;
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
    ll tc = 1;
//     cin >> tc;
    while (tc--)
    {
        TC();
    }

    return 0;
}