// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK :
#include <bits/stdc++.h>
#define ll long long
#define nl '\n'
#define all(a) a.begin(),a.end()
#define allr(a) a.rbegin(),a.rend()
#define no cout<<"NO\n"
#define yes cout<<"YES\n"
#define ENG_GAMAL ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;
// ————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
const int N = 3e3 + 5, M = 1e3, LOG = 20, inf = 0x3f3f3f3f;
ll infLL = 0x3f3f3f3f3f3f3f3f;
string s , t;
int n , m;
int dp[N][N];
int calc(int i , int j)
{
    if(i == n || j == m)
        return 0;

    int &ret = dp[i][j];

    if(~ret)
        return ret;
    if(s[i] == t[j])
        ret = calc(i + 1 , j + 1) + 1;
    else
        ret = max(calc(i + 1 , j) , calc(i , j + 1));

    return ret;
}

void solve() {
    memset(dp , -1 , sizeof dp);
    n = s.size();
    m = t.size();
    cout << calc(0 , 0) << nl;
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
    while (cin >> s >> t)
    {
        solve();
    }

    return 0;
}