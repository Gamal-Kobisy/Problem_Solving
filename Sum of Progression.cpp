// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/problemset/problem/1921/F
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
const int SQ = 317;
vector<ll> a;
vector<vector<ll>> pre_sum;
vector<vector<ll>> pre_mult;

void build() {
    int n = a.size() - 1;
    for (int d = 1; d < SQ; ++d) {
        for (int i = 1; i <= n; ++i) {
            pre_sum[d][i] = a[i];
            pre_mult[d][i] = a[i] * (i / d);
            if (i > d) {
                pre_sum[d][i] += pre_sum[d][i - d];
                pre_mult[d][i] += pre_mult[d][i - d];
            }
        }
    }
}

ll query(int s, int d, int k) {
    if (d >= SQ) {
        ll ans = 0;
        for (int i = 1; i <= k; ++i) {
            ans += a[s + (i - 1) * d] * i;
        }
        return ans;
    } else {
        int e = s + (k - 1) * d;
        ll sum_val = pre_sum[d][e];
        ll mult_val = pre_mult[d][e];
        if (s > d) {
            sum_val -= pre_sum[d][s - d];
            mult_val -= pre_mult[d][s - d];
        }
        ll ans = mult_val - sum_val * (s / d - 1);
        return ans;
    }
}

void TC() {
    int n , q;
    cin >> n >> q;
    a.assign(n + 1, 0);
    pre_sum.assign(SQ, vector<ll>(n + 1, 0));
    pre_mult.assign(SQ, vector<ll>(n + 1, 0));
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    build();
    while(q--){
        int s , d , k;
        cin >> s >> d >> k;
        cout << query(s , d , k) << sp;
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
    ll tc = 1;
     cin >> tc;
    while (tc--)
    {
        TC();
    }

    return 0;
}