// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK :
#include <bits/stdc++.h>
#define ll long long
#define int ll
#define nl '\n'
#define sp ' '
#define all(a) a.begin(),a.end()
#define allr(a) a.rbegin(),a.rend()
#define no cout<<"NO\n"
#define yes cout<<"YES\n"
#define imp cout<<"IMPOSSIBLE\n"
#define ENG_GAMAL ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;
// ————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
const int N = 2e5 + 5, M = 1e3, LOG = 20, inf = 0x3f3f3f3f;
ll infLL = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= cbrtl(LLONG_MAX) ; ++i) {
        int l = 1 , r = cbrtl(LLONG_MAX);
        while(l <= r){
            int y = (r + l) / 2;
            int x = i + y;
            int equation = i*i*i + 3*i*i*y + 3*i*y*y;
            if(equation == n){
                cout << x << sp << y << nl;
                return;
            }else if(equation > n){
                r = y - 1;
            }else{
                l = y + 1;
            }
        }
    }
    cout << -1 << nl;
}
void file()
{
#ifndef ONLINE_JUDGE
    freopen("Input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
    freopen("Error.txt", "w", stderr);
#endif
}

signed main() {
    file();
    ENG_GAMAL
    ll t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}
