// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/contest/2059/problem/C
#include <bits/stdc++.h>
#define ll long long
#define nl '\n'
#define sp ' '
#define all(a) a.begin(),a.end()
#define allr(a) a.rbegin(),a.rend()
#define no cout<<"NO\n"
#define yes cout<<"YES\n"
#define ENG_GAMAL ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;
// ————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
const int N = 2e5 + 5, M = 1e3, LOG = 20, inf = 0x3f3f3f3f;
ll infLL = 0x3f3f3f3f3f3f3f3f;



void solve() {
    int n;
    cin >> n;
    multiset<int>s;
    for (ll i = 0; i < n; ++i) {
        vector<ll>queue(n);
        for (ll j = 0; j < n; ++j) {
            cin >> queue[j];
        }
        reverse(all(queue));
        int cnt = 0;
        for (ll j = 0; j < n; ++j) {
            if(queue[j] == 1)
                cnt++;
            else
                break;
        }
        if(cnt)
            s.insert(cnt);
    }
    
    
    int ans = 1;
    while(!s.empty()){
        int cur = *s.begin();
        if(cur >= ans){
            ans++;
        }
        s.erase(s.begin());
    }
    cout << min(ans , n) << nl;
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
    while (t--)
    {
        solve();
    }

    return 0;
}