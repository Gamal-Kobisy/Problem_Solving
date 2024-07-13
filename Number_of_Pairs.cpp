//
// DATE : Created by Gamal on 7/8/2024.
// LINK : https://vjudge.net/contest/589623#problem/S

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

void solve()
{
    ll  n , l , r;
    cin >> n >> l >> r;
    vector<ll>nums(n);
    for (ll i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    sort(all(nums));
    ll ans = 0;
    for (int i = 0; i < n - 1; ++i) {
        ans +=  upper_bound(nums.begin() + i + 1 , nums.end() , abs(r - nums[i])) - lower_bound(nums.begin() + i + 1 , nums.end() , abs(l - nums[i])) ;
    }

    cout << ans << nl;
}

void done() {
    int t;
    cin >> t;
    while (t--) {
        ll n, l, r;
        cin >> n >> l >> r;
        vector<ll> v(n);
        for (ll i = 0; i < n; i++)
            cin >> v[i];
        ll cntr = 0;
        ordered_set<ll> st;
        for (int i = 1; i < n; ++i) {
            st.insert(v[i - 1]);
            ll num1 = st.order_of_key(r - v[i]);
            ll num2 = st.size() - st.order_of_key(l - v[i]);
            if ((*(st.find_by_order(st.size() - 1)) >= (l - v[i])) &&*(st.find_by_order(st.size() - 1)) <= (r - v[i])) {
                cntr += (abs(num2 - num1) + 1);
            }

        }
        cout << cntr << '\n';
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
