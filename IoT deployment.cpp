// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/group/PusYEORUbx/contest/689600/problem/M
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

struct DSU2{
    vector<int> par , sz;
    vector<pii>ans;
    vector<vector<pii>> queries;

    DSU2(int n, int q) : par(n) , sz(n , 1), queries(n), ans(q, {-1 , -1}) {
        iota(all(par) , 0);
    }

    int find(int x){
        if(x == par[x]) return x;
        else return par[x] = find(par[x]);
    }

    void add_query(int u, int v, int idx) {
        queries[u].pb({v, idx});
        queries[v].pb({u, idx});
    }

    void merge(int x , int y , int w , int id){
        x = find(x);
        y = find(y);
        if(x == y) return;
        if(sz[x] > sz[y]) swap(x , y);

        for(auto& q : queries[x]){
            if(find(q.fr) == y){
                ans[q.sc] = {w , id};
            }else{
                queries[y].pb(q);
            }
        }
        queries[x].clear();

        sz[y] += sz[x];
        par[x] = y;
    }
};

void TC() {
    int n , m;
    cin >> n >> m;
    vector<array<int , 5>> edges(m);
    vector<array<int , 5>> orig(m);
    for(int i=0; i<m; ++i) cin >> edges[i][0];
    for(int i=0; i<m; ++i) cin >> edges[i][3];
    for(int i=0; i<m; ++i) {
        cin >> edges[i][1] >> edges[i][2];
        edges[i][4] = i;
        orig[i] = edges[i];
    }
    ll s;
    cin >> s;
    sort(all(edges));

    vector<bool> inMST(m, false);
    ll MST = 0;
    DSU dsu(n + 1);
    map<int, int> freq;
    for (int i = 0; i < m; ++i) {
        if(dsu.merge(edges[i][1] , edges[i][2])){
            MST += edges[i][0];
            inMST[edges[i][4]] = true;
            freq[edges[i][3]]++;
        }
    }
    DSU2 dsu2(n + 1 , m);
    for (int i = 0; i < m; ++i) {
        if(!inMST[edges[i][4]]){
            dsu2.add_query(edges[i][1] , edges[i][2] , edges[i][4]);
        }
    }
    for(int i = 0; i < m; ++i){
        if(inMST[edges[i][4]]){
            dsu2.merge(edges[i][1] , edges[i][2] , edges[i][0] , edges[i][4]);
        }
    }

    ll ans = MST - (s / freq.begin()->fr);
    int best_in = -1, best_out = -1, best_c = freq.begin()->fr;
    for(int i = 0; i < m; ++i) {
        int id_in = edges[i][4];
        if(!inMST[id_in]) {
            auto [mxW_out , mxWID_out] = dsu2.ans[id_in];
            if(mxWID_out == -1) continue;
            int c_out = orig[mxWID_out][3];
            if(--freq[c_out] == 0) freq.erase(c_out);
            int c_in = orig[id_in][3];
            freq[c_in]++;
            ll newMST = MST - mxW_out + orig[id_in][0];
            int curMinC = freq.begin()->fr;
            ll cand = newMST - (s / curMinC);
            if(cand < ans) {
                ans = cand;
                best_in = id_in;
                best_out = mxWID_out;
                best_c = curMinC;
            }
            if(--freq[c_in] == 0) freq.erase(c_in);
            freq[c_out]++;
        }
    }
    cout << ans << nl;
    if (best_in == -1) {
        bool taken = false;
        for (int i = 0; i < m; ++i) {
            int id = edges[i][4];
            if (inMST[id]) {
                cout << id + 1 << sp;
                if (orig[id][3] == best_c and not taken) {
                    cout << orig[id][0] - (s / best_c) << nl;
                    taken = true;
                } else cout << orig[id][0] << nl;
            }
        }
    } else {
        bool taken = false;
        for (int i = 0; i < m; ++i) {
            int id = edges[i][4];
            if (inMST[id] and id != best_out) {
                cout << id + 1 << sp;
                if (orig[id][3] == best_c and not taken) {
                    cout << orig[id][0] - (s / best_c) << nl;
                    taken = true;
                } else cout << orig[id][0] << nl;
            }
        }
        cout << best_in + 1 << sp;
        if (orig[best_in][3] == best_c and not taken) {
            cout << orig[best_in][0] - (s / best_c) << nl;
        } else {
            cout << orig[best_in][0] << nl;
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