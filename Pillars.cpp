//
// DATE : Created by Gamal on 6/7/2024.
// LINk : https://vjudge.net/contest/586365#problem/K

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

void solve()
{
    ll n;
    cin >> n;
    list <ll> pillars;
    f0(n)
    {
        ll x;
        cin >> x;
        pillars.push_back(x);
    }
//    for( ll i : pillars)
//    {
//        cout << i << nl;
//    }
    auto it = max_element(all(pillars));
    while(pillars.size() != 1)
    {
            auto it_next = it;
            ++it_next;
            auto it_previous = it ;
            --it_previous;
            if(*it_next + 1 == *it)
            {
                pillars.erase(it);
                it = it_next;
            }
            else if(*it_previous + 1 == *it)
            {
                pillars.erase(it);
                it = it_previous;
            }
            else
            {
                cout << "NO\n";
                return;
            }
        }
    cout << "YES\n";
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
