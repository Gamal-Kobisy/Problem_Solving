// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://cses.fi/problemset/task/2101
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

struct DSU{
    vector<int>par , sz;

    DSU(int n) : par(n) , sz(n , 1) {iota(all(par) , 0);}

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
        sz[y] += sz[x];
        par[x] = y;
        return true;
    }
};

void TC() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<array<int , 2>>edges(m + 1);
    for (int i = 1; i <= m; ++i) {
        cin >> edges[i][0] >> edges[i][1];
    }
//    for(auto &[a , b] : edges){
//        cin >> a >> b;
//    }
    vector<int>L(q), R(q), ans(q , -1);
    vector<array<int , 2>>queries(q);
    vector<vector<int>>buckets(m + 1);
    for (int i = 0; i < q; ++i) {
        int a , b;
        cin >> a >> b;
        queries[i] = {a , b};
        L[i] = 0 , R[i] = m;
    }
    int steps = LOG;
    while(steps--){
        for (int i = 0; i < q; ++i) {
            if(L[i] <= R[i]) buckets[(L[i] + R[i]) / 2].pb(i);
        }
        DSU dsu(n + 1);
        for(int mid = 0 ; mid <= m ; mid++){
            auto [a , b] = edges[mid];
            dsu.merge(a , b);
            for(int query : buckets[mid]){
                auto [x , y] = queries[query];
                if(dsu.same(x , y)){
                    ans[query] = mid;
                    R[query] = mid - 1;
                }else{
                    L[query] = mid + 1;
                }
            }
            buckets[mid].clear();
        }
    }
    for(int i : ans) cout << i << nl;

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