//
// DATE : Created by Gamal on 7/11/2024.
// LINK : https://vjudge.net/contest/592750#problem/H

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

bool d(ll n)
{
    if(n % (ll)sqrt(n) != 0 || n <= 3)
    {
        return 0;
    }
    for (ll i = 2; i * i < n ; ++i) {
        if(n % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

void solve()
{
    ll n ;
    cin >> n;
    vector<ll>v(n);
    for (ll i = 0; i < n; ++i) {
        cin >> v[i];
    }
    for(ll i : v)
    {
        if(d(i))
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
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
    // cin >> t;
    while(t--)
    {
        solve();
    }

    return 0;
}
