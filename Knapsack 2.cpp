// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://atcoder.jp/contests/dp/tasks/dp_e
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

int n , w , W[101] , V[101] , memo[101][100001];

int solve(int idx , int sum) {
    if(sum <= 0) return 0;
    if(idx == n) return infLL;
    int &ret = memo[idx][sum];
    if(~ret) return ret;
    ret = solve(idx + 1 , sum);
    ret = min(ret ,
              solve(idx + 1 , sum - V[idx]) + W[idx]
              );
    return ret;
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
    cin >> n >> w;
    for (int i = 0; i < n; ++i) {
        cin >> W[i] >> V[i];
    }
    memset(memo , -1 , sizeof memo);

    for(int ans = 1e5 ; ans >= 0 ; ans--){
        if(solve(0 , ans) <= w){
            cout << ans << nl;
            return 0;
        }
    }

    return 0;
}