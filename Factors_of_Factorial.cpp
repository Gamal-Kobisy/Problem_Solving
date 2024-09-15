#include <bits/stdc++.h>
#define ll long long
#define nl '\n'
#define all(a) a.begin(),a.end()
#define allr(a) a.rbegin(),a.rend()
#define no cout<<"NO\n";
#define yes cout<<"YES\n";
#define ENG_GAMAL ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;
const ll MOD = 1e9 + 7;

/*
 ███████╗███╗   ██╗ ██████╗       ██████╗  █████╗ ███╗   ███╗ █████╗ ██╗
 ██╔════╝████╗  ██║██╔════╝      ██╔════╝ ██╔══██╗████╗ ████║██╔══██╗██║
 █████╗  ██╔██╗ ██║██║  ███╗     ██║  ███╗███████║██╔████╔██║███████║██║
 ██╔══╝  ██║╚██╗██║██║   ██║     ██║   ██║██╔══██║██║╚██╔╝██║██╔══██║██║
 ███████╗██║ ╚████║╚██████╔╝     ╚██████╔╝██║  ██║██║ ╚═╝ ██║██║  ██║███████╗
 ╚══════╝╚═╝  ╚═══╝ ╚═════╝       ╚═════╝ ╚═╝  ╚═╝╚═╝     ╚═╝╚═╝  ╚═╝╚══════╝
*/
template <typename T>
void get_vec(vector<T>& v) {
    for (ll i = 0; i < v.size(); ++i) {
        cin >> v[i];
    }
}
template <typename T>
void out_vec(vector<T>& v) {
    for (ll i = 0; i < v.size(); ++i) {
        cout << v[i] << ' ';
    }
    cout << nl;
}
const ll N = 1000;
vector<ll> spf(N + 1);  // Initialize a vector to store SPF for each number
void SPF(ll n = N) {
    for (ll i = 1; i <= n; ++i) {
        spf[i] = i;  // Initialize SPF as the number itself
    }

    for (ll i = 2; i * i <= n; ++i) {
        if (spf[i] == i) {  // i is a prime number
            for (ll j = i * i; j <= n; j += i) {
                if (spf[j] == j) {
                    spf[j] = i;  // Update SPF[j] to the smallest prime factor
                }
            }
        }
    }
}

// ————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void solve() {
    int n;
    cin >> n;
    map<int , int>divs;
    for (int i = 2; i <= n; ++i) {
        int cnt = 0 , j = i;
        while (j != 1)
        {
            divs[spf[j]]++;
            j /= spf[j];
        }
    }
    ll ans = 1;
    for (auto &i: divs) {
        ans *= (i.second + 1) % MOD;
        ans %= MOD;
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
    SPF();
// ————————————————————————————————————————————
    ll t = 1;
//    cin >> t;
    while(t--)
    {
        solve();
    }

    return 0;
}