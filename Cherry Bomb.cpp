// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK :
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
    ll n , m;
    cin >> n >> m;
    vector<pair<ll,ll>>a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].second;
    }
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first;
    }
    sort(allr(a));
    if(a[0].first == -1)
    {
        ll start = a.front().second - a.back().second;
        if(start > m)
            return void(cout << 0 << nl);
        else
            cout << m - start + 1 << nl;
    }
    else
    {
        ll res = a[0].first + a[0].second;
        for (int i = 1; i < n; ++i) {
            if(a[i].first == -1)
            {
                if(a[i].second > res || res - a[i].second > m)
                    return void(cout << 0 << nl);
                else
                    continue;
            }
            else if(a[i].first + a[i].second != res)
                return void(cout << 0 << nl);
        }
        cout << 1 << nl;
    }
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