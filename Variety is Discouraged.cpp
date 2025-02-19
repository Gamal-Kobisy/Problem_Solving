// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/contest/2064/problem/B
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
    ll n;
    cin >> n;
    vector<ll>a(n) , dist(n);
    map<ll , ll>freq;
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
        freq[a[i]]++;
    }
    pair<ll , ll>ans = {-1 , -1};
    ll maxi = 0;
    for (ll i = 0; i < n; ++i) {
        if(freq[a[i]] == 1)
        {
            int j = i + 1;
            ll sz = 1;
            while (freq[a[j]] == 1 && j< n)
            {
                sz++ , j++;
            }
            if(sz > maxi)
                ans = {i + 1 , j} , maxi = sz;
            i = j;
        }
    }
    if(ans.first + ans.second == -2)
        return void(cout << 0 << nl);
    cout << ans.first << sp << ans.second << nl;
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