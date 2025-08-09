// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK :
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
    ll n , m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        ll a , b;
        cin >> a >> b;
    }
    if(m < n - 1)
        return void(cout << -1 << nl);
    ll ans = 0;
    for (int i = 2; i <= n; ++i) {
        ans += i + 1;
    }
    vector<int>last(n + 1);
    priority_queue<pair<ll,int> , vector<pair<ll,int>> , greater<>>pq;
    for (int i = 2; i < n; ++i) {
        last[i] = i + 1;
        pq.push({i + last[i] , i});
    }
    m -= n - 1;
    while(m--)
    {
        auto [sum , node] = pq.top();
        pq.pop();
        ans += sum;
        last[node]++;
        if(last[node] <= n)
            pq.push({node + last[node] , node});
    }
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