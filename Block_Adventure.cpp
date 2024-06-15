//
// DATE : Created by Gamal on 6/7/2024.
// LINK : https://vjudge.net/contest/586365#problem/H

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
 ll n , bag , k;
 cin >> n >> bag >> k;
 vector <ll> columns(n);
 f0(n)
 {
     cin >> columns[i];
 }
 bool can = true;
    for (int i = 0; i < n - 1; ++i) {
        if(columns[i] >= columns[i+1])
        {
            bag += min(k + (columns[i] - columns[i+1]) , columns[i]);
        }
        else
        {
            if(columns[i+1] - columns[i] > k)
            {
                if(columns[i+1] - columns[i] > k + bag)
                {
                    can = false;
                    break;
                }
                else
                {
                    bag -= (columns[i+1] - columns[i]) - k;
                }
            }
            else
            {
                bag += k - (columns[i+1] - columns[i]);
            }
        }
    }
    cout << (can ? "YES\n" : "NO\n");
}

void good_solve()
{
    ll n , bag , k;
    cin >> n >> bag >> k;
    vector <ll> columns(n);
    f0(n)
    {
        cin >> columns[i];
    }
    for (int i = 0; i < n - 1; ++i) {
        bag += min(k + (columns[i] - columns[i+1]) , columns[i]);
        if(bag < 0)
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
     cin >> t;
    while(t--)
    {
        good_solve();
    }

    return 0;
}
