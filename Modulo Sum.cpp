// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/problemset/problem/577/B
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
const int N = 1e3 + 5, M = 1e3, LOG = 20, inf = 0x3f3f3f3f;
ll infLL = 0x3f3f3f3f3f3f3f3f;

int n , m , a[N] , dp[N][N];

int calc(int idx , int mod)
{
    if(mod == 0)
    {
        yes;
        exit(0);
    }
    if(idx >= n)
        return false;
    int &ret = dp[idx][mod];
    if(~ret)
        return ret;
    ret = false;
    ret |= calc(idx + 1 , (a[idx+1] + mod) % m);
    ret |= calc(idx + 1 , mod);
    return ret;
}

void solve() {
    cin >> n >> m;
    if(n > m)
        return void(yes);
    memset(dp , -1 , sizeof dp);
    for (int i = 0; i < n; ++i) {
        cin >> a[i + 1];
    }
    calc(0 , m);
    no;
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
//     cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}