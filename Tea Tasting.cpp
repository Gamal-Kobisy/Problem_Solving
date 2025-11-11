// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/contest/1795/problem/C
#pragma GCC optimize("O3")
#pragma GCC optimize ("unroll-loops")
#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
#pragma GCC target("avx2")
using namespace std;
#define ll long long
#define int ll
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
    int n;
    cin >> n;
    vector<int>a(n) , b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[n - 1 - i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[n - 1 - i];
    }
    vector<int>pre(n + 1) , preMul(n + 2) , add(n);
    for (int i = 1; i <= n; ++i) {
        pre[i] += pre[i - 1] + b[i - 1];
    }
    for (int r = 1; r <= n; ++r) {
        int curTea = a[r - 1];
        int lo = 1 , hi = r  + 1, l = r;
        while(lo <= hi){
            int mid = (hi + lo) >> 1;
            int sum = pre[r] - pre[mid - 1];
            if(sum <= curTea){
                l = mid;
                hi = mid - 1;
            }else{
                lo = mid + 1;
            }
        }
        preMul[l]++;
        preMul[r + 1]--;
        if(l > 1)
            add[l - 2] += curTea - (pre[r] - pre[l - 1]);
    }
    for (int i = 1; i <= n; ++i) {
        preMul[i] += preMul[i - 1];
    }
    for (int i = n; i >= 1; --i) {
        cout << preMul[i] * 1ll * b[i - 1] + add[i - 1] << sp;
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

signed main() {
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