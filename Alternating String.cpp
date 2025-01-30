// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/contest/2008/problem/E
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
    string s;
    cin >> n >> s;
    ll ans = 0;

    if (n & 1) {
        vector<vector<int>> pre_ev(n + 2, vector<int>(26, 0));
        vector<vector<int>> pre_od(n + 2, vector<int>(26, 0));

        for (ll i = 1; i <= n + 1; ++i) {
            pre_ev[i] = pre_ev[i - 1];
            pre_od[i] = pre_od[i - 1];
            if (i == n + 1)
                continue;
            if (i & 1)
                pre_ev[i][s[i - 1] - 'a']++;
            else
                pre_od[i][s[i - 1] - 'a']++;
        }

        ans = n + 1;
        for (ll i = 1; i <= n; ++i) {
            vector<pair<ll, char>> ev_freq(26), od_freq(26);
            for (ll j = 0; j < 26; ++j) {
                ev_freq[j].second = od_freq[j].second = 'a' + j;
                od_freq[j].first = pre_ev[i - 1][j] + (pre_od[n + 1][j] - pre_od[i][j]);
                ev_freq[j].first = pre_od[i - 1][j] + (pre_ev[n + 1][j] - pre_ev[i][j]);
            }
            sort(allr(ev_freq));
            sort(allr(od_freq));
            ans = min(ans, (n / 2 - ev_freq[0].first) + (n / 2 - od_freq[0].first) + 1);
        }
        cout << ans << nl;
    } else {
        vector<pair<ll, char>> ev_freq(26), od_freq(26);
        for (ll i = 0; i < 26; ++i) {
            ev_freq[i].second = od_freq[i].second = 'a' + i;
        }
        for (ll i = 0; i < n; ++i) {
            if (i & 1)
                ev_freq[s[i] - 'a'].first++;
            else
                od_freq[s[i] - 'a'].first++;
        }
        sort(allr(ev_freq));
        sort(allr(od_freq));
        ans += n / 2 - ev_freq[0].first;
        ans += n / 2 - od_freq[0].first;
        cout << ans << nl;
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