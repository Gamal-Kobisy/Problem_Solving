// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/contest/2167/problem/G
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
const int N = 8000 + 5, M = 1e3, LOG = 20, inf = 0x3f3f3f3f;
ll infLL = 0x3f3f3f3f3f3f3f3f;
int  n , a[N] , c[N] , memo[N];
int calc(int idx){
    if(idx > n) return 0;
    int &ret = memo[idx];
    if(~ret) return ret;
    ret = c[idx];
    for(int j = idx + 1; j <= n; ++j)
        if(a[j] >= a[idx]) ret = max(ret, c[idx] + calc(j));
    return ret;
}
void solve() {
    cin >> n;
    a[0] = c[0] = 0;
    for(int i = 1; i <= n; i++) cin >> a[i];
    int sum = 0;
    for (int i = 1; i <= n; ++i) { cin >> c[i]; sum += c[i]; }
    memset(memo, -1, sizeof memo);
    int maxi = 0;
    for(int i = 1; i <= n; ++i)
        maxi = max(maxi, calc(i));
    cout << sum - maxi << nl;
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
     cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}