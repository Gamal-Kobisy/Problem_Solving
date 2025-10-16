// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://atcoder.jp/contests/abc276/tasks/abc276_d?lang=en
#include <bits/stdc++.h>
#define ll long long
#define nl '\n'
#define sp ' '
#define all(a) a.begin(),a.end()
#define allr(a) a.rbegin(),a.rend()
#define no cout<<"NO\n"
#define yes cout<<"YES\n"
#define imp cout<<"IMPOSSIBLE\n"
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

ll gcd_vector(const vector<int>& vec) {
    ll result = vec[0];
    for (size_t i = 1; i < vec.size(); ++i) {
        result = gcd(result, vec[i]);
        if (result == 1) {
            return 1;
        }
    }
    return result;
}

void solve() {
    int n;
    cin >> n;
    vector<int>a(n);
    for(int i = 0 ; i < n ; i++) {
        cin >> a[i];
    }
    int GCD = gcd_vector(a);
    int twos = 0 , threes = 0;
    int c = GCD;
    while(c % 2 == 0)
        c /= 2 , twos++;
    while(c % 3 == 0)
        c /= 3 , threes++;
    ll ans = 0;
    for(int i = 0 ; i < n ; i++){
        int c2 = 0 , c3 = 0;
        while(a[i] % 2 == 0)
            a[i] /= 2 , c2++;
        while(a[i] % 3 == 0)
            a[i] /= 3 , c3++;
        if(c2 < twos or c3 < threes){
            ans = -1;
            break;
        }
        else{
            a[i] *= powl(2 , twos);
            a[i] *= powl(3 , threes);
        }
        if(a[i] != GCD){
            ans = -1;
            break;
        }
        else{
            ans += c2 - twos;
            ans += c3 - threes;
        }
    }
    cout << ans << nl;
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
//     cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}