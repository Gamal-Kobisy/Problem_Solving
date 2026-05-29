// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/problemset/problem/1957/D
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
const int N = 2e5 + 5, M = 1e3, LOG = 30, inf = 0x3f3f3f3f;
ll infLL = 0x3f3f3f3f3f3f3f3f;

void TC() {
    int n;
    cin >> n;
    vector<int>a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<int> pref(n + 1, 0);
    for (int i = 0; i < n; ++i) pref[i + 1] = pref[i] ^ a[i];
    vector<array<int , LOG>> preOn(n + 1), preOf(n + 1);
    vector<array<int , LOG>> sufOn(n + 1), sufOf(n + 1);
    for (int bit = 0; bit < LOG; ++bit) {
        preOn[0][bit] = (pref[0] >> bit) & 1;
        preOf[0][bit] = 1 - preOn[0][bit];
        for (int i = 1; i <= n; ++i) {
            preOn[i][bit] = preOn[i - 1][bit] + ((pref[i] >> bit) & 1);
            preOf[i][bit] = preOf[i - 1][bit] + (1 - ((pref[i] >> bit) & 1));
        }
    }
    for (int bit = 0; bit < LOG; ++bit) {
        sufOn[n][bit] = (pref[n] >> bit) & 1;
        sufOf[n][bit] = 1 - sufOn[n][bit];
        for (int i = n - 1; i >= 0; --i) {
            sufOn[i][bit] = sufOn[i + 1][bit] + ((pref[i] >> bit) & 1);
            sufOf[i][bit] = sufOf[i + 1][bit] + (1 - ((pref[i] >> bit) & 1));
        }
    }

    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        int bit = MSB(a[i]);
        int pL = (pref[i] >> bit) & 1;
        int pR = (pref[i + 1] >> bit) & 1;
        ll leftOn = pL ? preOf[i][bit] : preOn[i][bit];
        ll leftOf = (i + 1) - leftOn;
        ll rightOn = pR ? sufOf[i + 1][bit] : sufOn[i + 1][bit];
        ll rightOf = (n - i) - rightOn;
        ans += 1LL * leftOn * rightOf + 1LL * leftOf * rightOn;
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