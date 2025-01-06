// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/problemset/problem/2041/B
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

ll calc(ll b  , ll w , int rows)
{
    if(b < 0 || w < 0)
        return rows - 1;
    int v1 = INT_MIN , v2 = INT_MIN;
    v1 = calc( b - rows - 1 , w , rows + 1);
    v2 = calc(b ,  w - rows - 1 , rows + 1);
    return max(v1 , v2);
}

void bad_solve() {
    ll b , w;
    cin >> b >> w;
    cout << calc(b , w , 0) << nl;
}

void solve()
{
    ll b , w , i;
    cin >> b >> w;
    ll l = 0 , r = 65000 , ans = 0;
    while (l <= r)
    {
        ll mid = (l + r) / 2;
        if(b + w >= (mid) * (mid + 1) / 2)
        {
            ans = mid;
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
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