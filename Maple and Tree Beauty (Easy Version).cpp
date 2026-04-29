// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/problemset/problem/2138/C1
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

void TC() {
    int n , k;
    cin >> n >> k;
    vector<int>adj[n + 1];
    for(int i = 2 ; i <= n; i++){
        int p;
        cin >> p;
        adj[p].pb(i);
        adj[i].pb(p);
    }
    vector<int>NodesInDepth(n);
    int minLeafDepth = n;
    int maxDepth = 0;
    function<void(int , int, int)> dfs = [&](int u , int par , int d){
        maxDepth = max(maxDepth , d);
        NodesInDepth[d]++;
        for(int v : adj[u]){
            if(v == par) continue;
            dfs(v , u , d + 1);
        }
        if(adj[u].size() == 1 and u != 1)
            minLeafDepth = min(minLeafDepth , d);
    };
    dfs(1 , -1 , 0);
    int sum = 0;
    for(int i = 0; i <= minLeafDepth; i++) sum += NodesInDepth[i];
    vector<vector<int>>memo(minLeafDepth + 1 , vector<int>(k + 1 , -1));
    function<int(int,int)> solve = [&](int depth , int remK){
        if (remK < 0) return 0;
        if (depth > minLeafDepth) {
            int used_zeros = k - remK;
            int used_ones = sum - used_zeros;
            return (used_ones <= n - k) ? 1 : 0;
        }

        int &res = memo[depth][remK];
        if(~res) return res;

        res = solve(depth + 1 , remK);
        if(NodesInDepth[depth] <= remK){
            res = res | solve(depth + 1, remK - NodesInDepth[depth]);
        }
        return res;
    };
    if (solve(0 , k)) {
        cout << minLeafDepth + 1 << nl;
    } else {
        cout << minLeafDepth << nl;
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
     cin >> tc;
    while (tc--)
    {
        TC();
    }

    return 0;
}