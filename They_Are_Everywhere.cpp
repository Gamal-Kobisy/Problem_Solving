//
// DATE : Created by Gamal on 6/24/2024.
// LINK : https://vjudge.net/contest/589623#problem/B

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
void Two_Pointer_solve()
{
    ll n;
    cin >> n;
    string house ;
    cin >> house;
    set<char>s;
    for(char c : house)
    {
        s.insert(c);
    }
    ll l = 0 , r = 0, ans = n;
    map<char , ll>cur_freq;
    cur_freq[house[0]]++;
    while (l <= r && r < n)
    {
        ll mid = (l + r ) / 2;
        if(cur_freq.size() == s.size())
        {
            ans = min(ans , r - l + 1);
            cur_freq[house[l]]--;
            if(cur_freq[house[l]] == 0)
            {
                cur_freq.erase(house[l]);
            }
            l++;
        }
        else
        {
            r++;
            cur_freq[house[r]]++;
        }
    }
    cout << ans << nl;
}
void Binary_Search_solve()
{
    ll n;
    cin >> n;
    string house;
    cin >> house;
    set<char>s;
    for(char c : house)
    {
        s.insert(c);
    }
    ll l = s.size() , r = n , ans = 0;
    while (l <= r)
    {
        ll mid = (l + r) / 2;
        bool ok = false;
        for (ll i = 0; i <= n - mid; ++i) {
            set<char>t;
            for (ll j = i; j < i +  mid; ++j) {
                t.insert(house[j]);
            }
            if(t.size() == s.size())
            {
                ok = true;
                break;
            }
            t.clear();
        }
        if(ok)
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
    // cin >> t;
    while(t--)
    {
        Two_Pointer_solve();
    }

    return 0;
}
