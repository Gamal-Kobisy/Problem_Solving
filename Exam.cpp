//
// DATE : Created by Gamal on 6/8/2024.
// LINK : https://vjudge.net/contest/586365#problem/N

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define nl '\n'
#define all(a) a.begin(),a.end()
#define allr(a) a.rbegin(),a.rend()
#define f1(n) for(int i=1;i<n;i++)
#define f0(n) for(ll i=0;i<n;++i)
#define fe(v) for(auto & it:v)
using namespace std;
using namespace __gnu_pbds;

template <class T>
using ordered_set = tree<T, null_type, greater_equal<>, rb_tree_tag, tree_order_statistics_node_update>;

void solve()
{
    ll n, minutes;
    cin >> n >> minutes;
    priority_queue<ll> ordered_nums ;
    priority_queue<ll , vector<ll> , less_equal<>>removed;
    vector<ll> nums(n);

    f0(n)
    {
        cin >> nums[i];
    }
    ll fails = 0, sum = 0;
    f0(n)
    {
        sum += nums[i];
        if (sum <= minutes)
        {
            cout << fails << ' ';
            ordered_nums.push(nums[i]);
        }
        else
        {
            while (sum > minutes)
            {
                sum -= ordered_nums.top();
                removed.push(-ordered_nums.top());
                ordered_nums.pop();
                fails++;
            }
            cout << fails << ' ';
            int top = removed.top() ;
            int top2 = ordered_nums.top();
            int j = nums[i];
            if(nums[i] > -removed.top())
            {
                sum -= removed.top();
                sum -= nums[i];
                ordered_nums.push(-removed.top());
                removed.pop();
                removed.push(-nums[i]);
                while (sum + -removed.top() <= minutes)
                {
                    sum += -removed.top();
                    ordered_nums.push(-removed.top());
                    removed.pop();
                    fails--;
                }
            }
            else
            {
                ordered_nums.push(nums[i]);
            }
        }
    }
    cout << endl;
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
    while (t--)
    {
        solve();
    }

    return 0;
}
