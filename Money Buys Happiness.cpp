// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/problemset/problem/1974/E
#pragma GCC optimize("O3")
#pragma GCC optimize ("unroll-loops")
#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
#pragma GCC target("avx2")
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
vector<vector<ll>>memo;
vector<pii>a;
ll m , x;

ll solve(int idx , int hap){
    if(hap <= 0) return 0;
    if(idx < 0) return infLL;
    ll &ret = memo[idx][hap];
    if(~ret) return ret;
    ret = solve(idx - 1 , hap);
    ll take = solve(idx - 1, hap - a[idx].se) + a[idx].fi;
    if (take <= idx * x) {
        ret = min(ret, take);
    }
    return ret;
};
void TC() {
    cin >> m >> x;
    a = vector<pii>(m);
    int sum = 0;
    for (int i = 0; i < m; ++i) {
        cin >> a[i].fi >> a[i].se;
        sum += a[i].se;
    }
    const int SumMax = min(sum , (int)1e5);
    memo = vector<vector<ll>>(m , vector<ll>(SumMax + 1 , -1));

    for (int i = SumMax; i >= 0; --i) {
        if(solve(m - 1 , i) <= (m - 1) * x){
            cout << i << nl;
            break;
        }
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
    ll tc = 1;
    cin >> tc;
    while (tc--)
    {
        TC();
    }

    return 0;
}