// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK :
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

int X , k;
ll memo[19][2][165];
int memoSum[19][2][165];
int pw[20];
string s;

const ll MOD = 1e9 + 7;

ll add(ll a, ll b)
{
    return ((a % MOD) + (b % MOD)) % MOD;
}

ll sub(ll a, ll b)
{
    return ((a % MOD) - (b % MOD) + MOD) % MOD;
}

ll mul(ll a, ll b)
{
    return ((a % MOD) * (b % MOD)) % MOD;
}

ll dpCount(int i ,int sm , int sum){
    if(i == s.size()) return sum == X;
    ll &ret = memo[i][sm][sum];
    if(~ret) return ret;
    ret = 0;
    int limit = sm ? 9 : s[i];
    for (int d = 0; d <= limit; ++d) {
        ret += dpCount(
                i + 1,
                sm or d < s[i],
                (sum + d)
                );
    }
    return ret;
}

int dpSum(int i ,int sm , int sum){
    if(i == s.size()) return 0;
    int &ret = memoSum[i][sm][sum];
    if(~ret) return ret;
    ret = 0;
    int limit = sm ? 9 : s[i];
    for (int d = 0; d <= limit; ++d) {
        ret = add(ret ,
                  dpSum(
                i + 1,
                sm or d < s[i],
                (sum + d)
        ));
        int cnt = dpCount(
                i + 1,
                sm or d < s[i],
                (sum + d)
                );
        int val = d * pw[(s.size() - i - 1)];
        ret = add(ret , val * cnt);
    }
    return ret;
}
ll solve(ll mid){
    s = to_string(mid);
    mem(memo , -1);
    for(char&x :s) x -= '0';
    return dpCount(0 , 0 , 0);
}

int solveSum(ll ans){
    s = to_string(ans);
    for(char&x : s) x -= '0';
    mem(memoSum , -1);
    mem(memo , -1);
    return dpSum(0 , 0 , 0);
}

void TC() {
    cin >> X >> k;
    ll lo = 0 , hi = 1e18 , ans = -1;
    while(lo <= hi){
        ll mid = (lo + hi) / 2;
        if(solve(mid) >= k){
            ans = mid;
            hi = mid - 1;
        }else{
            lo = mid + 1;
        }
    }
    cout << solveSum(ans) << nl;
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
    pw[0] = 1;
    for (int i = 1; i < 20; ++i) {
        pw[i] = mul(pw[i - 1] , 10);
    }
// ————————————————————————————————————————————
    ll tc = 1;
     cin >> tc;
    while (tc--)
    {
        TC();
    }

    return 0;
}