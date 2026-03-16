// "ولا تقولن لشيء إني فاعل ذلك غدا"
// "إلا أن يشاء الله واذكر ربك إذا نسيت وقل عسى أن يهديني ربي لأقرب من هذا رشدا"

// LINK : https://codeforces.com/problemset/problem/628/D
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
int m , digit;
string a , b;
int memo[2001][2][2][2005];

int solve(int i , bool sm , bool lr , int sum){
    if(i == b.size())
        return (sum == 0);
    int &ret = memo[i][sm][lr][sum];
    if(~ret) return ret;
    ret = 0;
    int lower = lr ? 0 : a[i];
    int upper = sm ? 9 : b[i];
    for(int d = lower ; d <= upper ; d++){
        if((i + 1) % 2 == 1){
            if(d == digit) continue;
        }else{
            if(d != digit) continue;
        }
        ret = add(ret ,
                  solve(i + 1,
                        sm or d < b[i],
                        lr or d > a[i],
                        (sum * 10 + d) % m));
    }
    return ret;
}

void TC() {
    cin >> m >> digit >> a >> b;
    while(a.size() < b.size()) a = '0' + a;
    for(char &x : a) x -= '0';
    for(char &x : b) x -= '0';
    mem(memo , -1);
    cout << solve(0 , 0 , 0 , 0);
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
//     cin >> tc;
    while (tc--)
    {
        TC();
    }

    return 0;
}