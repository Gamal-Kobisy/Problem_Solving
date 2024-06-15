//
// DATE : Created by Gamal on 6/7/2024.
// LINK : https://vjudge.net/contest/586365#problem/Y
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
bool divide(long long x)
{
    int cnt_4 = 0, cnt_7 = 0;
    while (x)
    {
        int cnt = x % 10;
        if (cnt != 4 && cnt != 7)
        {
            return false;
        }
        (cnt == 4) ? cnt_4++ : cnt_7++;
        x /= 10;
    }
    return (cnt_4 == cnt_7);
}
void solve()
{
    long long num;
    cin >> num;
    long long n_copy = num;
    int digits = 0;

    while (n_copy)
    {
        digits++;
        n_copy /= 10;
    }

    if (digits % 2 == 1)
    {
        digits++;
    }
    n_copy = num;
    string maxx = string(digits / 2, '7') + string(digits / 2, '4');
    if (stoll(maxx) < n_copy)
    {
        digits += 2;
    }
    int perm[digits];
    for (int i = 0; i < digits / 2; i++)
    {
        perm[i] = 4;
    }
    for (int i = digits / 2; i < digits; i++)
    {
        perm[i] = 7;
    }
    do
    {
        long long lucky_num = 0;
        for (int i = 0; i < digits; i++)
        {
            lucky_num = lucky_num * 10 + perm[i];
        }
        if (lucky_num >= num)
        {
            cout << lucky_num << endl;
            return ;
        }
    } while (next_permutation(perm, perm + digits));

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
    // cin >> t;
    while(t--)
    {
        solve();
    }

    return 0;
}