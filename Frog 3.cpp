// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://atcoder.jp/contests/dp/tasks/dp_z
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

struct Line {
    ll m, b;

    ll value(ll x) {
        return m * x + b;
    }
};

// minimum query
// slopes must be added in monotonic order
// queries must also be monotonic
struct CHT {

    deque<Line> dq;

    // remove middle line if useless
    bool bad(Line l1, Line l2, Line l3) {

        return (__int128)(l3.b - l1.b) * (l1.m - l2.m)
             <= (__int128)(l2.b - l1.b) * (l1.m - l3.m);
    }

    void add(ll m, ll b) {

        // for maximum query:
        // m *= -1;
        // b *= -1;

        Line cur = {m, b};

        while (dq.size() >= 2 &&
               bad(dq[dq.size() - 2], dq.back(), cur))
            dq.pop_back();

        dq.push_back(cur);
    }

    ll query(ll x) {

        while (dq.size() >= 2 &&
               dq[0].value(x) >= dq[1].value(x))
            dq.pop_front();

        // for maximum query:
        // return -dq[0].value(x);

        return dq[0].value(x);
    }
};

void TC() {
    ll n , c;
    cin >> n >> c;
    vector<ll>a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<ll>memo(n + 1);
    CHT cht;
    memo[0] = 0;
    cht.add(-2 * a[0] , memo[0] + a[0] * a[0]);
    for (int i = 1; i < n; ++i) {
        memo[i] = a[i] * a[i] + c + cht.query(a[i]);
        cht.add(-2 * a[i] , memo[i] + a[i] * a[i]);
    }
    cout << memo[n - 1] << nl;
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