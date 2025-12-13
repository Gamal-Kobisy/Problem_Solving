// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/problemset/problem/1633/D
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

int n , k, b[1001] , c[1001] , Cost[1001];
ll memo[1001][12001];

ll calc(int idx , int rem){
    if(idx == n) return 0;
    ll &ret = memo[idx][rem];
    if(~ret) return ret;
    if(b[idx] == 1){
        ret = calc(idx + 1 , rem) + c[idx];
    }else{
        ll skip = calc(idx + 1 , rem);
        ll pick = 0;
        int cost = Cost[b[idx]];
        if(rem >= cost)
            pick = calc(idx + 1 , rem - cost) + c[idx];
        ret = max(skip , pick);
    }
    return ret;
}

void TC() {
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }
    mem(memo , -1);
    cout << calc(0 , min(k , 12000)) << nl;
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
    mem(Cost , inf);
    Cost[1] = 0;
    int mx = -inf;
    for (int i = 1; i <= 1000; ++i) {
        for (int j = 1;  ; ++j) {
            int k = i + (i / j);
            Cost[k] = min(Cost[k] , Cost[i] + 1);
            if(k == i + 1) break;
        }
    }
    for (int i = 1; i <= 1000; ++i) {
        mx = max(mx , Cost[i]);
    }
//    cout << mx << nl;
// ————————————————————————————————————————————
    ll tc = 1;
    cin >> tc;
    while (tc--)
    {
        TC();
    }

    return 0;
}