//
// DATE : Created by Gamal on 6/17/2024.
// LINK : https://vjudge.net/contest/588093#problem/J

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

struct Conditioners
{
    ll heat ;
    ll pos;
};
void solve()
{
    ll n , k;
    cin >> n >> k;
    vector<ll>land(n , LLONG_MAX);
    vector<Conditioners> Air_Conditioners(k);
    for (ll i = 0; i < k; ++i) {
        cin >> Air_Conditioners[i].pos;
        Air_Conditioners[i].pos--;
    }
    for (ll i = 0; i < k; ++i) {
        cin >> Air_Conditioners[i].heat;
    }
    for (ll i = 0; i < n; ++i) {
        land[i] = Air_Conditioners[0].heat + abs(Air_Conditioners[0].pos - i);
    }
    Air_Conditioners.erase(Air_Conditioners.begin());
    for (auto &conditioner: Air_Conditioners) {
        for (ll i = conditioner.pos; i < n ; ++i) {
            if(land[i] <= conditioner.heat + abs(conditioner.pos - i))
            {
                break;
            }
            land[i] = min(land[i],conditioner.heat + abs(conditioner.pos - i));
        }
        for (ll i = conditioner.pos; i >= 0 ; --i) {
            if(land[i] < conditioner.heat + abs(conditioner.pos - i))
            {
                break;
            }
            land[i] = conditioner.heat + abs(conditioner.pos - i);
        }
    }
    for (ll item: land) {
        cout << item << ' ';
    }
    cout << nl;
}

void good_solve()
{
    ll n , k;
    cin >> n >> k;
    vector<ll>v,pre(n+2 , 10e10) , suf(n+2 , 10e10);
    vector<Conditioners> Air_Conditioners(k);
    for (ll i = 0; i < k; ++i) {
        cin >> Air_Conditioners[i].pos;
    }
    for (ll i = 0; i < k; ++i) {
        cin >> Air_Conditioners[i].heat;
        pre[Air_Conditioners[i].pos] = Air_Conditioners[i].heat;
        suf[Air_Conditioners[i].pos] = Air_Conditioners[i].heat;
    }
    for (ll i = 0; i < n ; ++i) {
            pre[i+1] = min(pre[i+1] ,pre[i] + 1);
    }
    for (ll i = n; i > 0 ; i--) {
            suf[i-1] = min(suf[i-1] ,suf[i] + 1);
    }
    for (ll i = 0; i < n; ++i) {
        cout << min(pre[i+1] , suf[i+1]) << ' ';
    }
    cout << nl;
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
