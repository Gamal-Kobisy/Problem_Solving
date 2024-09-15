// LINK :  https://codeforces.com/problemset/problem/476/B
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
    string s1 , s2;
    cin >> s1 >> s2;
    ll Drazil_pos = 0;
    for (ll i = 0; i < s1.size(); ++i) {
        Drazil_pos += (s1[i] == '+' ? 1 : -1);
    }
    ll Dreamoon_pos = 0;
    for (ll i = 0; i < s2.size(); ++i) {
        if(s2[i] == '+')
        {
            Dreamoon_pos++;
        }
        if(s2[i] == '-')
        {
            Dreamoon_pos--;
        }
    }
    ll n = count(all(s2) , '?') , ans = 0;
    for (ll i = 0; i < (1 << n); ++i) {
        ll cnt = 0;
        for (ll j = 0; j < n; ++j) {
            if((1 << j) & i)
            {
                cnt++;
            }
            else
            {
                cnt--;
            }
        }
        if(Dreamoon_pos + cnt == Drazil_pos)
        {
            ans++;
        }
    }
    cout << fixed << setprecision(12) << (double)ans / (1 << n) << nl;
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
//    cin >> t;
    while(t--)
    {
        solve();
    }

    return 0;
}