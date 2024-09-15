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
}
// ————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

//void solve() {
//    ll n;
//    cin >> n;
//    list<ll>v;
//    vector<ll> ans;
//    auto it_max = v.begin();
//    ll maxi = 0;
//    for (ll i = 0; i < n; ++i) {
//        ll x;
//        cin >> x;
//        v.push_back(x);
//        if(x > maxi)
//        {
//            maxi = x;
//            it_max = prev(v.end());
//        }
//    }
//    v.erase(it_max);
//    ans.push_back(maxi);
//    ll back = ans.back();
//    while (ans.size() != n)
//    {
//        if(back == (1 << (ll)ceil(log2(maxi))) - 1)
//        {
//            break;
//        }
//        auto it_next = v.begin();
//        ll next = 0;
//        for (auto i = v.begin(); i != v.end(); ++i) {
//            if((back | *i) >= (back | next))
//            {
//                it_next = i;
//                next = *i;
//            }
//        }
//        v.erase(it_next);
//        ans.push_back(next);
//        back |= ans.back();
//    }
//    out_vec(ans);
//    for (ll &i: v) {
//        cout << i << ' ';
//    }
//    cout << nl;
//}

void solve() {
    int n;
    cin >> n;
    vector<ll>v(n);
    get_vec(v);
    ll cur_or = 0;
    vector<bool>vis(n , false);
    for (ll i = 0; i < min(31 , n); ++i) {
        ll mx = 0 , idx = -1;
        for (ll j = 0; j < n; ++j) {
            if(vis[j])
            {
                continue;
            }
            if((v[j] | cur_or) >= mx)
            {
                mx = (cur_or | v[j]);
                idx = j;
            }
        }
        vis[idx] = true;
        cout << v[idx] << ' ';
        cur_or |= v[idx];
    }
    for (ll i = 0; i < n; ++i) {
        if(!vis[i])
        {
            cout << v[i] << ' ';
        }
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