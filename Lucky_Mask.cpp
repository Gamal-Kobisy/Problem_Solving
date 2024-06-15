//
// DATE : Created by Gamal on 6/8/2024.
// LINK : https://vjudge.net/contest/586365#problem/T

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
using namespace std;
using namespace __gnu_pbds;
struct un_ordered
{
    bool operator()(const long long &a, const long long &b) const
    {
        return true;
    }
};
template <class T>
using ordered_set = tree<T, null_type, un_ordered, rb_tree_tag, tree_order_statistics_node_update>;
string get_mask(ll num)
{
    string mask = "";
    while (num)
    {
        int digit = num % 10;
        if(digit == 4 || digit == 7)
        {
            mask += digit + '0';
        }
        num /= 10;
    }
    reverse(all(mask));
    return mask;
}
void solve()
{
    ll num;
    string  mask;
    cin >> num >> mask;
    num++;
    string curr_mask = get_mask(num);
    while(curr_mask != mask)
    {
        num++;
        curr_mask = get_mask(num);
    }
    cout << num << nl;
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