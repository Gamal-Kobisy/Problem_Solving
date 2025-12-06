// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/problemset/problem/1778/C
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

ll sum(ll n){
    return n * (n + 1) / 2;
}

void TC() {
    int n , k;
    cin >> n >> k;
    string a , b;
    cin >> a >> b;
    map<char , int>freq;
    for (int i = 0; i < n; ++i) {
        freq[a[i]]++;
    }
    vector<char>idx;
    for(auto [c , f] : freq){
        idx.pb(c);
    }
    int dist = idx.size();
    ll ans = 0;
    for (int i = 0; i < (1 << dist); ++i) {
        if(Ones(i) > k) continue;
        vector<bool>pass(26 , false);
        for (int j = 0; j < dist; ++j) {
            if((1 << j) & i) pass[idx[j] - 'a'] = true;
        }
        ll cand = 0 , cnt = 0;
        for (int j = 0; j < n; ++j) {
            if(a[j] == b[j] or pass[a[j] - 'a']) cnt++;
            else{
                cand += sum(cnt);
                cnt = 0;
            }
        }
        ans = max(ans , cand + sum(cnt));
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