// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/problemset/problem/2094/H
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
const int N = 1e5 + 5, M = 1e3, LOG = 20, inf = 0x3f3f3f3f;
ll infLL = 0x3f3f3f3f3f3f3f3f;
vector<int>divs[N];
vector<int>pos[N];
void TC() {
    int n, q;
    cin >> n >>q;
    vector<int>a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        pos[a[i]].pb(i);
    }
    while(q--){
        int k , l , r;
        cin >> k >> l >> r;
        ll ans = 0;
        int idx = l - 1;
        int curK = k;
        while(idx < r){
            vector<int>ids;
            for(int d : divs[curK]){
                if(pos[d].empty()) continue;
                auto it = lower_bound(all(pos[d]), idx);
                if(it != pos[d].end() and *it < r) ids.pb(*it);
            }
            if(ids.empty()){
                ans += 1ll * curK * (r - idx);
                break;
            }
            sort(all(ids));
            int next_idx = ids.front();
            ans += 1ll * curK * (next_idx - idx);
            while((curK % a[next_idx]) == 0)
                curK /= a[next_idx];
            ans += curK;
            idx = next_idx + 1;
            if(curK == 1){
                ans += 1ll * curK * (r - idx);
                break;
            }
        }
        cout << ans << nl;
    }
    for(int i : a) pos[i].clear();
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
    for (int i = 1; i < N; ++i) {
        for (int j = i; j < N; j += i) {
            divs[j].pb(i);
        }
    }
// ————————————————————————————————————————————
    ll tc = 1;
     cin >> tc;
    while (tc--)
    {
        TC();
    }

    return 0;
}