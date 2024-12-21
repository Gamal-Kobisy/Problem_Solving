// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/problemset/problem/1798/B
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
    int m;
    cin >> m;
    map<int , int>can_win_at_idx;
    vector<vector<int>>days;
    for (int i = 0; i < m; ++i) {
        int n;
        cin >> n;
        vector<int>day(n);
        for (int j = 0; j < n; ++j) {
            cin >> day[j];
            can_win_at_idx[day[j]] = max(can_win_at_idx[day[j]] , i);
        }
        days.emplace_back(day);
    }
    vector<int>ans;
    for (ll i = 0; i < m; ++i) {
        bool found = false;
        for (int j = 0; j < days[i].size(); ++j) {
            if(can_win_at_idx[days[i][j]] == i)
            {
                found = true;
                ans.emplace_back(days[i][j]);
                break;
            }
        }
        if(!found)
            return void(cout << -1 << nl);
    }
    for (ll i = 0; i < m; ++i) {
        cout << ans[i] << ' ';
    }
    cout << nl;
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