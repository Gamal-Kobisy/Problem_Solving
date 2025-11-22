// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/problemset/problem/1843/E
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

void TC() {
    int n , m;
    cin >> n >> m;
    vector<pii>a(m);
    for (int i = 0; i < m; ++i) {
        int l , r;
        cin >> l >> r;
        a[i] = {l , r};
    }
    sort(all(a));
    int q;
    cin >> q;
    vector<int>x(q + 1);
    for (int i = 0; i < q; ++i) {
        cin >> x[i + 1];
    }

    int lo = 1 , hi = q , ans = -1;
    while(lo <= hi){
        int mid = (lo + hi) >> 1;
        vector<int>pre(n + 1);
        for (int i = 1; i <= mid; ++i) {
            pre[x[i]]++;
        }
        for (int i = 1; i <= n; ++i) {
            pre[i] += pre[i - 1];
        }
        bool ok = false;
        for (int i = 0; i < m; ++i) {
            int l = a[i].fi , r = a[i].se;
            if(pre[r] - pre[l - 1] > (r - l + 1) / 2){
                ok = true;
                break;
            }
        }
        if(ok){
            ans = mid;
            hi = mid - 1;
        }else{
            lo = mid + 1;
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