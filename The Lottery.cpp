// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1266
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

ll n , m;

ll gcd(ll a, ll b) {
    while (b != 0) {
        ll temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}

ll lcm_vector(const vector<ll>& vec) {
    ll result = vec[0];
    for (size_t i = 1; i < vec.size(); ++i) {
        result = lcm(result, vec[i]);
    }
    return result;
}

void solve() {
    vector<int>a(m);
    for (int i = 0; i < m; ++i) {
        cin >> a[i];
    }
    ll ans = 0;
    for (int i = 1 ; i < (1 << m); ++i) {
        ll l = 1;
        for (int j = 0; j < m; ++j) {
            if(i & (1 << j))
                l = lcm(l , a[j]);
//            if(l > n)
//                break;
        }
        if(__builtin_popcount(i) & 1)
            ans += n / l;
        else
            ans -= n / l;
    }
    cout << n - ans << nl;
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
//     cin >> t;
    while (cin >> n >> m)
    {
        solve();
    }

    return 0;
}