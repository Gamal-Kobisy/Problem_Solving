// LINK : https://codeforces.com/contest/1692/problem/D
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
bool valid(ll h , ll m)
{
    return (h % 10 == m / 10) && (h / 10 == m % 10);
}
void solve() {
    string s;
    ll x , ans = 0;
    cin >> s >> x;
    ll h = stoi(s.substr(0 , 2)) , m = stoi(s.substr(3));
    if(valid(h , m))
    {
        ans++;
    }
    ll h2 = h + (x / 60) , m2 = m + (x % 60);
    if(m2 >= 60)
    {
        h2 += m2 / 60;
        m2 %= 60;
    }
    h2 %= 24;
    while (h2 != h || m2 != m)
    {
        if(valid(h2 , m2))
        {
            ans++;
        }
        h2 += (x / 60) ;
        m2 += (x % 60) ;
        if(m2 >= 60)
        {
            h2 += m2 / 60;
            m2 %= 60;
        }
        h2 %= 24;
    }
    cout << ans << nl;
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