//
// DATE : Created by Gamal on 6/28/2024.
// LINK : https://vjudge.net/contest/589623#problem/H
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
using namespace std::chrono;
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

void solve()
{
    ll n ;
    cin >> n;
    map<ll , vector<ll>>pos;
    for (ll i = 0; i < n; ++i) {
        ll z;
        cin >> z;
        pos[z].push_back(i+1);
    }


    ll q;
    cin >> q;
    while (q--)
    {
        ll l , r , x;
        cin >> l >> r >> x;
        cout << upper_bound(pos[x].begin(), pos[x].end(),r) - lower_bound(pos[x].begin(), pos[x].end(),l) << nl;
    }
}
void fatema_solve()
{
    ll n; cin >> n;
    vector<ll>v(2e5);
    for (ll i = 1; i < n + 1; i++)
        cin >> v[i];
    vector<vector<ll>>pre(2e5, vector<ll>(2e5));
    for (ll i = 1; i < n+1; i++)
    {
        pre[v[i]][i] = 1;
    }
    for (ll i = 1; i < n+1; i++)
    {
        for (ll j = 1; j < n+1; j++)
        {
            pre[i][j] += pre[i][j-1];
        }
    }
    ll q; cin >> q;
    while (q--)
    {
        ll l, r, x; cin >> l >> r >> x;
        cout << pre[x][r] - pre[x][l-1]<<'\n';
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
void time(const function<void()>& func) {
    // Get the start time
    auto start_time = high_resolution_clock::now();

    // Execute the function
    func();

    // Get the end time
    auto end_time = high_resolution_clock::now();

    // Calculate the duration in microseconds
    auto duration = duration_cast<microseconds>(end_time - start_time).count();

    // Output the execution time
    cout << "Execution Time: " << duration << " microseconds" << endl;
}
int main() {
    file();
    fast();
    ll t = 1;
    // cin >> t;
    while(t--)
    {
//        time(solve);
        fatema_solve();
    }
    return 0;
}
