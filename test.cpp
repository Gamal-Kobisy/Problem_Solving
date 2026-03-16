// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK :
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

    int n, b, t;
    cin >> n >> b >> t;

    int max_mask = (1 << b);

    vector<int> cnt(max_mask, 0);

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cnt[x]++;
    }

    for (int i = 0; i < max_mask; i++) {
        if (cnt[i] >= t) {
            cout << 0 << nl;
            return;
        }
    }

    vector<pii> unique_a;
    for (int i = 0; i < max_mask; i++) {
        if (cnt[i]) unique_a.pb({i, cnt[i]});
    }

    vector<int> cur_cnt(max_mask, 0);

    auto check = [&](int k)->bool {

        for (int mask = 0; mask < max_mask; mask++) {

            if (Ones(mask) != k) continue;

            int keep = (~mask) & (max_mask - 1);

            vector<int> touched;

            for (auto &p : unique_a) {

                int mod_val = p.fr & keep;

                if (cur_cnt[mod_val] == 0) touched.pb(mod_val);

                cur_cnt[mod_val] += p.sc;

                if (cur_cnt[mod_val] >= t) {

                    for (int v : touched) cur_cnt[v] = 0;

                    return true;
                }
            }

            for (int v : touched) cur_cnt[v] = 0;
        }

        return false;
    };

    int l = 1, r = b, ans = b;

    while (l <= r) {

        int mid = (l + r) / 2;

        if (check(mid)) {
            ans = mid;
            r = mid - 1;
        }
        else {
            l = mid + 1;
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
//     cin >> tc;
    while (tc--)
    {
        TC();
    }

    return 0;
}