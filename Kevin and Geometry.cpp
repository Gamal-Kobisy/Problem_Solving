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
    ll n;
    cin >> n;
    vector<ll>a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(all(a));
    set<ll>pairs;
    for (ll i = 0; i < n - 1; ++i) {
        if(a[i] == a[i + 1])
            pairs.insert(a[i]) , i++;
    }
    if(pairs.size() >= 2)
        return void(cout << *pairs.begin() << sp << *pairs.begin() << sp << *next(pairs.begin()) << sp << *next(pairs.begin()) << nl);
    if(pairs.size() == 1)
    {
        auto it = lower_bound(all(a) , *pairs.begin());
        a.erase(next(it));
        a.erase(it);
        for (ll i = 0; i < a.size(); ++i) {
            it = upper_bound(all(a) , (a[i] - 2 * *pairs.begin()));
            if(it != a.end() && it - a.begin() != i)
                return void(cout << *pairs.begin() << sp << *pairs.begin() << sp << a[i] << sp << *it << nl);
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