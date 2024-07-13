//
// DATE : Created by Gamal on 6/27/2024.
// LINK : https://vjudge.net/contest/589623#problem/AH

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <variant>

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
using ordered_set = tree<T, null_type, un_ordered, rb_tree_tag, tree_order_statistics_node_update>;

void solve() {
    ll n, q;
    cin >> n >> q;
    multiset<ll>s;
    vector<ll> candies(n) , pre(n+1);
    for (ll i = 0; i < n; ++i) {
        cin >> candies[i];
        s.insert(candies[i]);
    }
    auto it = s.end();
    it--;
    for (ll i = 0; i < n; ++i) {
        pre[i+1] = pre[i] + *it;
        it--;
    }
    while (q--)
    {
        ll x;
        cin >> x;
        ll l = 0 , r = n , ans = LLONG_MAX;
        if(pre[n] < x)
        {
            cout << -1 << nl;
            continue;
        }

        while (l <= r)
        {
            ll mid = (l + r) / 2;
            ll sugar = pre[mid];
            if(sugar >= x)
            {
                ans = min(ans , mid);
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        cout << ans  << nl;
    }
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
    cin >> t;
    while(t--)
    {
        solve();
    }

    return 0;
}
