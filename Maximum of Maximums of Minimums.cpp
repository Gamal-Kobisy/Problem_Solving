// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/contest/872/problem/B
#include <bits/stdc++.h>
#define ll long long
#define int ll
#define nl '\n'
#define sp ' '
#define all(a) a.begin(),a.end()
#define allr(a) a.rbegin(),a.rend()
#define no cout<<"NO\n"
#define yes cout<<"YES\n"
#define imp cout<<"IMPOSSIBLE\n"
#define ENG_GAMAL ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;
// ————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
const int N = 1e5 + 5, M = 1e3, LOG = 20, inf = 0x3f3f3f3f;
ll infLL = 0x3f3f3f3f3f3f3f3f;
int n , k , s[N] , T[N][LOG];

int merge(int a , int b){
    return min(a , b);
}

void build(){
    for (int i = 0; i < n; ++i) {
        T[i][0] = s[i];
    }
    for(int pw = 1 ; (1 << pw) <= n ; pw++){
        for (int i = 0; i + (1 << pw) <= n ; ++i) {
            T[i][pw] = merge(T[i][pw - 1] , T[i + (1 << (pw - 1))][pw - 1]);
        }
    }
}

int query(int l  ,int r)
{
    int sz = r - l + 1;
    int ret = 0;
    for (int i = 21; i >= 0; --i) {
        if((sz >> i) & 1)
        {
            ret = merge(ret  , T[l][i]);
            l += (1 << i);
        }
    }
    return ret;
}

int query2(int l , int r){
    int sz = r - l + 1;
    int pw = log2(sz);
    return merge(T[l][pw] , T[r - (1 << pw) + 1][pw]);
}

void solve() {
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }
    build();
    if(k == 1){
        cout << query2(0 , n - 1) << nl;
    }else if(k == 2){
        int ans = -infLL;
        for(int i = 0 ; i < n ; i++){
            ans = max({ans, query2(0, i), query2(i + 1, n - 1)});
        }
        cout << ans << nl;
    }else{
        cout << *max_element(s , s + n) << nl;
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

signed main() {
    file();
    ENG_GAMAL
// test-independent code ——————————————————————
// ————————————————————————————————————————————
    ll t = 1;
//     cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}