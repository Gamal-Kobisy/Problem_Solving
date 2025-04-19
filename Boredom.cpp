// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/problemset/problem/455/A
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
const int N = 1e5 + 5, M = 1e3, LOG = 20, inf = 0x3f3f3f3f;
ll infLL = 0x3f3f3f3f3f3f3f3f;

ll n , dp[N];
pair<ll , int>a[N];

ll calc(int idx) {
    if (idx == n)
        return 0;
    ll &ret = dp[idx];
    if (~ret)
        return ret;
    ret = calc(idx + 1);
    int sec = idx + 1;
    while (sec < n && a[sec].first <= a[idx].first + 1)
        sec++;
    ret = max(ret, a[idx].first * a[idx].second + calc(sec));

    return ret;
}

void solve() {
    cin >> n;
    map<int , int>freq;
    for(int i = 1; i <= n; i++) {
        ll x;
        cin >> x;
        freq[x]++;
    }
    int idx = 0;
    for (auto i : freq) {
        a[idx++] = i;
    }
    n = idx;
    memset(dp , -1 , sizeof(dp));
    cout << calc(0) << endl;
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
    //     cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
