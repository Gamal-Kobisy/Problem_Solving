//
// DATE : Created by Gamal on 6/7/2024.
// LINK : https://vjudge.net/contest/586365#problem/G

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
    string s1, s2;
    cin >> s1 >> s2;
    long long s1_index = 0, s2_index = 0;
    bool not_valid = false;
    while (s1_index != s1.size() && s2_index != s2.size())
    {
        if (s1[s1_index] == s2[s2_index])
        {
            s1_index++;
            s2_index++;
        }
        else if (s1[s1_index - 1] == s2[s2_index])
        {
            s2_index++;
        }
        else
        {
            not_valid = true;
            break;
        }
    }
    while (s2_index != s2.size())
    {
        s2_index++;
        if (s2[s2_index - 1] != s1[s1_index - 1])
        {
            not_valid = true;
            break;
        }
    }
    if (not_valid)
    {
        cout << "NO\n";
        return;
    }
    cout << (s1_index == s1.size() ? "YES\n" : "NO\n");
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
