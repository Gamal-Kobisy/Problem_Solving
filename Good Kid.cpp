// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/problemset/problem/1873/B

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];

        ll ans = 0;
        for (int i = 0; i < n; ++i) {
            ll prod = 1;
            for (int j = 0; j < n; ++j) {
                if (i == j) prod *= (a[j] + 1);
                else prod *= a[j];
            }
            ans = max(ans, prod);
        }
        cout << ans << '\n';
    }
    return 0;
}
