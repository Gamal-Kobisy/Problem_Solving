// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/problemset/problem/1893/B
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

void TC() {
    int n , m;
    cin >> n >> m;
    vector<int> b(m) , a(n);
    vector<pii>v;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        v.pb({a[i] , -i});
    }
    sort(all(v));
    vector<int>put[n + 1];
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }
    sort(allr(b));
    vector<int>greater;
    for (int i = 0; i < m; ++i) {
        auto it = lower_bound(all(v) , make_pair(b[i] , -inf));
        if(it == v.end())
            greater.pb(b[i]);
        else{
            int idx = -it->second;
            put[idx].pb(b[i]);
        }

    }
    for(int i : greater) cout << i << sp;
    for (int i = 0; i < n; ++i) {
        cout << a[i] << sp;
        for(int j : put[i]) cout << j << sp;
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