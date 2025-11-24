// LINK: https://codeforces.com/problemset/problem/1829/B
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define nl '\n'

void TC() {
    ll n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    ll maxZero = 0, cur = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == 0) cur++;
        else {
            maxZero = max(maxZero, cur);
            cur = 0;
        }
    }
    maxZero = max(maxZero, cur);
    cout << maxZero << nl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;
    cin >> t;
    while (t--) TC();
}
