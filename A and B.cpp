// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/contest/2149/problem/D
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
    string s;
    cin >> n >> s;
    vector<int>a , b;
    for(int i = 0 ; i < n ; i++){
        if(s[i] == 'a')
            a.emplace_back(i);
        else
            b.emplace_back(i);
    }
    ll ans1 = 0 , mid1 = a.size() / 2;
    for(int i = 0 ; i < a.size() ; i++){
        ans1 += abs(a[mid1] - a[i]) - abs(mid1 - i);
    }
    ll ans2 = 0 , mid2 = b.size() / 2;
    for(int i = 0 ; i < b.size() ; i++){
        ans2 += abs(b[mid2] - b[i]) - abs(mid2 - i);
    }
    cout << min(ans1 , ans2) << nl;
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