// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/contest/2051/problem/C
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

void solve() {
    ll n, m, k;
    cin >> n >> m >> k;
    vector<ll>a(m);
    map<ll , bool>known;
    for (ll i = 0; i < m; ++i) {
        cin >> a[i];
    }
    for (ll i = 0; i < k; ++i) {
        ll x;
        cin >> x;
        known[x] = true;
    }
    if (k == n) {
        cout << string(m, '1') << nl;
        return;
    }
    if (k + 1 < n)
    {
        cout << string(m , '0') << nl;
        return;
    }
    string answer = string(m , '0');
    for (ll i = 0; i < m; ++i) {
        if(!known[a[i]])
        {
            answer[i] = '1';
            break;
        }
    }

    cout << answer << nl;
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