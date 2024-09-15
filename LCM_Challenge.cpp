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
// ————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

const ll N = 1e6;
vector<ll> spf(N + 1);  // Initialize a vector to store SPF for each number
vector<ll> primes;      // Initialize a vector to store prime numbers

void SPF(ll n = N) {
    for (ll i = 1; i <= n; ++i) {
        spf[i] = i;  // Initialize SPF as the number itself
    }

    for (ll i = 2; i * i <= n; ++i) {
        if (spf[i] == i) {  // i is a prime number
            primes.push_back(i);  // Add i to the list of primes
            for (ll j = i * i; j <= n; j += i) {
                if (spf[j] == j) {
                    spf[j] = i;  // Update SPF[j] to the smallest prime factor
                }
            }
        }
    }

    // Collect remaining prime numbers greater than sqrt(n)
    for (ll i = sqrt(n) + 1; i <= n; ++i) {
        if (spf[i] == i) {  // i is a prime number
            primes.push_back(i);  // Add i to the list of primes
        }
    }
}

int64_t gcd(ll a, ll b) {
    while (b != 0) {
        ll temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int64_t lcm(ll a, ll b) {
    return std::abs(a * b) / gcd(a, b);
}

ll lcm_Vector(const std::vector<ll>& nums) {
    ll result = nums[0];
    for (size_t i = 1; i < nums.size(); ++i) {
        result = lcm(result, nums[i]);
    }
    return result;
}

ll not_divisible(ll x , map<ll,ll>divs)
{
    bool ok = false;
    while (!ok)
    {
        bool is_divisible = false;
        for (auto &d: divs) {
            if(x % d.first == 0)
            {
                is_divisible = true;
                break;
            }
        }
        if(!is_divisible)
        {
            ok = true;
        }
        else
        {
            x--;
        }
    }
    return x;
}
void solve() {
    ll n;
    cin >> n;
    if(n <= 2)
    {
        cout << n << nl;
        return;
    }
    int64_t ans = lcm(n , lcm(n - 1 , n - 2));
    for (ll i = n; i > n - 2 ; --i) {
        map<ll,ll>divs;
        ll x = i;
        while (x != 1)
        {
            divs[spf[x]]++;
            x /= spf[x];
        }
        ll frst = not_divisible(n - 1 , divs);
        x = frst;
        while (x != 1)
        {
            divs[spf[x]]++;
            x /= spf[x];
        }
        ll scnd = not_divisible(frst - 1 , divs);
//        cout << i << ' ' << frst << ' ' << scnd << " -> " << lcm(i , lcm(frst , scnd)) << nl;
        ans = max(ans , lcm(i , lcm(frst , scnd)));
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