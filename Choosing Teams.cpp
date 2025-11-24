// LINK: https://codeforces.com/problemset/problem/432/A
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define nl '\n'

void TC() {
    ll n, k;
    cin >> n >> k;
    vector<ll> y(n);
    ll eligible = 0;
    for (int i = 0; i < n; i++) {
        cin >> y[i];
        if (y[i] + k <= 5) eligible++;
    }
    cout << eligible / 3 << nl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    TC();
}
