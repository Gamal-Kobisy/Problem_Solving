 // "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/contest/2090/problem/B

#include <bits/stdc++.h>
#define ll long long
#define nl '\n'
#define sp ' '
#define all(a) a.begin(),a.end()
#define allr(a) a.rbegin(),a.rend()
#define no cout<<"NO\n"
#define yes cout<<"YES\n"
#define ENG_GAMAL ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;
ll infLL = 0x3f3f3f3f3f3f3f3f , inf = 0x3f3f3f3f;
// ————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————


void solve() {
    int n , m;
    cin >> n >> m;
    vector<string> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < m; ++j) {
            if (v[i][j] == '0')
                continue;
            char up = v[i - 1][j];
            char left = v[i][j - 1];
            if (left != '1' && up != '1')
                return void(no);
        }
    }
    yes;
}

void file() {
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
    ll t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
