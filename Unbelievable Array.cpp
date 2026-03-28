// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://toph.co/p/unbelievable-array
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
        if(x == y) return false;
        sz[y] += sz[x];
        par[x] = y;
        return true;
    }
};

void TC(int tc) {
    int n, q;
    cin >> n >> q;

    DSU dsu(n);

    vector<int> a(n);
    vector<int> pos(N, -1);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (pos[a[i]] == -1) {
            pos[a[i]] = i;
        } else {
            dsu.merge(i, pos[a[i]]);
        }
    }

    cout << "Case " << tc << ":" << nl;

    while(q--) {
        int ty;
        cin >> ty;

        if(ty == 1) {
            int x, y;
            cin >> x >> y;

            if(x == y || pos[x] == -1) continue;

            if(pos[y] == -1) {
                pos[y] = pos[x];
                a[pos[y]] = y;
                pos[x] = -1;
            } else {
                dsu.merge(pos[x], pos[y]);
                pos[x] = -1;
            }
        } else {
            int idx;
            cin >> idx;
            --idx;
            cout << a[dsu.find(idx)] << nl;
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
     cin >> tc;
    for (int i = 0; i < tc; ++i) {
        TC(i + 1);
    }

    return 0;
}