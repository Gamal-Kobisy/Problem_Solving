// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/group/Rilx5irOux/contest/710261/problem/C
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
#define fi first
#define se second
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
int n, h;
vector<pair<pair<int, int>, int>> a;

struct State {
    int sc = -inf, pen = -inf;
    vector<int> seq;
    bool operator<(const State& o) const {
        if (sc != o.sc) return sc < o.sc;
        if (pen != o.pen) return pen < o.pen;
        return seq > o.seq;
    }
};

State dp[105][305];
bool vis[105][305];

State solve(int i, int t) {
    if (t > h)
        return {-inf, -inf, {}};
    if (i == n)
        return {0, 0, {}};

    if (vis[i][t])
        return dp[i][t];
    vis[i][t] = true;
    auto& ret = dp[i][t];
    ret = solve(i + 1, t);
    if (h - t >= a[i].fi.fi) {
        int new_time = t + a[i].fi.fi;
        State res = solve(i + 1, new_time);

        res.sc += a[i].fi.se;
        res.pen -= new_time;
        res.seq.insert(res.seq.begin(), a[i].se);

        ret = max(ret, res);
    }
    return ret;
}

void TC() {
    cin >> n >> h;
    h *= 60;
    a.resize(n);
    for (int i = 0; i < n; i++)
        a[i].se = i;
    for (int i = 0; i < n; i++)
        cin >> a[i].fi.fi, a[i].fi.fi /= 50;
    for (int i = 0; i < n; i++)
        cin >> a[i].fi.se;
    sort(all(a), [](const pair<pair<int, int>, int>& x, const pair<pair<int, int>, int>& y) {
        return make_pair(x.fi.fi, x.se) < make_pair(y.fi.fi, y.se);
    });

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= h; j++) {
            vis[i][j] = false;
        }
    }
    vector<int> ans = solve(0, 0).seq;
    for (int i = 0; i < (int)ans.size(); i++)
        cout << ans[i] + 1 << sp;
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
    ll tc = 1;
    cin >> tc;
    while (tc--)
    {
        TC();
    }

    return 0;
}
