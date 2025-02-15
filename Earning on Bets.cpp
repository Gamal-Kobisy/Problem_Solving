// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/contest/1979/problem/C
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

ll gcd(ll a, ll b) {
    while (b != 0) {
        ll temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

ll lcm(ll a, ll b) {
    return abs(a * b) / gcd(a, b);
}

ll lcm_Vector(vector<ll>& nums) {
    ll result = nums[0];
    for (size_t i = 1; i < nums.size(); ++i) {
        result = lcm(result, nums[i]);
    }
    return result;
}

void solve() {
    int n;
    cin >> n;
    vector<ll>a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }
    ll LCM = lcm_Vector(a) , sum = 0;
    for (ll i = 0; i < n; ++i) {
        sum += LCM / a[i];
    }
    if(sum >= LCM)
        return void(cout << -1 << nl);
    for (ll i = 0; i < n; ++i) {
        cout << LCM / a[i] << sp;
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