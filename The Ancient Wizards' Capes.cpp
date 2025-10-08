// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/contest/2155/problem/C
#include <bits/stdc++.h>
#define ll long long
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
    vector<int>a(n);
    vector<bool>like(n);
    for(int i = 0 ; i < n ; i++){
        cin >> a[i];
        if(i)
            like[i] = abs(a[i] - a[i - 1]);
    }
    vector<int>sol1(n) , sol2(n);
    // 1-> right cape
    // 2-> left cape
    sol1[0] = 1;
    sol2[0] = 2;
    for(int i = 1 ; i < n ; i++){
        if(like[i]){
            sol1[i] = sol1[i - 1];
            sol2[i] = sol2[i - 1];
        }
        else{
            sol1[i] = 3 - sol1[i - 1];
            sol2[i] = 3 - sol2[i - 1];
        }
    }
    vector<int>pre1(n + 1) , suf1(n + 2);
    vector<int>pre2(n + 1) , suf2(n + 2);
    for(int i = 1 ; i <= n ; i++){
        pre1[i] = pre1[i - 1] + (sol1[i - 1] == 2);
        pre2[i] = pre2[i - 1] + (sol2[i - 1] == 2);
    }

    for(int i = n ; i >= 0 ; i--){
        suf1[i] = suf1[i + 1] + (sol1[i - 1] == 1);
        suf2[i] = suf2[i + 1] + (sol2[i - 1] == 1);
    }
    bool ok1 = true , ok2 = true;
    for(int i = 0 ; i < n ; i++) {
        if (suf1[i + 1] + pre1[i + 1] != a[i])
            ok1 = false;
        if (suf2[i + 1] + pre2[i + 1] != a[i])
            ok2 = false;
    }
    int ans = 0;
    ans += ok1;
    ans += ok2;
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
    while (t--)
    {
        solve();
    }

    return 0;
}