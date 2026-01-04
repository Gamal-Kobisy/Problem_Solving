// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/problemset/problem/1628/A
//#pragma GCC optimize("O3")
//#pragma GCC optimize ("unroll-loops")
//#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
//#pragma GCC target("avx2")
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
#define fi first
#define se second
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
    vector<int> a(n);
    vector<vector<int>> pos(n + 2);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        pos[a[i]].pb(i);
    }

    vector<int> suff(n);
    vector<bool> seen(n + 2, false);
    int mex = 0;
    for (int i = n - 1; i >= 0; --i) {
        seen[a[i]] = true;
        while (seen[mex]) mex++;
        suff[i] = mex;
    }

    vector<int> ans;
    int curr = 0;

    while (curr < n) {
        int target = suff[curr];
        ans.pb(target);

        if (target == 0) {
            curr++;
            continue;
        }
        int max_idx = curr;
        for (int v = 0; v < target; ++v) {
            auto it = lower_bound(all(pos[v]), curr);
            max_idx = max(max_idx, *it);
        }
        curr = max_idx + 1;
    }

    cout << ans.size() << nl;
    for (int i = 0; i < ans.size(); ++i) {
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