// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://vjudge.net/problem/CodeChef-FREQARRRET
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
    vector<ll> v(n) , ans(n);
    map<ll, ll> freq;
    for(ll i=0; i<n; i++) {
        cin >> v[i];
        freq[v[i]]++;
    }
    for (pair<ll, ll> p : freq) {
        if (p.second % p.first) {
            return void(cout << -1 << nl);
        }
    }
    map<ll, pair<ll , ll>> mp;
    ll num = 1;
    for(ll i=0; i<n; i++) {
        if (mp.find(v[i]) == mp.end() || mp[v[i]].second == 0) {
            mp[v[i]] = {num++ , v[i] - 1};
        }
        else {
            mp[v[i]].second--;
        }
        ans[i] = mp[v[i]].first;
    }
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << " ";
    }
    cout << endl;
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
