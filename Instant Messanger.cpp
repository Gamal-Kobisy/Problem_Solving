// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/contest/398/problem/D
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
const int N = 5e4 + 5, M = 1e3, LOG = 20, inf = 0x3f3f3f3f;
ll infLL = 0x3f3f3f3f3f3f3f3f;
const int PROMOTE = 500;
const int DEMOTE = 300;
vector<int> adj[N], heavy_adj[N];
int n, m, q, o, deg[N], ans[N];
bool on[N], heavy[N];
inline void fast_erase(vector<int>& vec, int val) {
    for (int i = 0; i < (int)vec.size(); ++i) {
        if (vec[i] == val) {
            vec[i] = vec.back();
            vec.pop_back();
            return;
        }
    }
}

inline void On(int u){
    on[u] = true;
    for(int v : heavy_adj[u]){
        ans[v]++;
    }
}

inline void Off(int u){
    on[u] = false;
    for(int v : heavy_adj[u]){
        ans[v]--;
    }
}

inline void addEdge(int u , int v){
    deg[u]++;
    deg[v]++;
    adj[u].pb(v);
    adj[v].pb(u);
    if(heavy[u]){
        heavy_adj[v].pb(u);
        if(on[v]) ans[u]++;
    } else if(deg[u] == PROMOTE){
        heavy[u] = true;
        ans[u] = 0;
        for(int x : adj[u]){
            heavy_adj[x].pb(u);
            if(on[x]) ans[u]++;
        }
    }
    if(heavy[v]){
        heavy_adj[u].pb(v);
        if(on[u]) ans[v]++;
    } else if(deg[v] == PROMOTE){
        heavy[v] = true;
        ans[v] = 0;
        for(int x : adj[v]){
            heavy_adj[x].pb(v);
            if(on[x]) ans[v]++;
        }
    }
}

inline void delEdge(int u , int v){
    deg[u]--;
    deg[v]--;
    fast_erase(adj[u], v);
    fast_erase(adj[v], u);
    if(heavy[u]){
        fast_erase(heavy_adj[v], u);
        if(on[v]) ans[u]--;

        if(deg[u] == DEMOTE - 1){
            heavy[u] = false;
            for(int x : adj[u]){
                fast_erase(heavy_adj[x], u);
            }
        }
    }
    if(heavy[v]){
        fast_erase(heavy_adj[u], v);
        if(on[u]) ans[v]--;

        if(deg[v] == DEMOTE - 1){
            heavy[v] = false;
            for(int x : adj[v]){
                fast_erase(heavy_adj[x], v);
            }
        }
    }
}

inline int count_ans(int u){
    if(heavy[u]) return ans[u];
    int cnt = 0;
    for(int v : adj[u]){
        cnt += on[v];
    }
    return cnt;
}

void TC() {
    mem(deg , 0);
    mem(on , false);
    mem(heavy , false);
    mem(ans , 0);

    cin >> n >> m >> q >> o;
    vector<int>init(o);
    for (int i = 0; i < o; ++i) {
        cin >> init[i];
    }
    for (int i = 0, a, b; i < m; ++i) {
        cin >> a >> b;
        addEdge(a , b);
    }
    for(int a : init){
        On(a);
    }
    while(q--){
        char ty;
        int u , v;
        cin >> ty >> u;
        if(ty == 'O'){
            On(u);
        }
        if(ty == 'F'){
            Off(u);
        }
        if(ty == 'A'){
            cin >> v;
            addEdge(u , v);
        }
        if(ty == 'D'){
            cin >> v;
            delEdge(u , v);
        }
        if(ty == 'C'){
            cout << count_ans(u) << nl;
        }
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