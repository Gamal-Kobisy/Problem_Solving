// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/contest/2069/problem/D
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

void solve() {
    string s;
    cin >> s;
    int i = 0 , n = s.size();
    while (i <= n / 2 && s[i] == s[n - i - 1])
        i++;
    n -= i * 2;
    s = s.substr(i , n);
    int ans[2] = {0 , 0};
    for (ll j = 0; j < 2; ++j) {
        int l = 0 , r = n;
        while (l <= r)
        {
            int mid = (r + l) / 2;
            vector<int>freq(26);
            for (ll i = 0 ; i < mid; ++i) {
                freq[s[i] - 'a']++;
            }
            bool ok = true;
            for (ll i = 0; i < min(n / 2, n - mid); ++i) {
                char c = s[s.size() - i - 1];
                if (i < mid)
                {
                    ok &= freq[c - 'a'] > 0;
                    freq[c - 'a']--;
                }
                else
                {
                    ok &= (c == s[i]);
                }
            }
            for (ll i = 0; i < 26; ++i) {
                ok &= (freq[i] % 2 == 0);
            }
            if(ok)
            {
                r = mid - 1;
                ans[j] = mid;
            }
            else
            {
                l = mid + 1;
            }
        }
        reverse(all(s));
    }
    cout << min(ans[0] , ans[1]) << nl;
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