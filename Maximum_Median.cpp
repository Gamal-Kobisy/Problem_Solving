//
// DATE : Created by Gamal on 7/8/2024.
// LINK : https://vjudge.net/contest/589623#problem/W

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define nl '\n'
#define all(a) a.begin(),a.end()
#define allr(a) a.rbegin(),a.rend()
#define f1(n) for(int i=1;i<n;i++)
#define f0(n) for(int i=0;i<n;++i)
#define fe(v) for(auto & it:v)
#define pi 3.141592653589793238462643383279502884197
#define e 2.718281828459045
using namespace std;
using namespace __gnu_pbds;
struct un_ordered
{
    bool operator()(const long long &a, const long long &b) const
    {
        return true;
    }
};
long long gcd(long long a, long long b) {
    while (b != 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

long long lcm(long long a, long long b) {
    return a / gcd(a, b) * b;  // Use the GCD to calculate the LCM
}

template <class T>
using ordered_set = tree<T, null_type, less_equal<>, rb_tree_tag, tree_order_statistics_node_update>;

void solve()
{
    ll n , k;
    cin >> n >> k;
    multiset<ll>ms;
    ll maxx = LLONG_MIN;
    for (ll i = 0; i < n; ++i) {
        ll x;
        cin >> x;
        maxx = max(maxx , x);
        ms.insert(x);
    }
    for (int i = 0; i < n / 2; ++i) {
        ms.erase(ms.begin());
    }
    ll l = *ms.begin() , r = maxx + k , ans ;
    while (l <= r)
    {
        ll mid = (r + l) / 2 , k_copy = k;
        bool ok = true;
        for(ll i : ms)
        {
            if(i >= mid)
            {
                continue;
            }
            if(i + k_copy >= mid)
            {
                k_copy -= (mid - i);
            }
            else
            {
                ok = false;
                break;
            }
        }
        if(ok)
        {
            l = mid + 1;
            ans = mid;
        }
        else
        {
            r = mid - 1;
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
void fast()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

}
int main() {
    file();
    fast();
    ll t = 1;
    // cin >> t;
    while(t--)
    {
        solve();
    }

    return 0;
}
