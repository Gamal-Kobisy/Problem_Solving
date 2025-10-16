// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/contest/2160/problem/C
#include <bits/stdc++.h>
#define ll long long
#define nl '\n'
#define sp ' '
#define all(a) a.begin(),a.end()
#define allr(a) a.rbegin(),a.rend()
#define NO cout<<"NO\n"
#define YES cout<<"YES\n"
#define imp cout<<"IMPOSSIBLE\n"
#define ENG_GAMAL ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;
// ————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
const int N = 2e5 + 5, M = 1e3, LOG = 20, inf = 0x3f3f3f3f;
ll infLL = 0x3f3f3f3f3f3f3f3f;

// renamed helper: check if the lower `len` bits of value form a binary palindrome
bool check_pal(int value, int len) {
    for (int i = 0; i < len / 2; ++i) {
        int bit_left  = (value >> i) & 1;
        int bit_right = (value >> (len - 1 - i)) & 1;
        if (bit_left != bit_right) return false;
    }
    return true;
}


void solve() {
    int n;
    cin >> n;
    if (n == 0) {
        YES;
        return;
    }

    int tz = __builtin_ctz(n);
    int hz = 31 - __builtin_clz(n);
    int mid_bits = n >> tz;
    int mid_len  = hz - tz + 1;
    if (!check_pal(mid_bits, mid_len)) {
        NO;
        return;
    }

    if (mid_len % 2 != 0) {
        int middle = (mid_bits >> (mid_len / 2)) & 1;
        if (middle == 1) {
            NO;
            return;
        }
    }
    YES;
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
// test-independent code ——————————————————————
// ————————————————————————————————————————————
    ll t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}