// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/problemset/problem/2185/G
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define PI acos(-1)
#define Ones(n) __builtin_popcountll(n)
#define MSB(n) (63 - __builtin_clzll(n))
#define LSB(n) (__builtin_ctzll(n))
#define mem(arrr, xx) memset(arrr,xx,sizeof arrr)
#define fr first
#define sc second
#define pb push_back
#define all(a) a.begin(),a.end()
#define allr(a) a.rbegin(),a.rend()
#define no cout<<"NO\n"
#define yes cout<<"YES\n"
#define imp cout<<"IMPOSSIBLE\n"
#define nl '\n'
#define sp ' '
#define ENG_GAMAL ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;
// ————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
const int N = 2e5 + 5, M = 1e3, LOG = 20, inf = 0x3f3f3f3f;
ll infLL = 0x3f3f3f3f3f3f3f3f;

void TC() {
    int n;
    cin >> n;
    vector<vector<int>>a(n);
    vector<pii>mexs(n);
    ll sum = 0;
    ll sub = 0;
    for (int i = 0; i < n; ++i) {
        int m;
        cin >> m;
        a[i].assign(m , 0);
        map<int , int>freq;
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
            freq[a[i][j]]++;
        }
        int mex1 = 0 , mex2;
        while(freq[mex1]) {
            mex1++;
        }
        for (int k = 0; k < mex1; ++k) {
            if (freq[k] == 1) sub += 1ll * (mex1 - k) * (n - 1);
        }
        mex2 = mex1 + 1;
        while(freq[mex2]) mex2++;
        mexs[i] = {mex1 , mex2};
        sum += mex1;
    }
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += a[i].size() * (n - 1) * sum;
    }
//    cout << ans << nl;
    ans -= sub;
//    cout << ans << nl;
    sort(all(mexs));
    vector<pii>pre(n + 1);
    for (int i = 1; i <= n; ++i) {
        pre[i].fr = pre[i - 1].fr + mexs[i - 1].fr;
        pre[i].sc = pre[i - 1].sc + mexs[i - 1].sc;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < a[i].size(); ++j) {
            int cur = a[i][j];
            auto it1 = lower_bound(all(mexs) , make_pair(cur , -1));
            auto it2 = upper_bound(all(mexs) , make_pair(cur , inf));
            if(it1 == mexs.end()) continue;
            int l = it1 - mexs.begin();
            int r = it2 - mexs.begin();
            ans -= pre[r].fr - pre[l].fr;
            ans += pre[r].sc - pre[l].sc;
        }
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
    ll tc = 1;
     cin >> tc;
    while (tc--)
    {
        TC();
    }

    return 0;
}