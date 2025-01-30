// LINK : https://codeforces.com/contest/1692/problem/F
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
    ll n;
    cin >> n;
    vector<int>v(n);
    map<ll,ll>freq;
    for (ll i = 0; i < n; ++i) {
        ll x;
        cin >> x;
        x %= 10;
        freq[x]++;
        v[i] = x;
    }
    for (ll i = 0; i <= 9; ++i) {
        for (ll j = 0; j <= 9 ; ++j) {
            for (ll k = 0; k < 9 ; ++k) {
                ll fk = freq[k] , fi = freq[i] , fj = freq[j];
                if(freq[k]-- && freq[i]-- && freq[j]--)
                {
                    if((i + j + k) % 10 == 3)
                    {
                        yes;
                        return;
                    }
                }
                freq[k] = fk;
                freq[i] = fi;
                freq[j] = fj;
            }
        }
    }
    no;
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