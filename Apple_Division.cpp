// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://cses.fi/problemset/task/1623
#include <bits/stdc++.h>
#define ll long long
#define nl '\n'
#define all(a) a.begin(),a.end()
#define allr(a) a.rbegin(),a.rend()
#define no cout<<"NO\n"
#define yes cout<<"YES\n"
#define ENG_GAMAL ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;
// ————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
const int N = 2e5 + 5, M = 1e3, LOG = 20, inf = 0x3f3f3f3f;
ll infLL = 0x3f3f3f3f3f3f3f3f;
ll ans = LLONG_MAX;

void backtrack(int idx , vector<ll>a , ll sum_a , ll sum_b)
{
    if(idx == a.size())
    {
        ans = min(ans , abs(sum_a - sum_b));
        return;
    }

    backtrack(idx + 1 , a , sum_a + a[idx] , sum_b - a[idx]);
    backtrack(idx + 1 , a , sum_a , sum_b);

}
void solve() {
    int n ;
    cin >> n;
    vector<ll>a(n);
    ll sum = 0;
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
    }
    backtrack(0 , a , 0 , sum);
cout << ans << nl;
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
    ll t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}