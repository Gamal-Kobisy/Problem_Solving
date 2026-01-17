// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/problemset/problem/1690/F
#pragma GCC optimize("O3")
#pragma GCC optimize ("unroll-loops")
#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
#pragma GCC target("avx2")
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
#define fi first
#define se second
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

ll gcd(ll a, ll b) {
    while (b != 0) {
        ll temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}

ll lcm_vector(const vector<ll>& vec) {
    ll result = vec[0];
    for (size_t i = 1; i < vec.size(); ++i) {
        result = lcm(result, vec[i]);
    }
    return result;
}

void TC() {
    int n;
    string s;
    cin >> n >> s;
    vector<int>a(n);
    vector<int>adj[n + 1];
    vector<int>vis(n + 1);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        adj[i + 1].pb(a[i]);
    }
    int nodes;
    string t;
    function<void(int)> dfs = [&](int v){
        vis[v] = true;
        nodes++;
        t += s[v - 1];
        for(int u : adj[v]){
            if(not vis[u]) dfs(u);
        }
    };
    vector<ll>v;
    for (int i = 1; i <= n; ++i) {
        if(not vis[i]){
            nodes = 0;
            t = "";
            dfs(i);
            int lo = 1 , hi = nodes , ans = nodes;
            for (int md = lo; md <= hi; ++md) {
                bool ok = true;
                for (int j = 0; j < t.size() and ok; ++j) {
                    ok &= t[j] == t[(j + md) % t.size()];
                }
                if(ok){
                    ans = md;
                    break;
                }
            }
//            while(lo <= hi){
//                int md = (lo + hi) / 2;
//                bool ok = true;
//                for (int j = 0; j < t.size() and ok; ++j) {
//                    ok &= t[j] == t[(j + md) % t.size()];
//                }
//                if(ok){
//                    ans = md;
//                    hi = md - 1;
//                }else{
//                    lo = md + 1;
//                }
//            }
            v.pb(ans);
        }
    }
    cout << lcm_vector(v) << nl;
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