// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/contest/2107/problem/C
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
    ll n , k;
    string s;
    cin >> n >> k >> s;
    vector<ll> a(n);
    ll sum = 0 , maxi = 0 , zero = -1;
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
        if(s[i] == '0')
            a[i] = -1e18 , zero = i;
        sum += a[i];
        maxi = max(maxi , sum);
        sum = max(sum , 0ll);
    }
    if(maxi > k || (zero == -1 && maxi != k))
        return void(no);
    if(zero == -1 && maxi == k)
    {
        yes;
        for (int i = 0; i < n; ++i) {
            cout << a[i] << sp;
        }
        cout << nl;
        return;
    }
    ll pre = 0 , suf = 0;
    sum = 0;
    for (ll i = zero + 1; i < n; ++i) {
        if(s[i] == '0')
            break;
        sum += a[i];
        pre = max(sum , pre);
    }
    sum = 0;
    for (ll i = zero - 1; ~i; --i) {
        if(s[i] == '0')
            break;
        sum += a[i];
        suf = max(sum , suf);
    }
    a[zero] = k - pre - suf;
    yes;
    for (int i = 0; i < n; ++i) {
        cout << a[i] << sp;
    }
    cout << nl;
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