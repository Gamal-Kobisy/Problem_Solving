// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/problemset/problem/2044/E
#include <bits/stdc++.h>
#define ll long long
#define nl '\n'
#define sp ' '
#define all(a) a.begin(),a.end()
#define allr(a) a.rbegin(),a.rend()
#define no cout<<"NO\n"
#define yes cout<<"YES\n"
#define ENG_GAMAL ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;
// ————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
const int N = 2e5 + 5, M = 1e3, LOG = 20, inf = 0x3f3f3f3f;
ll infLL = 0x3f3f3f3f3f3f3f3f;

void bad_solve() {
    ll k , l1 , r1 , l2 , r2;
    cin >> k >> l1 >> r1 >> l2 >> r2;
    if(k == 1)
        return void(cout << max(l2 - r1 , 0ll) << nl);
    ll ans = 0;
    for (ll i = min(l1 , l2); i <= r1; ++i) {
        ll maxi = logl(r2 / i) / logl(k);
        ll l = 0 , r = maxi , mini = r;
        while (l <= r)
        {
            ll mid = (l + r) / 2;
            if(i * powl(k , mid) >= l2)
            {
                mini = mid;
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        if(i * pow(k , mini) < l2)
            break;
        ll t_ans = maxi - mini + 1;
        ll x = min((ll)(r2 / powl(k , maxi)) , r1);
        ll freq = x - i + 1;
        ans += t_ans * freq;
        i = x;
    }
    cout << ans << nl;
}

void solve()
{
    ll k , l1 , r1 , l2 , r2;
    cin >> k >> l1 >> r1 >> l2 >> r2;
    ll ans = 0;
    for (ll n = 0; n < 32; ++n) {
        if(powl(k , n) > r2)
            break;
        ll l = l1 , r = r1 , min_x = r1 + 1 , max_x = l1 - 1;
        while (l <= r)
        {
            ll mid = (l + r) / 2;

            if(mid * powl(k , n) >= l2)
            {
                min_x = mid;
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        l = l1 , r = r1;
        while (l <= r)
        {
            ll mid = (l + r) / 2;

            if(mid * powl(k , n) <= r2)
            {
                max_x = mid;
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        ans += max_x - min_x + 1;
    }
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
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}