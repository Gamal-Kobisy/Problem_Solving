#include <bits/stdc++.h>
#define ll long long
#define nl '\n'
#define all(a) a.begin(),a.end()
#define allr(a) a.rbegin(),a.rend()
#define no cout<<"NO\n";
#define yes cout<<"YES\n";
#define ENG_GAMAL ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

/*
 ███████╗███╗   ██╗ ██████╗       ██████╗  █████╗ ███╗   ███╗ █████╗ ██╗
 ██╔════╝████╗  ██║██╔════╝      ██╔════╝ ██╔══██╗████╗ ████║██╔══██╗██║
 █████╗  ██╔██╗ ██║██║  ███╗     ██║  ███╗███████║██╔████╔██║███████║██║
 ██╔══╝  ██║╚██╗██║██║   ██║     ██║   ██║██╔══██║██║╚██╔╝██║██╔══██║██║
 ███████╗██║ ╚████║╚██████╔╝     ╚██████╔╝██║  ██║██║ ╚═╝ ██║██║  ██║███████╗
 ╚══════╝╚═╝  ╚═══╝ ╚═════╝       ╚═════╝ ╚═╝  ╚═╝╚═╝     ╚═╝╚═╝  ╚═╝╚══════╝
 https://vjudge.net/contest/583343#problem/U
 https://vjudge.net/problem/CodeForces-1526C2
 https://vjudge.net/contest/598172#problem/I
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

const ll N = 1e6;
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
ll gcd(ll a, ll b) {
    while (b != 0) {
        ll temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
ll gcd_Vector(const std::vector<ll>& nums) {
    ll result = nums[0];
    for (size_t i = 1; i < nums.size(); ++i) {
        result = gcd(result, nums[i]);
        if (result == 1) {
            return 1; // GCD is 1, no need to continue
        }
    }
    return result;
}
// ————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

ll cnt_nums_divisible(ll a , ll r)
{
    return r / a;
}

void solve() {
    ll n;
    cin >> n;
    ll n_cpoy = n;
    ll ans = n;
    set<ll>primes;
    while (n != 1)
    {
        primes.insert(spf[n]);
        ll Spf = spf[n];
        while (n % Spf == 0)
        {
            n /= Spf;
        }
    }
    for (auto &i: primes) {
        ans -= ans / i;
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
    cin >> t;
    while(t--)
    {
        solve();
    }

    return 0;
}