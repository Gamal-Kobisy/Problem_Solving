// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/contest/2153/problem/C
#include <bits/stdc++.h>
#define ll long long
#define nl '\n'
#define sp ' '
#define all(a) a.begin(),a.end()
#define allr(a) a.rbegin(),a.rend()
#define no cout<<"NO\n"
#define yes cout<<"YES\n"
#define imp cout<<"IMPOSSIBLE\n"
#define ENG_GAMAL ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;
// ————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
const int N = 2e5 + 5, M = 1e3, LOG = 20, inf = 0x3f3f3f3f;
ll infLL = 0x3f3f3f3f3f3f3f3fLL;

void solve() {
    int n;
    cin >> n;
    map<ll, int> freq;
    for (int i = 0; i < n; ++i) {
        ll a;
        cin >> a;
        freq[a]++;
    }

    vector<pair<ll, int>> v;
    for (auto& [x, y] : freq) v.push_back({x, y});
    int m = v.size();
    if (m == 0) {
        cout << 0 << nl;
        return;
    }

    vector<ll> pre_s(m, 0);
    vector<int> pre_c(m, 0);
    pre_s[0] = v[0].first * (v[0].second / 2 * 2);
    pre_c[0] = v[0].second / 2 * 2;
    for (int i = 1; i < m; ++i) {
        pre_s[i] = pre_s[i - 1] + v[i].first * (v[i].second / 2 * 2);
        pre_c[i] = pre_c[i - 1] + (v[i].second / 2 * 2);
    }

    vector<ll> odd;
    for (auto& [x, y] : freq) if (y % 2) odd.push_back(x);

    ll ans = 0;
    for (int i = m - 1; i >= 0; --i) {
        ll maxi = v[i].first;
        ll sum = pre_s[i];
        int cnt = pre_c[i];

        auto it = upper_bound(all(odd), maxi);
        int k = distance(odd.begin(), it);

        ll p = sum;
        int s = cnt;
        if (k >= 1) p += odd[k - 1];
        if (k >= 2) p += odd[k - 2];
        s += min(2, k);

        if (s >= 3 && p > 2 * maxi) {
            ans = p;
            break;
        }
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
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}
