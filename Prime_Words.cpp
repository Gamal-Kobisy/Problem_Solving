//
// DATE : Created by Gamal on 7/17/2024.
// LINK : https://vjudge.net/contest/592750#problem/Y

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

bool isPrime(ll num) {
    for (ll i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

void solve()
{
    string word;
    while (cin >> word)
    {
        ll sum = word.size();
        for(char c : word)
        {
            ll x;
            if(c < 'a')
            {
                x = c - 'A' + 26;
            }
            else
            {
                x = c - 'a';
            }
            sum += x;
        }
        if (isPrime(sum))
        {
            cout << "It is a prime word.\n";
        }
        else
        {
            cout << "It is not a prime word.\n";
        }
    }
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
