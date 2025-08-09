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
    ll n;
    cin >> n;
    vector<ll>a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<ll>pre(n) , suf(n);
    pre[0] = a[0];
    for (int i = 1; i < n; ++i) {
        pre[i] = max(a[i] , pre[i - 1]);
    }
    suf[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        suf[i] = max(a[i] , suf[i + 1]);
    }
    vector<ll>nxt(n) , prv(n);
    stack<ll>st;
    st.push(-1);
    for (int i = 0; i < n; ++i) {
        while(~st.top() && a[st.top()] < a[i])
            st.pop();
        prv[i] = st.top();
        st.push(i);
    }
    while(!st.empty())
        st.pop();
    st.push(n);
    for (int i = n - 1; i >= 0; --i) {
        while(st.top() != n && a[st.top()] < a[i])
            st.pop();
        nxt[i] = st.top();
        st.push(i);
    }

    ll ans = infLL;

    for (int i = 1; i + 1 < n; ++i) {
        ll prev = pre[max(0ll , prv[i])];
        ll next = suf[min(n - 1 , nxt[i])];
        ans = min(ans , a[i] + prev + next);
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
//     cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}