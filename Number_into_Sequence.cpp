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

const ll N = 1e7;
vector<bool> isPrime(N + 1, true);  // Initialize a boolean vector
vector<ll> primes;
void Sieve(ll n = N) {
    isPrime[0] = isPrime[1] = false;  // 0 and 1 are not primes

    for (ll i = 2; i * i <= n; ++i) {
        if (isPrime[i]) {
            for (ll j = i * i; j <= n; j += i) {
                isPrime[j] = false;  // Mark multiples of i as non-prime
            }
        }
    }
    for (ll i = 2; i <= n; ++i) {
        if (isPrime[i]) {
            primes.push_back(i);  // Collect all prime numbers
        }
    }
}

bool isprime(ll n) {
    if (n <= 3) return true;         // 2 and 3 are prime numbers
    if (n % 2 == 0 || n % 3 == 0) return false; // Multiple of 2 or 3 are not prime
    // Check factors from 5 to sqrt(n)
    for (ll i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}
// ————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void solve() {
    ll n;
    cin >> n;
    if(isprime(n))
    {
        cout << 1 << nl << n << nl;
        return;
    }
    map<ll , ll>divs;
    ll n_copy = n;
    while (n_copy != 1)
    {
        if(isprime(n_copy))
        {
            divs[n_copy]++;
            n_copy = 1;
            break;
        }
        for(ll i : primes)
        {
            while (n_copy % i == 0)
            {
                divs[i]++;
                n_copy /= i;
            }
            if(i > n_copy)
            {
                break;
            }
        }
    }
    pair<ll , ll> most_freq_div = {0 , 0};
    for (auto &i: divs) {
        if(i.second > most_freq_div.second)
        {
            most_freq_div = i;
        }
    }
    cout << most_freq_div.second << nl;
    for (ll i = 1; i < most_freq_div.second; ++i) {
        cout << most_freq_div.first << ' ';
        n /= most_freq_div.first;
    }
    cout << n << nl;
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
    Sieve();
// ————————————————————————————————————————————
    ll t = 1;
    cin >> t;
    while(t--)
    {
        solve();
    }

    return 0;
}