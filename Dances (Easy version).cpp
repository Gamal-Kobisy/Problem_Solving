// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/problemset/problem/1883/G1
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
    int n , m;
    cin >> n >> m;
    vector<int>a(n , 1) , b(n);
    for (int i = 1; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    sort(allr(b));
    vector<int> temp = a;
    sort(allr(temp));
    int init = 0 , idx = 0;
    for (int i = 0; i < n; ++i) {
        if(temp[i] >=  b[idx]) continue;
        init++;
        idx++;
    }
//    cout << init << nl;
    int lo = 1 , hi = m , flib;
    while(lo <= hi){
        int md = (lo + hi) / 2;
        temp = a;
        temp[0] = md;
        sort(allr(temp));
        int cnt = 0;
        idx = 0;
        for (int i = 0; i < n; ++i) {
            if(temp[i] >=  b[idx]) continue;
            cnt++;
            idx++;
        }
        if(cnt == init){
            flib = md;
            lo = md + 1;
        }else{
            hi = md - 1;
        }
    }
//    cout << flib << nl;
    ll ans = 1ll * flib * (n - init) + 1ll * (m - flib) * (n - init + 1);
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