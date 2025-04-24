// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/contest/2093/problem/E
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

void solve() {
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }

    ll l = 0, r = n / m, ans = 0;
    while (l <= r) {
        ll mid = (l + r) / 2;
        vector< bool > freq(mid + 1);
        int mex = 0;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] < mid) {
                freq[a[i]] = true;
            }
            while (freq[mex]) {
                mex++;
            }
            if (mex == mid) {
                mex = 0;
                cnt++;
                fill(all(freq), false);
                if (cnt >= m) {
                    break;
                }
            }
        }
        if (cnt >= m) {
            ans = mid;
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
    }

    cout << ans << nl;
}

int main() {
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
