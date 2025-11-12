// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/problemset/problem/996/A
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#pragma GCC target("avx2")
using namespace std;
#define ll long long
#define nl '\n'
#define ENG_GAMAL ios::sync_with_stdio(false); cin.tie(nullptr)

void TC(){
    ll n;
    cin >> n;
    ll bills[] = {100, 20, 10, 5, 1};
    ll count = 0;
    for (ll b : bills) {
        count += n / b;
        n %= b;
    }
    cout << count << nl;
}

int main(){
    ENG_GAMAL;
    TC();
    return 0;
}
