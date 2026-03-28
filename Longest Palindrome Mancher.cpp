// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://cses.fi/problemset/task/1111/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define PI acos(-1)
#define Ones(n) __builtin_popcountll(n)
#define MSB(n) (63 - __builtin_clzll(n))
#define LSB(n) (__builtin_ctzll(n))
#define mem(arrr, xx) memset(arrr,xx,sizeof arrr)
#define fr first
#define sc second
#define pb push_back
#define all(a) a.begin(),a.end()
#define allr(a) a.rbegin(),a.rend()
#define no cout<<"NO\n"
#define yes cout<<"YES\n"
#define imp cout<<"IMPOSSIBLE\n"
#define nl '\n'
#define sp ' '
#define ENG_GAMAL ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;
// ————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
const int N = 2e5 + 5, M = 1e3, LOG = 20, inf = 0x3f3f3f3f;
ll infLL = 0x3f3f3f3f3f3f3f3f;

void manacher(string &s,vector<int>&odd,vector<int>&even) {
    int n = s.size();
    odd.resize(n);
    for (int i = 0, l = 0, r = -1; i < n; i++) {
        odd[i] = (i <= r) ? (min(odd[r - i + l], r - i + 1)) : 1;
        while (i + odd[i] < n && i - odd[i] >= 0 && s[i + odd[i]] == s[i - odd[i]])
            odd[i]++;
//        ans = max(ans, 2 * odd[i] - 1);
        if (i + odd[i] - 1 > r) {
            r = i + odd[i] - 1;
            l = i - odd[i] + 1;
        }
    }
    even.resize(n);
    for (int i = 0, l = 0, r = -1; i < n; i++) {
        even[i] = (i <= r) ? (min(even[r - i + l + 1], r - i + 1)) : 0;
        while (i + even[i] < n && i - even[i] - 1 >= 0 && s[i + even[i]] == s[i - even[i] - 1])
            even[i]++;
//        ans = max(ans, 2 * even[i]);
        if (i + even[i] - 1 > r) {
            r = i + even[i] - 1;
            l = i - even[i];
        }
    }
}


void TC() {
    string s;
    cin >> s;
    vector<int>odd , even;
    manacher(s , odd , even);
    pii ans = {1 , 0};
    for (int i = 0; i < s.size(); ++i) {
        ans = max(ans ,{2 * odd[i] - 1 , i - odd[i] + 1});
        ans = max(ans ,{2 * even[i] , i - even[i]});
    }
    cout << s.substr(ans.sc , ans.fr) << nl;
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
    ll tc = 1;
//     cin >> tc;
    while (tc--)
    {
        TC();
    }

    return 0;
}