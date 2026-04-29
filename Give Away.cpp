// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://www.spoj.com/problems/GIVEAWAY/
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
const int N = 5e5 + 5, M = 1e3, LOG = 20, inf = 0x3f3f3f3f;
ll infLL = 0x3f3f3f3f3f3f3f3f;
const int SQ = 708;
vector<int>B[SQ];
vector<int>a;
void build(){
    for (int i = 0; i < a.size(); ++i) {
        B[i / SQ].pb(a[i]);
    }
    for(auto &b : B){
        sort(all(b));
    }
}
void update(int idx , int val){
    a[idx] = val;
    B[idx / SQ].clear();
    int l = idx - idx % SQ;
    int r = l + SQ - 1;
    while(l <= r){
        B[idx / SQ].pb(a[l]);
        l++;
    }
    sort(all(B[idx / SQ]));
}

int query(int l, int r, int val){
    int res = 0;
    while(l % SQ and l <= r){
        res += a[l] >= val;
        l++;
    }
    while(l + SQ - 1 <= r){
        auto &b = B[l / SQ];
        res += b.end() - lower_bound(all(b) , val);
        l += SQ;
    }
    while(l <= r){
        res += a[l] >= val;
        l++;
    }
    return res;
}
void TC() {
    int n , q;
    cin >> n;
    a.assign(n , 0);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    build();
    cin >> q;
    while(q--){
        int ty , l , r , idx , val;
        cin >> ty;
        if(ty){
            cin >> idx >> val;
            update(--idx , val);
        }else{
            cin >> l >> r >> val;
            cout << query(--l, --r, val) << nl;
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