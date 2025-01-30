// LINK : https://codeforces.com/contest/1980/problem/C
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
    vector<ll>a(n) , b(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }
    ll cnt = 0;
    for (ll i = 0; i < n; ++i) {
        cin >> b[i];
        if(a[i] != b[i])
        {
            cnt++;
        }
    }
    ll m;
    cin >> m;
    vector<ll>d(m);
    map<ll , ll>freq;
    for (ll i = 0; i < m; ++i) {
        cin >> d[i];
        freq[d[i]]++;
    }
    if(cnt > m)
    {
        no;
        return;
    }
    for (ll i = 0; i < n; ++i) {
        if(a[i] != b[i])
        {
            if(freq[b[i]])
            {
                freq[b[i]]--;
                continue;
            }
            else
            {
                no;
                return;
            }
        }
    }
    if(find(all(b) , d[m - 1]) == b.end())
    {
        no;
    }
    else
    {
        yes;
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