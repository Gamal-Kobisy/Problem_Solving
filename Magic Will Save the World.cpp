// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/problemset/problem/1862/F
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

void TC() {
    ll x , y , n;
    cin >> y >> x >> n;
    vector<int>a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    ll sum = accumulate(all(a) , 0);
    vector<bool> dp(sum + 1, false);
    dp[0] = true;
    for (int x : a) {
        for (ll s = sum; s >= x; --s) {
            if (dp[s - x]) dp[s] = true;
        }
    }
    ll ans = 1e6;
    for (ll water = 0; water <= sum; ++water) {
        if (dp[water]) {
            ll timeW = (water + x - 1) / x;
            ll timeF  = (sum - water + y - 1) / y;
            ans = min(ans, max(timeW, timeF));
        }
    }

    cout << ans << nl;
//    cout << sum << nl;
//    int lo = 1 , hi = 1e6;
//    while(lo <= hi){
//        int md = (lo + hi) / 2;
//        ll curW = y * md;
//        curW = min(curW , sum); /// this is a very good optimization
//        ll curF = x * md;
//        vector<vector<int>> memo(n + 1, vector<int>(curW + 1, 0));
//        for (int i = 1; i <= n; ++i) {
//            for (int w = 0; w <= curW; ++w) {
//                memo[i][w] = memo[i - 1][w];
//                if (w >= a[i]) {
//                    memo[i][w] = max(memo[i][w], memo[i - 1][w - a[i]] + a[i]);
//                }
//            }
//        }
//        int mx = 0;
//        for (int i = 0; i <= curW; ++i) {
//            mx = max(mx , memo[n][i]);
//        }
//        bool ok = (sum - mx) <= curF;
//        if(ok){
//            hi = md - 1;
//        }else{
//            lo = md + 1;
//        }
//    }
//    cout << lo << nl;
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