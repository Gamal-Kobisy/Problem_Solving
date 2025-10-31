// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/contest/2167/problem/E
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
    int n , k , x;
    cin >> n >> k >> x;
    vector<int>a(n) , reversed(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        reversed[i] = -a[i];
    }
    sort(all(a));
    vector<int>ans;
    int lo = 0 , hi = infLL;
    while(lo <= hi){
        int mid = (hi + lo) >> 1;
        vector<int>pos;
        int first = 0;
        while(abs(first - a.front()) >= mid and pos.size() < k )
            pos.emplace_back(first) , first++;
        int last = x;
        while(abs(last - a.back()) >= mid and pos.size() < k)
            pos.emplace_back(last) , last--;
        for (int i = 0 ; i < n - 1 and pos.size() < k; ++i) {
            for (int j = a[i] + mid ; j <= a[i + 1] - mid and pos.size() < k; ++j) {
                pos.emplace_back(j);
            }
        }
        if(pos.size() >= k){
            ans = pos;
            lo = mid + 1;
        }else{
            hi = mid - 1;
        }
    }
    for (int i = 0; i < min((int)ans.size() , k); ++i) {
        cout << ans[i] << sp;
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