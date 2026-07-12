// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK :
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
    int n;
    ll c;
    cin >> n >> c;
    vector<ll> first(n);
    vector<pair<ll, int>> ord;
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        first[i] = x + i + 1;
        ord.push_back({x + min(1ll * (i + 1), 1ll * (n - i)), i});
    }
    sort(all(ord));
    vector<ll> pref(n + 1, 0);
    vector<int> pos(n);
    for (int i = 0; i < n; i++) {
        pref[i + 1] = pref[i] + ord[i].fr;
        pos[ord[i].sc] = i;
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ll rem = c - first[i];
        if (rem < 0) continue;
        int p = pos[i];
        int lo = 0, hi = n;
        int best = 0;
        while (lo <= hi) {
            int mid = (lo + hi) >> 1;
            ll need = pref[mid];
            int cnt = mid + 1;
            if (mid > p) {
                need -= ord[p].first;
                cnt--;
            }
            if (need <= rem) {
                best = cnt;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        ans = max(ans, best);
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
    ll tc = 1;
     cin >> tc;
    while (tc--)
    {
        TC();
    }

    return 0;
}