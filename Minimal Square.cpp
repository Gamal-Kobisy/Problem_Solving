// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/problemset/problem/1360/A

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        ll a, b;
        cin >> a >> b;
        ll s1 = max(2*a, b);
        ll s2 = max(2*b, a);
        ll s3 = a + b;
        ll side = min({s1, s2, s3});
        cout << side * side << '\n';
    }
    return 0;
}
