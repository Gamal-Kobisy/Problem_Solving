//
// DATE : Created by Gamal on 7/1/2024.
// LINK :https://vjudge.net/contest/589623#problem/N

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
using ordered_set = tree<T, null_type, un_ordered, rb_tree_tag, tree_order_statistics_node_update>;
ll me_score(multiset<ll>ms , ll n)
{
    auto it = ms.begin();
    ll stages = ceil(n * 0.75);
    ll unscored_stages = floor(n * 0.25);
    ll sum = 0;
    for (ll i = 1; i <= n; ++i) {
        if(i <= unscored_stages)
        {
            it++;
            continue;
        }
        sum += *it;
        it++;
    }
    return sum;
}

ll ilya_score(multiset<ll>ms , ll n)
{
    auto it = ms.rbegin();
    ll stages = ceil(n * 0.75);
    ll sum = 0;
    for (ll i = 1; i <= stages; ++i) {
        sum += *it;
        it++;
    }
    return sum;
}
void solve()
{
    ll n;
    cin >> n;
    multiset<ll>me;
    multiset<ll>ilya;
    for (int i = 0; i < n; ++i) {
        ilya.insert(0);
        me.insert(100);
    }
    for (ll i = 0; i < n; ++i) {
        ll x;
        cin >> x;
        me.insert(x);
    }
    for (ll i = 0; i < n; ++i) {
        ll x;
        cin >> x;
        ilya.insert(x);
    }
    ll l = 0 , r = n , ans ;
    while (l <= r)
    {
        ll mid = (r + l) / 2;
        if(me_score(me , n + mid) >= ilya_score(ilya , n + mid))
        {
            ans = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
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
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}
