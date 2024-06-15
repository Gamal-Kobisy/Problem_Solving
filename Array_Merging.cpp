//
// DATE : Created by Gamal on 6/7/2024.
// LINK : https://vjudge.net/contest/586365#problem/C

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
    long long n;
    cin >> n;
    map<long long, long long> freq1, freq2;
    vector<long long> v1(n), v2(n);
    long long counter = 1;
    for (long long i = 0; i < n; i++)
    {
        cin >> v1[i];
    }
    for (long long i = 0; i < n; i++)
    {
        cin >> v2[i];
    }
    for (long long i = 0; i < n - 1; i++)
    {
        if (v1[i] == v1[i + 1])
        {
            counter++;
        }
        else
        {
            freq1[v1[i]] = max(counter, freq1[v1[i]]);
            counter = 1;
        }
    }
    if (v1[n - 1] == v1[n - 2])
    {
        freq1[v1[n - 1]] = max(counter, freq1[v1[n - 1]]);
        counter = 1;
    }
    else
    {
        freq1[v1[n - 1]] = max(1ll, freq1[v1[n - 1]]);
        counter = 1;
    }
    for (long long i = 0; i < n - 1; i++)
    {
        if (v2[i] == v2[i + 1])
        {
            counter++;
        }
        else
        {
            freq2[v2[i]] = max(counter, freq2[v2[i]]);
            counter = 1;
        }
    }
    if (v2[n - 1] == v2[n - 2])
    {
        freq2[v2[n - 1]] = max(counter, freq2[v2[n - 1]]);
        counter = 1;
    }
    else
    {
        freq2[v2[n - 1]] = max(1ll, freq2[v2[n - 1]]);
        counter = 1;
    }
    long long maxx = LLONG_MIN;
    for (auto i : freq1)
    {
        maxx = max(maxx, i.second + freq2[i.first]);
    }
    for (auto i : freq2)
    {
        maxx = max(maxx, i.second + freq1[i.first]);
    }
    cout << maxx << endl;
}

void file()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
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
