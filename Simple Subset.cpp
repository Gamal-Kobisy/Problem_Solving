// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/contest/665/problem/D
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

bool isPrime(int n) {
    // Handle edge cases
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;

    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }

    return true;
}

void solve() {
    ll n , a;
    cin >> n;
    vector<ll>odd{infLL} , even;
    for (ll i = 0; i < n; ++i) {
        cin >> a;
        if(a & 1)
            odd.emplace_back(a);
        else
            even.emplace_back(a);
    }
    sort(all(even));
    sort(all(odd));
    for (ll i = 0; i < odd.size() - 1; ++i) {
        for (ll j = 0; j < even.size(); ++j) {
            if(isPrime(odd[i] + even[j]))
            {
                if(odd[i] == 1)
                {
                    ll ones = count(all(odd) , 1);
                    cout <<  ones + 1 << nl;
                    for (ll k = 0; k < ones; ++k) {
                        cout << 1 << sp;
                    }
                    cout << even[j] << nl;
                }
                else
                {
                    cout << 2 << nl << odd[i] << sp << even[j] << nl;
                }
                return;
            }
        }
        if(odd[i] == 1)
        {
            ll ones = count(all(odd) , 1);
            if(ones < 2)
                continue;
            cout <<  ones  << nl;
            for (ll k = 0; k < ones; ++k) {
                cout << 1 << sp;
            }
            cout << nl;
            return;
        }
    }

    cout << 1 << nl << a << nl;
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
    // cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}