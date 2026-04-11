// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/contest/2218/problem/G
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define PI acos(-1)
#define Ones(n) __builtin_popcountll(n)
#define MSB(n) (63 - __builtin_clzll(n))
#define LSB(n) (__builtin_ctzll(n))
#define mem(arrr, xx) memset(arrr,xx,sizeof arrr)
#define fr first
#define sc second
#define pb push_back
#define all(a) a.begin(),a.end()
#define allr(a) a.rbegin(),a.rend()
#define no cout<<"NO\n"
#define yes cout<<"YES\n"
#define imp cout<<"IMPOSSIBLE\n"
#define nl '\n'
#define sp ' '
#define ENG_GAMAL ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;
// ————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
const int N = 2e5 + 5, M = 1e3, LOG = 20, inf = 0x3f3f3f3f;
ll infLL = 0x3f3f3f3f3f3f3f3f;

void TC() {
    int n, m;
    cin >> n >> m;

    vector<int> b(n);
    vector<int> cnt(m, 0);
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        cnt[b[i]]++;
    }

    vector<int> pre(m, 0);
    pre[0] = cnt[0];
    for (int i = 1; i < m; ++i) {
        pre[i] = pre[i - 1] + cnt[i];
    }
    ll ans = 1;
    int MOD = 676767677;
    for (int i = 0; i < n; ++i) {
        if (b[i] == 0) continue;
        int mn = inf;
        if (i > 0) mn = min(mn, b[i - 1]);
        if (i < n - 1) mn = min(mn, b[i + 1]);

        if (mn >= b[i]) {
            ans = 0;
            break;
        } else if (mn == b[i] - 1) {
            ans = (ans * pre[b[i] - 1]) % MOD;
        } else {
            ans = (ans * cnt[b[i] - 1]) % MOD;
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
// test-independent code ——————————————————————
// ————————————————————————————————————————————
    ll tc = 1;
     cin >> tc;
    while (tc--)
    {
        TC();
    }

    return 0;
}