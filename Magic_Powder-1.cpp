//
// DATE : Created by Gamal on 6/22/2024.
// LINK : https://codeforces.com/contest/670/problem/D1

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
struct cooke
{
    long long number_of_cookies;
    long long needed_grams;
    long long valid_grams;
    long long needed_add_new;
};

struct cookies_sort
{
    bool operator()(cooke a , cooke b) const
    {
        if(a.number_of_cookies > b.number_of_cookies)
        {
            return true;
        }
        else if(a.number_of_cookies == b.number_of_cookies)
        {
            return (a.needed_add_new > b.needed_add_new);
        }
        return false;
    }
};
void solve()
{
    ll n , k;
    cin >> n >> k;
    vector<cooke>v(n);
    priority_queue<cooke , vector<cooke> , cookies_sort>cookies;
    for (ll i = 0; i < n; ++i) {
        cin >> v[i].needed_grams;
    }
    for (ll i = 0; i < n; ++i) {
        cin >> v[i].valid_grams;
    }
    for (auto &item: v) {
        item.number_of_cookies = item.valid_grams / item.needed_grams;
        ll reminder = item.valid_grams % item.needed_grams;
        item.needed_add_new = item.needed_grams - reminder;
        cookies.push(item);
    }
    while(k)
    {
        cooke top = cookies.top();
        cookies.pop();
        if(top.needed_add_new > k)
        {
            cookies.push(top);
            break;
        }
        top.valid_grams += top.needed_add_new;
        top.number_of_cookies++;
        top.needed_add_new = top.needed_grams;
        cookies.push(top);
    }
    cout << cookies.top().number_of_cookies << nl;
}

void good_solve()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n) , b(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (ll i = 0; i < n; ++i) {
        cin >> b[i];
    }
    ll l = 1 , r = 2000000000 , ans = 0 ;
    while(l <= r)
    {
        ll mid = (l + r) / 2 , magic = k;
        bool ok = true;
        for (ll i = 0; i < n; ++i) {
            ll available = b[i] / a[i];
            if(available >= mid)
            {
                continue;
            }
            ll needed_cookies = mid - available;
            ll needed_powder = mid * a[i] - b[i];
            if(needed_powder <= magic)
            {
                magic -= needed_powder;
                continue;
            }
            else
            {
                ok = false;
                break;
            }
        }
        if(ok)
        {
            ans = max(ans , mid);
            l = mid + 1;
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
        good_solve();
    }

    return 0;
}
