// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/problemset/problem/151/A
#pragma GCC optimize("O3")
#pragma GCC optimize ("unroll-loops")
#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
#pragma GCC target("avx2")
using namespace std;
#define ll long long
#define nl '\n'
#define ENG_GAMAL ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

void TC() {
    ll n,k,l,c,d,p,nl_s,np_s;
    cin >> n >> k >> l >> c >> d >> p >> nl_s >> np_s;
    ll t1 = k * l / nl_s;
    ll t2 = c * d;
    ll t3 = p / np_s;
    cout << min({t1,t2,t3}) / n << nl;
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
    ll tc = 1;
    while (tc--)
    {
        TC();
    }
    return 0;
}
