// LINK :
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
const int N = 2e5 + 5, M = 1e3, LOG = 20, inf = 0x3f3f3f3f;
int MOD = 1e9 + 7;
ll infLL = 0x3f3f3f3f3f3f3f3f;

void solve() {
    ll n , neg = 0;
    cin >> n;
    for (ll i = 0; i < n; ++i) {
        int x;
        cin >> x;
        if(x < 0)
        {
            neg++;
        }
    }
    if(neg <= n / 2)
    {
        cout << (neg & 1) << nl;
    }
    else
    {
        ll ans = neg - (n / 2);
        neg -= ans;
        cout << ans + (neg & 1) << nl;
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