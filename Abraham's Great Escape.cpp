// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/contest/2155/problem/B
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
    int n , k;
    cin >> n >> k;
    if(pow(n , 2) == k){
        yes;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << 'U';
            }
            cout << nl;
        }
        return;
    }
    if(((int)pow(n , 2) - k) == 1)
        return void(no);
    yes;
    for(int i = 0 ; i < n  - 1; i++){
        for(int j = 0 ; j < n; j++){
            if(k){
                cout << 'U';
                k--;
            }
            else{
                cout << 'D';
            }
        }
        cout << nl;
    }
    for(int i = 0 ; i < n - 1 ; i++){
        if(k){
            cout << 'U';
            k--;
        }
        else{
        cout << 'R';

        }
    }
    cout << 'L';
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
    while (t--)
    {
        solve();
    }

    return 0;
}