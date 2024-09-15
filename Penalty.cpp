// LINK : https://codeforces.com/problemset/problem/1553/C
#include <bits/stdc++.h>
#define ll long long
#define nl '\n'
#define all(a) a.begin(),a.end()
#define allr(a) a.rbegin(),a.rend()
#define no cout<<"NO\n";
#define yes cout<<"YES\n";
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
template <typename T>
void get_vec(vector<T>& v) {
    for (ll i = 0; i < v.size(); ++i) {
        cin >> v[i];
    }
}
template <typename T>
void out_vec(vector<T>& v) {
    for (ll i = 0; i < v.size(); ++i) {
        cout << v[i] << ' ';
    }
    cout << nl;
}
// ————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void solve() {
    string s;
    cin >> s;
    ll n = count(all(s) , '?');
    ll ans = 10;
    for (ll i = 0; i < (1 << n); ++i) {
        string could;
        for (ll j = 0; j < n; ++j) {
            if((1 << j) & i)
            {
                could += '1';
            }
            else
            {
                could += '0';
            }
        }
        ll idx = 0;
        ll t1 = 0 , t2 = 0;
        for (ll j = 1; j <= 10; ++j) {
            char kick = s[j - 1];
            if(kick == '?')
            {
                kick = could[idx];
                idx++;
            }
            if(j & 1)
            {
                t1 += kick - '0';
            }
            else
            {
                t2 += kick - '0';
            }
            if(t1 > t2 + ceil((10 - j) / 2.0))
            {
                ans = min(ans , j);
                break;
            }
            if(t2 > t1 + (((10 - j) / 2.0)))
            {
                ans = min(ans , j);
                break;
            }
        }
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