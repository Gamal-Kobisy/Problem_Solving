// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/problemset/problem/1822/G1
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

ll nPr(int n, int r) {
    ll res = 1;
    for (int i = 0; i < r; i++) {
        res *= (n - i);
    }
    return res;
}

void TC() {
    int n;
    cin >> n;
    map<int , int>freq;
    for (int i = 0; i < n; ++i) {
        int a; cin >> a;
        freq[a]++;
    }
    ll ans = 0;
    for(auto [a , f] : freq){
        if(f == 0) continue;
        if(f >= 3) ans += nPr(f , 3);

        for (int i = 2; 1LL * i * i <= a; ++i) {
            if(a % (i * i) == 0){
                int aj = a / i;
                int ak = a / (i * i);

                auto itAj = freq.find(aj);
                auto itAk = freq.find(ak);

                if(itAj != freq.end() && itAk != freq.end()){
                    ans += 1LL * f * itAj->second * itAk->second;
                }
            }
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