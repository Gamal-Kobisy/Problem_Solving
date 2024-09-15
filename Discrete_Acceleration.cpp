//
// DATE : Created by Gamal on 7/10/2024.
// LINK : https://vjudge.net/contest/589623#problem/O

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

struct car
{
    ll pos;
    ll speed = 1;
};
void solve()
{
    ll n , length;
    cin >> n >> length;
    vector<ll>flags(n) , pre(n +1) , suf(n + 2);
    suf[n+1]=1;
    pre[0]=1;
    for (ll i = 0; i < n; ++i) {
        cin >> flags[i];
        pre[i]++;
        suf[i]++;
    }
    for (ll i = 1; i < n; ++i) {
        pre[i] += pre[i - 1];
    }
    for (ll i = n ; i >= 0 ; i--) {
        suf[i] += suf[i + 1];
    }
    double sec = 0;
    car first , second;
    first.pos = 0;
    second.pos = length;
    ll l = 0 , r = n - 1;
    while (l <= r)
    {
        double time_1 = (flags[l] - first.pos) / (double) first.speed;
        double time_2 = (second.pos - flags[r]) / (double) second.speed;
        if(time_1 <= time_2)
        {
            first.pos = flags[l];
            first.speed = pre[l];
            l++;
            second.pos -= second.speed * time_1;
            while(second.pos <= flags[r])
            {
                second.speed = suf[r];
                r--;
            }
            sec += time_1;
        }
        else
        {
            second.pos = flags[r];
            second.speed = suf[r];
            r--;
            first.pos += first.speed * time_2;
            while(first.pos >= flags[l])
            {
                first.speed = pre[l];
                l++;
            }
            sec += time_2;
        }
    }
    double extra = double(second.pos - first.pos) / double(first.speed + second.speed);
    sec += extra;
    cout << fixed << setprecision(15) << sec << nl;
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
