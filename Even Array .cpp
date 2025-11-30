// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/problemset/problem/1367/B

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];

        int even_wrong = 0, odd_wrong = 0;
        for (int i = 0; i < n; ++i) {
            if ((i % 2) != (a[i] % 2)) {
                if (i % 2 == 0) ++even_wrong;
                else ++odd_wrong;
            }
        }

        if (even_wrong == odd_wrong) cout << even_wrong << '\n';
        else cout << -1 << '\n';
    }
    return 0;
}
