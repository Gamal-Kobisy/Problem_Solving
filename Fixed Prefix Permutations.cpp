// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/problemset/problem/1792/D
#pragma GCC optimize("O3")
#pragma GCC optimize ("unroll-loops")
#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
#pragma GCC target("avx2")
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
    int n , m;
    cin >> n >> m;
    vector<vector<int>>p(n , vector<int>(m));
    vector<vector<int>>pos(n , vector<int>(m)) , sorted;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> p[i][j];
            pos[i][p[i][j] - 1] = j + 1;
        }
    }
    sorted = pos;
    sort(all(sorted));
    for (int i = 0; i < n; ++i) {
        int ans = 0;
        vector<int>target(m , -inf);
        for (int j = 0; j < m; ++j) {
            target[j] = p[i][j];
            auto it = lower_bound(all(sorted) , target);
            int idx = it - sorted.begin();
            if(it == sorted.end() or target[j] != sorted[idx][j]){
                break;
            }else{
                bool valid = true;
                for (int k = 0; k < j; ++k) {
                    valid &= target[k] == sorted[idx][k];
                }
                ans += valid;
            }
        }
        cout << ans << sp;
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