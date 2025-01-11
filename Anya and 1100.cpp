// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/problemset/problem/2036/C
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
// ————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
const int N = 2e5 + 5, M = 1e3, LOG = 20, inf = 0x3f3f3f3f;
ll infLL = 0x3f3f3f3f3f3f3f3f;
string s;

bool is_chain(int i)
{
    return (i >= 0 && i + 3 < s.size() && s[i] == '1' && s[i + 1] == '1' && s[i + 2] == '0' && s[i + 3] == '0');
}

void solve() {
    cin >> s;
    int chains = 0;
    for (ll i = 0; i < s.size() - 3; ++i) {
        if(is_chain(i))
            chains++;
    }
    int q;
    cin >> q;
    for (ll j = 0; j < q; ++j) {
        int i , val;
        cin >> i >> val;
        i--;
        if (s[i] != '0' + val) {
            bool before = is_chain(i - 3) || is_chain(i - 2) || is_chain(i - 1) || is_chain(i);
            s[i] = '0' + val;
            bool after = is_chain(i - 3) || is_chain(i - 2) || is_chain(i - 1) || is_chain(i);
            chains += after - before;
        }
        (chains ? yes : no);
    }

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