// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/problemset/problem/492/A

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    if (!(cin >> n)) return 0;
    int height = 0;
    for (ll k = 1; ; ++k) {
        ll need = k * (k + 1) / 2; // cubes needed for level k
        if (n >= need) {
            n -= need;
            ++height;
        } else break;
    }
    cout << height << '\n';
    return 0;
}
