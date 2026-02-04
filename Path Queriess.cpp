// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/problemset/problem/1213/G
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

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
struct un_ordered
{
    bool operator()(const long long &a, const long long &b) const
    {
        return true;
    }
};
template <class T, class C = greater_equal<T>>
using ordered_set = tree<T, null_type, C, rb_tree_tag, tree_order_statistics_node_update>;
ll sum(ll n){
    return (n) * (n - 1) / 2;
}
struct DSU{
    vector<int>par , sz;
    multiset<int>comps;
    ll pairs = 0;
    DSU(int n) : par(n) , sz(n , 1) {
        for (int i = 0; i < n; ++i) {
            comps.insert(1);
        }
        iota(all(par) , 0);
    }

    int find(int x){
        if(x == par[x]) return x;
        else return par[x] = find(par[x]);
    }

    bool same(int x , int y){
        return find(x) == find(y);
    }

    bool merge(int x , int y){
        x = find(x);
        y = find(y);
        if(same(x , y)) return false;
        if(sz[x] > sz[y]) swap(x , y);
        if(sz[x] > 1) pairs -= sum(sz[x]);
        if(sz[y] > 1) pairs -= sum(sz[y]);
        pairs += sum(sz[y] + sz[x]);
        comps.erase(comps.find(sz[y]));
        comps.erase(comps.find(sz[x]));
        comps.insert(sz[y] + sz[x]);
        sz[y] += sz[x];
        par[x] = y;
        return true;
    }
};

void TC() {
    int n , q;
    cin >> n >> q;
    vector<array<int , 3>>edges(n - 1);
    for(auto& [w , u , v] : edges){
        cin >> u >> v >> w;
        --u , --v;
    }
    DSU dsu(n);
    sort(all(edges));
    vector<pii>queries(q);
    for (int i = 0; i < q; ++i) {
        int x;
        cin >> x;
        queries[i] = {x , i};
    }
    vector<ll>ans(q);
    sort(all(queries));
    int edgIdx = 0;
    for (int i = 0; i < q; ++i) {
        auto [limit , idx] = queries[i];
        for (;edgIdx < n - 1;) {
            auto [w , u , v] = edges[edgIdx];
            if(w > limit) break;
            dsu.merge(u , v);
            edgIdx++;
        }
        ans[idx] = dsu.pairs;
    }
    for (int i = 0; i < q; ++i) {
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