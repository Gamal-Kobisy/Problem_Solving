//
// DATE : Created by Gamal on 7/9/2024.
// LINK : https://vjudge.net/contest/589623#problem/U

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
    string s;
    cin >> s;
    vector<ll>needed(3);
    for (int i = 0; i < s.size(); ++i) {
        if(s[i] == 'B')
        {
            needed[0]++;
        }
        else if(s[i] == 'S')
        {
            needed[1]++;
        }
        else if(s[i] == 'C')
        {
            needed[2]++;
        }
    }
    vector<ll>have(3);
    cin >> have[0] >> have[1] >> have[2];
    vector<ll>price(3);
    cin >> price[0] >> price[1] >> price[2];
    ll rubles;
    cin >> rubles;
    ll l = 0 , r = 1000000000100, ans ;
    while (l <= r)
    {
        ll mid = (r + l) / 2;
        ll needed_rubles = 0;
        vector<ll>total_need(3);
        for (int i = 0; i < 3; ++i) {
            total_need[i] = mid * needed[i];
            if(total_need[i] >= have[i])
            {
                total_need[i] -= have[i];
            }
            else
            {
                total_need[i] = 0;
            }
            needed_rubles += total_need[i] * price[i];
        }
        if (rubles >= needed_rubles)
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
