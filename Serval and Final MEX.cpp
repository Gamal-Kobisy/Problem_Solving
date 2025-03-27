// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/contest/2085/problem/B
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
    map<ll,ll>mp;
    bool zero = false;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        mp[a[i]]++;
        if (a[i] == 0)
            zero = true;
    }
    if (!zero) {
        cout << 1 << nl;
        cout << 1 << sp << n << nl;
    }
    else if (a.front() != 0) {
        cout << 2 << nl;
        cout << 2 << sp << n << nl;
        cout << 1 << sp << 2 << nl;
    }
    else if (a.back() != 0) {
        cout << 2 << nl;
        cout << 1 << sp << n - 1 << nl;
        cout << 1 << sp << 2 << nl;
    }
    else {
        auto it1 = find(all(a) , 0);
        if (it1 == a.begin())
            it1++;
        auto it2 = find(it1 + 1, a.end() , 0);
        cout << 3 << nl;
        cout << 1 << sp << it1 - a.begin() + 1 << nl;
        cout << 2 << sp << n - (it1 - a.begin()) << nl;
        cout << 1 << sp << 2 << nl;
    }
}

void file() {
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
    while (t--) {
        solve();
    }

    return 0;
}
