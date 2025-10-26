// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/contest/2146/problem/B
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
#define YN(x) ((x) ? yes : no);
#define ENG_GAMAL ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;
// ————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
const int N = 2e5 + 5, M = 1e3, LOG = 20, inf = 0x3f3f3f3f;
ll infLL = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n , m;
    cin >> n >> m;
    vector<vector<int>>a(n);
    vector<int>freq(m + 1);
    for (int i = 0; i < n; ++i) {
        int l;
        cin >> l;
        a[i] = vector<int>(l);
        for (int j = 0; j < l; ++j) {
            cin >> a[i][j];
            freq[a[i][j]]++;
        }
    }
    for(int i = 1 ; i <= m ; i++){
        if(not freq[i])
            return void(no);
    }
    int cnt = 0;
    for(int i = 0 ; i < n ; i++){
        bool okey = true;
        for (int j = 0; j < a[i].size(); ++j) {
            if(freq[a[i][j]] <= 1){
                okey = false;
                break;
            }
        }
        cnt += okey;
    }
    YN(cnt >= 2)
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