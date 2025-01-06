// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/problemset/problem/2048/C
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
    int zero = find(all(s) , '0') - s.begin();
    int sec_size = max(1 , (int)s.size() - zero);
    string maxi = string(sec_size , '0');
    pair<int , int> ans = {1 , 1};
    for (ll i = 0; i < s.size() - sec_size + 1; ++i) {
        string sec = s.substr(i , sec_size);
        string result ;
        for (ll j = sec_size - 1; j >= 0; --j) {
            if(sec[j] != s[zero + j])
                result.push_back('1');
            else
                result.push_back('0');
        }
        reverse(all(result));
        if(result >= maxi)
            maxi = result , ans = {i + 1 , i + sec_size};

    }
    cout << 1 << sp << s.size() << sp << ans.first << sp << ans.second << nl;
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