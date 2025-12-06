// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/problemset/problem/2006/A
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
// ————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
const int N = 2e5 + 5, M = 1e3, LOG = 20, inf = 0x3f3f3f3f;
ll infLL = 0x3f3f3f3f3f3f3f3f;

void TC() {
    int n;
    cin >> n;
    vector<int> deg(n+1,0);
    for (int i = 0; i < n-1; ++i) {
        int u,v;
        cin >> u >> v;
        deg[u]++; deg[v]++;
    }
    string s;
    cin >> s;
    int cnt0 = 0, cnt1 = 0, cntq = 0;
    int inner_q = 0;
    for (int i = 1; i <= n; ++i) {
        bool isLeaf = (i != 1 && deg[i] == 1);
        char c = s[i-1];
        if (isLeaf) {
            if (c == '0') cnt0++;
            else if (c == '1') cnt1++;
            else cntq++;
        } else {
            if (i == 1) continue;
            if (c == '?') inner_q++;
        }
    }
    char root = s[0];
    int ans = 0;
    if (root == '0' || root == '1') {
        int inv = (root == '0') ? cnt1 : cnt0;
        ans = inv + (cntq + 1) / 2;
    } else {
        if (cnt0 > cnt1) {
            ans = cnt0 + (cntq / 2);
        }
        else if (cnt1 > cnt0) {
            ans = cnt1 + (cntq / 2);
        }
        else {
            ans = cnt0 + (cntq + (inner_q % 2)) / 2;
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