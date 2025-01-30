// LINK : https://codeforces.com/contest/2005/problem/B1
#include <bits/stdc++.h>
#define ll long long
#define nl '\n'
#define all(a) a.begin(),a.end()
#define allr(a) a.rbegin(),a.rend()
#define no cout<<"NO\n"
#define yes cout<<"YES\n"
#define ENG_GAMAL ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

/*
 ███████╗███╗   ██╗ ██████╗       ██████╗  █████╗ ███╗   ███╗ █████╗ ██╗
 ██╔════╝████╗  ██║██╔════╝      ██╔════╝ ██╔══██╗████╗ ████║██╔══██╗██║
 █████╗  ██╔██╗ ██║██║  ███╗     ██║  ███╗███████║██╔████╔██║███████║██║
 ██╔══╝  ██║╚██╗██║██║   ██║     ██║   ██║██╔══██║██║╚██╔╝██║██╔══██║██║
 ███████╗██║ ╚████║╚██████╔╝     ╚██████╔╝██║  ██║██║ ╚═╝ ██║██║  ██║███████╗
 ╚══════╝╚═╝  ╚═══╝ ╚═════╝       ╚═════╝ ╚═╝  ╚═╝╚═╝     ╚═╝╚═╝  ╚═╝╚══════╝
*/
// ————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
void solve() {
    ll n , m , q;
    cin >> n >> m >> q;
    vector<ll>tech(m);
    for (ll i = 0; i < m; ++i) {
        cin >> tech[i];
    }
    for (ll i = 0; i < q; ++i) {
        ll cur ;
        cin >> cur;
        ll l = 0 , r = n + 1;
        for (ll j = 0; j < m; ++j) {
            if(tech[j] < cur)
            {
                l = max(l , tech[j]);
            }
            if(tech[j] > cur)
            {
                r = min(r , tech[j]);
            }
        }
//        cout << l << ' ' << cur << ' ' << r << nl;
        if(l == 0)
        {
            cout << r - 1 << nl;
        }
        else if(r == n + 1)
        {
            cout << r - l - 1 << nl;
        }
        else
        {
            cout << abs(r - l) / 2 << nl;
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
int main() {
    file();
    ENG_GAMAL
// test-independent code ——————————————————————
// ————————————————————————————————————————————
    ll t = 1;
    cin >> t;
    while(t--)
    {
        solve();
    }

    return 0;
}