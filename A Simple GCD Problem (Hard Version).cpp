// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/contest/2210/problem/C2
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

ll gcd(ll a, ll b) {
    while (b != 0) {
        ll temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}

ll lcm_vector(const vector<ll>& vec) {
    ll result = vec[0];
    for (size_t i = 1; i < vec.size(); ++i) {
        result = lcm(result, vec[i]);
    }
    return result;
}

void TC() {
    int n;
    cin >> n;
    vector<ll>a(n) , b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    vector<ll> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83};

    vector<ll> target(n);
    target[0] = gcd(a[0], a[1]);
    for(int i = 1; i < n - 1; i++) {
        target[i] = lcm(gcd(a[i], a[i - 1]), gcd(a[i], a[i + 1]));
    }
    target[n - 1] = gcd(a[n - 1], a[n - 2]);

    vector<vector<ll>> val(n);
    vector<vector<int>> cost(n);

    for(int i = 0; i < n; i++) {
        val[i].push_back(a[i]);
        cost[i].push_back(0);
        if (target[i] <= b[i] and target[i] != a[i]) {
            val[i].push_back(target[i]);
            cost[i].push_back(1);
        }
        for (ll p : primes) {
            if (p * a[i] <= b[i]) {
                val[i].push_back(p * a[i]);
                cost[i].push_back(1);
            }
        }
        if (b[i] / a[i] >= 89) {
            val[i].push_back(a[i]);
            cost[i].push_back(1);
        }
    }
    vector<vector<int>> memo(n, vector<int>(30, -1));
    function<int(int,  int)> solve = [&](int i, int s) -> int {
        if (i == n) return 0;

        int &res = memo[i][s];
        if (~res) return memo[i][s];

        res = -infLL;
        ll g = gcd(a[i - 1], a[i]);
        for (int u = 0; u < val[i].size(); u++) {
            if (gcd(val[i - 1][s], val[i][u]) == g) {
                int next_ans = solve(i + 1, u);

                if (next_ans != -1e9) {
                    res = max(res, cost[i][u] + next_ans);
                }
            }
        }

        return res;
    };

    int ans = 0;
    for (int u = 0; u < val[0].size(); u++) {
        int cand = solve(1, u);
        ans = max(ans, cost[0][u] + cand);
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