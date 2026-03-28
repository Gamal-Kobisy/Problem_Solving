// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://atcoder.jp/contests/abc420/tasks/abc420_e
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
#define no cout<<"No\n"
#define yes cout<<"Yes\n"
#define imp cout<<"IMPOSSIBLE\n"
#define nl '\n'
#define sp ' '
#define ENG_GAMAL ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;
// ————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
const int N = 2e5 + 5, M = 1e3, LOG = 20, inf = 0x3f3f3f3f;
ll infLL = 0x3f3f3f3f3f3f3f3f;

struct DSU{
    vector<int>par;
    vector<pii>sz;

    DSU(int n) : par(n) , sz(n,{1 , 0}) {iota(all(par) , 0);}

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
        sz[y].fr += sz[x].fr;
        sz[y].sc += sz[x].sc;
        par[x] = y;
        return true;
    }
};

void TC() {
    int n , q;
    cin >> n >> q;
    vector<bool>isBlack(n , false);
    DSU dsu(n);
    while(q--){
        int ty , u , v;
        cin >> ty;
        if(ty == 1){
            cin >> u >> v;
            dsu.merge(--u , --v);
        }else if(ty == 2){
            cin >> u;
            if(isBlack[--u]){
                dsu.sz[dsu.find(u)].sc--;
                isBlack[u] = false;
            }else{
                dsu.sz[dsu.find(u)].sc++;
                isBlack[u] = true;
            }
        }else{
            cin >> u;
            dsu.sz[dsu.find(--u)].sc ? yes : no;
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