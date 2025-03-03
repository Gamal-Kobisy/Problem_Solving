// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/gym/104872/problem/F
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
    int n;
    cin >> n;
    map<ll, ll> freq , cols , rows;
    vector<vector<ll>> a(n, vector<ll>(n));
    for (ll i = 0; i < n; ++i) {
        ll sum = 0;
        for (ll j = 0; j < n; ++j) {
            cin >> a[i][j];
            sum += a[i][j];
        }
        freq[sum]++;
        rows[i] = sum;
    }
    for (ll i = 0; i < n; ++i) {
        ll sum = 0;
        for (ll j = 0; j < n; ++j) {
            sum += a[j][i];
        }
        freq[sum]++;
        cols[i] = sum;
    }
    ll sum1 = (freq.begin())->first;
    ll sum2 = next(freq.begin())->first;
    ll sum3 = next(next(freq.begin()))->first;
    ll r1 = 0, r2 = 0, c1 = 0, c2 = 0;
    for (ll i = 0; i < n; ++i) {
        ll sum = 0;
        for (ll j = 0; j < n; ++j) {
            sum += a[i][j];
        }
        if(sum == sum3)
            r1 = i + 1;
        if(sum == sum1)
            r2 = i + 1;
    }
    for (ll i = 0; i < n; ++i) {
        ll sum = 0;
        for (ll j = 0; j < n; ++j) {
            sum += a[j][i];
        }
        if(sum == sum3)
            c1 = i + 1;
        if(sum == sum1)
            c2 = i + 1;
    }
    if(r1 == 0 || r2 == 0) {
        for (ll i = 0; i < n; ++i) {
            if(a[i][c1 - 1] - a[i][c2 - 1] == sum2 - sum1) {
                r1 = r2 = i + 1;
                break;
            }
        }
    }
    if(c1 == 0 || c2 == 0) {
        for (ll i = 0; i < n; ++i) {
            if(a[r1 - 1][i] - a[r2 - 1][i] == sum2 - sum1) {
                c1 = c2 = i + 1;
                break;
            }
        }
    }
    cout << r1 << sp << c1 << nl << r2 << sp << c2 << nl;
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
    // cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}