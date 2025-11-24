// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK :
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

void TC() {
    int n , k , q;
    cin >> n >> k >> q;
    vector<int>ans(n , k + 1);
    vector<int>c1(n) , c2(n);
    vector<pii>mex;

    for (int i = 0; i < q; ++i) {
        int c , l , r;
        cin >> c >> l >> r;
        l-- , r--;
        if(c == 2){
            for (int j = l; j <= r; ++j) {
                c2[j]++;
            }
            mex.pb({l , r});
        }
        if(c == 1){
            for (int j = l; j <= r; ++j) {
                c1[j] = true;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        if(c1[i] and not c2[i]) ans[i] = k;
    }
    for (int i = 0; i < n; ++i) {
        if(c1[i]) c2[i] = -inf;
    }
//    sort(all(mex));
//    for(auto [l , r] : mex){
//        for (int i = 0; i < k; ++i) {
//            if(count(ans.begin() + l , ans.begin() + r + 1 , i) == 0){
//                int max_idx = max_element(c2.begin() + l , c2.begin() + r + 1) - c2.begin();
//                ans[max_idx] = i;
//                c2[max_idx] = -1;
//            }
//        }
//    }

    for (int i = 0; i < n; ++i) {
        if(c2[i] and not c1[i]) ans[i] = (i + 1) % k;
    }

    for (int i = 0; i < n; ++i) {
        cout << ans[i] << sp;
    }

    cout << nl;
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