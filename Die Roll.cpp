// LINK: https://codeforces.com/problemset/problem/9/A
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define nl '\n'

ll gcd(ll a, ll b) {
    while (b != 0) {
        ll temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

ll gcd_vector(const vector<ll>& vec) {
    ll result = vec[0];
    for (size_t i = 1; i < vec.size(); ++i) {
        result = gcd(result, vec[i]);
        if (result == 1) {
            return 1;
        }
    }
    return result;
}

void TC() {
    int Y, W;
    cin >> Y >> W;
    int mx = max(Y, W);
    int favorable = 6 - mx + 1;
    int g = gcd(favorable, 6);
    cout << favorable / g << "/" << 6 / g << nl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    TC();
}
