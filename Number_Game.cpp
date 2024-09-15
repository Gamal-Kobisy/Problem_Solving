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

long long spf(long long n) {
    if (n % 2 == 0) return 2;
    for (long long i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return i;
    }
    return n;
}

void solve()
{
    ll n;
    cin >> n;
    if(n == 1)
    {
        cout << "FastestFinger" << nl;
        return;
    }
    if(n == 2)
    {
        cout << "Ashishgup" << nl;
        return;
    }
    if(n % 2)
    {
        cout << "Ashishgup" << nl;
    }
    else
    {
        ll n_copy = n , even_divs = 0 , odd_divs = 0;
        while (n % 2 == 0)
        {
            n /= 2;
            even_divs++;
        }
        while (n != 1 )
        {
            ll odd_div = spf(n);
            while (n % odd_div == 0)
            {
                n /= odd_div;
                odd_divs++;
            }
            if (odd_divs > 1)
            {
                break;
            }
        }
        if(odd_divs == 0)
        {
            cout << "FastestFinger" << nl;
        }
        else if(even_divs > 1)
        {
            cout << "Ashishgup" << nl;
        }
        else if(even_divs == 1)
        {
            if(odd_divs > 1)
            {
                cout << "Ashishgup" << nl;
            }
            else
            {
                cout << "FastestFinger" << nl;
            }
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