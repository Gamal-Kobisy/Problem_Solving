// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK :
#include <iostream>
#include <cstring>
#define ll long long
//#define int ll
#define nl '\n'
#define sp ' '
#define all(a) a.begin(),a.end()
#define allr(a) a.rbegin(),a.rend()
#define no cout<<"NO\n"
#define yes cout<<"YES\n"
#define imp cout<<"IMPOSSIBLE\n"
#define ENG_GAMAL ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
// ————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
const int N = 2e5 + 5, M = 1e3, LOG = 20, inf = 0x3f3f3f3f;
ll infLL = 0x3f3f3f3f3f3f3f3f;
int n , a[101] , p[101] , memo[101][100001];
int solve(int idx , int sum) {
    if(idx >= n) return ((sum + 10) * p[n - 1]);
    int &ret = memo[idx][sum];
    if(~ret) return ret;
    ret = min(solve(idx + 1 , sum) + (a[idx] + 10) * p[idx] ,
              solve(idx + 1 , sum + a[idx]));
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

int main() {
    file();
    ENG_GAMAL
// test-independent code ——————————————————————
// ————————————————————————————————————————————
    ll t = 1;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> a[i] >> p[i];
        }
        memset(memo , -1 , sizeof memo);
        cout << solve(0 , 0) << nl;
    }

    return 0;
}