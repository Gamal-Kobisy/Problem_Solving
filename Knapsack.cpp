// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/contest/1446/problem/A
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
    ll n , w;
    cin >> n >> w;
    vector<pair<ll , ll>>a;
    a.emplace_back(0 , 0);
    for (ll i = 0; i < n; ++i) {
        int x;
        cin >> x;
        a.emplace_back(x , i + 1);
    }
    sort(all(a));
    for (ll i = 1; i < n + 1; ++i) {
        a[i].first += a[i - 1].first;
    }
    for (ll i = 0; i < n + 1; ++i) {
        if(a[i].first >= ceil(w / 2.0) && a[i].first <= w)
        {
            cout << i << nl;
            for (ll j = 1; j <= i; ++j) {
                cout << a[j].second << sp;
            }
            cout << nl;
            return;
        }
        if(a[i].first > w)
        {
            for (ll j = i; j >= 0; --j) {
                ll cur = a[i].first - a[j].first;
                if(cur >= ceil(w / 2.0) && cur <= w)
                {
                    cout << i - j << nl;
                    for (ll k = j + 1; k <= i; ++k) {
                        cout << a[k].second << sp;
                    }
                    cout << nl;
                    return;
                }
            }
        }
    }
    cout << -1 << nl;
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