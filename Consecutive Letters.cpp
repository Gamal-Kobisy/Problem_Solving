// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://www.spoj.com/problems/CONSEC/
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

void TC(int tc_num) {
    string s;
    cin >> s;
    int q;
    cin >> q;

    vector<pair<int, int>> queries(q);
    string work_s = s;

    for (int i = 0; i < q; i++) {
        cin >> queries[i].first >> queries[i].second;
        if (queries[i].first == 2) {
            work_s[queries[i].second] = '#';
        }
    }

    int n = s.length();
    DSU dsu(n);

    for (int i = 0; i < n - 1; i++) {
        if (work_s[i] != '#' && work_s[i] == work_s[i + 1]) {
            dsu.merge(i, i + 1);
        }
    }

    vector<int> ans;

    for (int i = q - 1; i >= 0; i--) {
        int type = queries[i].first;
        int idx = queries[i].second;

        if (type == 1) {
            ans.push_back(dsu.sz[dsu.find(idx)]);
        } else {
            work_s[idx] = s[idx];

            if (idx > 0 && work_s[idx - 1] == work_s[idx]) {
                dsu.merge(idx, idx - 1);
            }
            if (idx < n - 1 && work_s[idx + 1] == work_s[idx]) {
                dsu.merge(idx, idx + 1);
            }
        }
    }

    cout << "Case " << tc_num << ":" << nl;
    for (int i = ans.size() - 1; i >= 0; i--) {
        cout << ans[i] << nl;
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
    for (int i = 1; i <= tc; i++)
    {
        TC(i);
    }

    return 0;
}