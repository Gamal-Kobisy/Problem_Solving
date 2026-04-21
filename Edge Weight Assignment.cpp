// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/contest/1338/problem/B
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
vector<int>adj[N];
int n;
bool odd_depth = false , even_depth = false;
void dfs(int u , int par = -1 , int depth = 0){
    for(int v : adj[u]){
        if(v == par) continue;
        dfs(v , u , depth + 1);
    }
    if(adj[u].size() == 1){
        (depth & 1) ? odd_depth = true : even_depth = true;
    }
}

void TC() {
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int a , b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    for (int i = 1; i <= n; ++i) {
        if(adj[i].size() == 1){
            dfs(i);
            break;
        }
    }
    int mn = (odd_depth and even_depth) ? 3 : 1;
    int mx = n - 1;
    for (int i = 1; i <= n; ++i) {
        int cnt = 0;
        for(int child : adj[i]){
            cnt += adj[child].size() == 1;
        }
        if(cnt){
            mx -= cnt - 1;
        }
    }
    cout << mn << sp << mx << nl;
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