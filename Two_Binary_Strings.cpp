//
// DATE : Created by Gamal on 6/8/2024.
// LINK : https://vjudge.net/problem/CodeForces-1202A

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

ll binary_to_ll(string num)
{
    return stoull(num , nullptr , 2);
}

string reverse_binary(ll sk)
{
    string rev_k;
    while (sk)
    {
        rev_k += (sk % 2 == 0) ? '0' : '1';
        sk /= 2;
    }
    return rev_k.empty()? "0" : rev_k;
}
void find_k(ll fx , ll fy)
{
    ll optimal_k = 0;
    string min_rev;
    for(ll k = 0 ;; k++)
    {
        ll sk = fx + (fy << k);
        string rev_k = reverse_binary(sk);
        if(min_rev.empty() || rev_k < min_rev)
        {
            optimal_k = k;
            min_rev = rev_k;
        }
        else
        {
            break;
        }
    }
    cout << optimal_k << nl;
}
void solve() {
    string x, y;
    cin >> x >> y;
    find_k(binary_to_ll(x), binary_to_ll(y));
}
void good_solve()
{
    string x, y;
    cin >> x >> y;
    reverse(x.begin(), x.end());
    reverse(y.begin(), y.end());
    ll index_y = y.find('1');
    ll k = 0;
    while(x[index_y] != '1')
    {
        x.erase(x.begin());
        k++;
    }
    cout << k << nl;
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
